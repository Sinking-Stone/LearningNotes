#include "IOTask_interaction_DDS.hpp"
#include "serialization_config.hpp"
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <iostream>

namespace Hirain_Deserialization {

ObjectEncoderDecoder::ObjectEncoderDecoder() {
  typeCastingMap = serialization_config::getTypeCastingMap();
  historyData = nullptr;
  historyData = new char[102400];
  memset(historyData, 0, 102400);
  if (historyData == nullptr) {
    perror("malloc memory failed");
  }
}

ObjectEncoderDecoder::~ObjectEncoderDecoder() {
  if (historyData != nullptr) {
    delete[] historyData;
  }
}

std::string ObjectEncoderDecoder::getECUName(std::string guid) {
  if (guidDecodeData.size() == 0) {
    return "";
  }
  return guidDecodeData[guid][2];
}
/**
 * 读取JSON文件并获得相关属性(wfl)
*/
DDSConfigTemplate &ObjectEncoderDecoder::getDDSConfig(char *filename) {
  static bool flag = true;

  if (flag) {
    flag = false;
    // 采用property_tree的目的是为了方便解析jsno文件(wfl)
    boost::property_tree::ptree pt;

    try {
      boost::property_tree::read_json(filename, pt);
    } catch (const boost::property_tree::json_parser_error &e) {
      std::cerr << "JSON parse error : " << e.what() << std::endl;
      return mapData;
    } catch (const std::exception &e) {
      std::cerr << "error occurs : " << e.what() << std::endl;
      return mapData;
    }
    // 获取json文件中每一个元素的值(wfl)
    for (const auto &ecu : pt.get_child("ecu")) {
      std::string ECUName = ecu.second.get<std::string>("ECUName");
      const boost::property_tree::ptree &payloads =
          ecu.second.get_child("payloads");

      for (const auto &payload : payloads) {
        std::string TopicName = payload.second.get<std::string>("TopicName");
        std::string MsgName = payload.second.get<std::string>("MsgName");
        std::string Guid = payload.second.get<std::string>("Guid");

        const boost::property_tree::ptree &typeList =
            payload.second.get_child("Type");
        std::vector<std::string> typeVect;
        for (const auto &type : typeList) {
          const std::string typeValue = type.second.data();
          typeVect.push_back(typeValue);
        }

        const boost::property_tree::ptree &unionList =
            payload.second.get_child("UNION");
        std::vector<int> unionVect;
        for (const auto &value : unionList) {
          const std::string typeValue = value.second.data();
          unionVect.push_back(std::stoi(typeValue));
        }

        hashCodeMap[Guid] = unionVect;

        // guid typeList
        mapData[Guid] = typeVect;
        guidDecodeData[Guid] =
            std::vector<std::string>({TopicName, MsgName, ECUName});
        encodeGuidData[TopicName.append(MsgName)] = Guid;
      }
    }
  }

  return mapData;
}

// to implement struct alignment,set '/0' padding
void ObjectEncoderDecoder::setPadding(std::shared_ptr<std::string> payload,
                                      int alignSize) {
  if (alignSize == 0) {
    perror("ObjectEncoderDecoder::setPadding alignSize == 0");
  }

  int paddingSize = (alignSize - payload->size() % alignSize) & (alignSize - 1);

  while (paddingSize != 0) {
    payload->push_back(0);
    paddingSize -= 1;
  }
}

// to calc typesize from typeString
uint16_t
ObjectEncoderDecoder::castTypeStringToTypeSize(std::string &typeString) {
  // mapping from  FLOAT32_TYPE   to 4 bytes
  uint16_t ret = 0;
  for (int i = 0; i < typeString.size(); ++i) {
    if (48 <= typeString[i] && typeString[i] <= 57) {
      ret *= 10;
      ret += typeString[i] - 48;
    }
  }
  return ret / 8;
};

bool ObjectEncoderDecoder::onChanged(char *data, uint32_t b_index,
                                     uint32_t e_index) {
  int ret = memcmp(historyData + b_index + 42, data + b_index + 42,
                   e_index - b_index - 42);
  if (ret == 0) {
    memcpy(historyData + b_index, data + b_index, 42);
    return 0;
  }
  memcpy(historyData + b_index, data + b_index, e_index - b_index);
  return 1;
};

// 解析基本数据类型，并返回该数据对齐长度,typeString的输入为 0x？000？
// 测试过，没问题
uint16_t
ObjectEncoderDecoder::decodeMsgBasicType(std::shared_ptr<std::string> payload,
                                         char *data, uint32_t &dataIndex,
                                         std::string &typeString) {
  uint16_t alignSize = castTypeStringToTypeSize(typeCastingMap[typeString]);
  // 首先判断是不是指针存储
  if (typeString[2] == '0') {
    setPadding(payload, alignSize);
    // 接着判断是不是字符串
    if (typeString[typeString.size() - 1] != 'E') {
      payload->append(data + dataIndex, alignSize);
      dataIndex += alignSize;
    } else {
      uint32_t strLen = 0;
      uintptr_t ptr = mm.add_string(data + dataIndex, strLen);
      dataIndex += strLen;
      payload->append((char *)(&ptr), sizeof(ptr));
    }
  // 是指针存储
  } else {
    // 不是字符串
    if (typeString[typeString.size() - 1] != 'E') {
      uintptr_t ptr = mm.add_element(data + dataIndex, alignSize, alignSize);
      dataIndex += alignSize;
      setPadding(payload, sizeof(uintptr_t));
      payload->append((char *)(&ptr), sizeof(uintptr_t));
      // 是字符串
    } else {
      uint32_t strLen = 0;
      uintptr_t ptr = mm.add_string(data + dataIndex, strLen);
      dataIndex += strLen;
      ptr =
          mm.add_element((char *)(&ptr), sizeof(uintptr_t), sizeof(uintptr_t));
      setPadding(payload, sizeof(uintptr_t));
      payload->append((char *)(&ptr), sizeof(uintptr_t));
    }
    alignSize = sizeof(uintptr_t);
  }
  return alignSize; 
}

// 测试过，没问题
uint16_t ObjectEncoderDecoder::decodeMsgFixedArrayType(
    std::shared_ptr<std::string> payload, char *data, uint32_t &dataIndex,
    std::string &typeString, std::string &arrLength) {
  uint16_t alignSize = castTypeStringToTypeSize(typeCastingMap[typeString]);
  int arrLen = std::stoi(arrLength, nullptr, 16);
  // 首先判断是不是指针存储
  if (typeString[2] == '0') {
    // 接着判断是不是字符串
    setPadding(payload, alignSize);
    if (typeString[typeString.size() - 1] != 'E') {
      payload->append(data + dataIndex, alignSize * arrLen);
      dataIndex += alignSize * arrLen;
    } else {
      for (int i = 0; i < arrLen; ++i) {
        uint32_t strLen = 0;
        uintptr_t ptr = mm.add_string(data + dataIndex, strLen);
        dataIndex += strLen;
        payload->append((char *)(&ptr), sizeof(ptr));
      }
    }
  } else {
    if (typeString[typeString.size() - 1] != 'E') {
      uintptr_t ptr =
          mm.add_element(data + dataIndex, alignSize, alignSize * arrLen);
      dataIndex += alignSize * arrLen;
      setPadding(payload, sizeof(ptr));
      payload->append((char *)(&ptr), sizeof(ptr));
    } else {
      std::shared_ptr<std::string> tempPaylod = std::make_shared<std::string>();
      std::string tempTypeString = "0x00";
      tempTypeString.append(typeString.substr(4));
      decodeMsgFixedArrayType(tempPaylod, data, dataIndex, tempTypeString,
                              arrLength);
      uintptr_t ptr = mm.add_element(tempPaylod->data(), sizeof(uintptr_t),
                                     tempPaylod->size());
      setPadding(payload, sizeof(uintptr_t));
      payload->append((char *)(&ptr), sizeof(ptr));
    }
    alignSize = sizeof(uintptr_t);
  }
  return alignSize;
}

// 测试过，没问题
uint16_t ObjectEncoderDecoder::decodeMsgVariableArrayType(
    std::shared_ptr<std::string> payload, char *data, uint32_t &dataIndex,
    std::string &typeString, std::string &arrMaxLength) {
  if (typeString[2] == '0') {
    uint32_t maximumLength = std::stoi(arrMaxLength, nullptr, 16);
    uint32_t validLength = *((uint32_t *)(data + dataIndex));
    dataIndex += 4;
    setPadding(payload, sizeof(uintptr_t));
    payload->append((char *)&maximumLength, 4);
    payload->append((char *)&validLength, 4);
    std::shared_ptr<std::string> subpayload = std::make_shared<std::string>();
    // 将变长数组转为定长数组“0x101
    decodeMsgFixedArrayType(subpayload, data, dataIndex,
                            std::string("0x101").append(typeString.substr(5)),
                            arrMaxLength);
    payload->append(subpayload->data(), subpayload->size());

    bool flag = 0;
    payload->append((char *)&flag, 1);
    setPadding(payload, sizeof(uintptr_t));
  } else {
    std::shared_ptr<std::string> subpayload = std::make_shared<std::string>();
    std::string tempString = "0x00";
    tempString.append(typeString.substr(4));
    decodeMsgVariableArrayType(subpayload, data, dataIndex, tempString,
                               arrMaxLength);

    uintptr_t ptr = mm.add_element(subpayload->data(), sizeof(uintptr_t),
                                   subpayload->size());

    setPadding(payload, sizeof(uintptr_t));
    payload->append((char *)&ptr, sizeof(uintptr_t));
  }

  return sizeof(uintptr_t);
}

// deserialize from iotask to dds
uint16_t
ObjectEncoderDecoder::decodeMsgPayload(std::shared_ptr<std::string> payload,
                                       char *data, uint32_t &dataIndex,
                                       DataConfig dataConfig) {
  // base condition
  if (dataConfig.size() == 0) {
    return 1;
  }
  uint16_t alignmentLen = 1;

  // ql add
  for (int start = 0; start < dataConfig.size();) {
    std::string sstr = dataConfig[start];
    uint16_t alignSize = 0;
    // 判断是否为基本数据类型，也包括指针指向的基本数据类型
    if (sstr.substr(3, 2) == "00") {
      alignSize =
          decodeMsgBasicType(payload, data, dataIndex, dataConfig[start]);
      alignmentLen = std::max(alignSize, alignmentLen);
      start += 1;
    } else if (sstr.substr(3, 2) == "01") {
      alignSize = decodeMsgFixedArrayType(
          payload, data, dataIndex, dataConfig[start], dataConfig[start + 1]);
      alignmentLen = std::max(alignSize, alignmentLen);
      start += 2;
    } else if (sstr.substr(3, 2) == "02") {
      alignSize = decodeMsgVariableArrayType(
          payload, data, dataIndex, dataConfig[start], dataConfig[start + 1]);
      alignmentLen = std::max(alignSize, alignmentLen);
      start += 2;
    } else if (sstr.substr(3, 2) == "10") {
      int struct_end = 1;
      int end = start;
      std::string estr = sstr.substr(0, sstr.size() - 2).append("FF");
      while (struct_end != 0) {
        end++;
        if (dataConfig[start] == dataConfig[end]) {
          struct_end += 1;
        } else if (dataConfig[end] == estr) {
          struct_end -= 1;
        }
      };

      if (sstr[2] != '1') {
        std::shared_ptr<std::string> subpayload =
            std::make_shared<std::string>();
        alignSize = decodeMsgPayload(subpayload, data, dataIndex,
                                     DataConfig(dataConfig.begin() + start + 1,
                                                dataConfig.begin() + end));

        setPadding(payload, alignSize);
        payload->append(subpayload->data(), subpayload->size());

        alignmentLen = std::max(alignSize, alignmentLen);
      } else {
        DataConfig tempConfig = DataConfig(dataConfig.begin() + start,
                                           dataConfig.begin() + end + 1);
        tempConfig[0] = "0x01000";
        tempConfig[tempConfig.size() - 1] = "0x010FF";
        std::shared_ptr<std::string> subpayload =
            std::make_shared<std::string>();

        alignSize = decodeMsgPayload(subpayload, data, dataIndex, tempConfig);

        uintptr_t ptr =
            mm.add_element(subpayload->data(), alignSize, subpayload->size());
        setPadding(payload, sizeof(uintptr_t));

        payload->append((char *)&ptr, sizeof(uintptr_t));

        alignmentLen = std::max(alignSize, (uint16_t)sizeof(uintptr_t));
      }
      start = end + 1;
    } else if (sstr.substr(3, 2) == "11") {
      int struct_end = 1;
      int end = start + 1;
      int struct_size = std::stoi(dataConfig[start + 1], nullptr, 16);
      std::string estr = sstr.substr(0, sstr.size() - 2).append("FF");
      while (struct_end != 0) {
        end++;
        if (dataConfig[start] == dataConfig[end]) {
          struct_end += 1;
        } else if (dataConfig[end] == estr) {
          struct_end -= 1;
        }
      };

      if (sstr[2] != '1') {
        for (int struct_size_index = 0; struct_size_index < struct_size;
             ++struct_size_index) {
          std::shared_ptr<std::string> subpayload =
              std::make_shared<std::string>();
          alignSize =
              decodeMsgPayload(subpayload, data, dataIndex,
                               DataConfig(dataConfig.begin() + start + 2,
                                          dataConfig.begin() + end));
          setPadding(payload, alignSize);
          payload->append(subpayload->data(), subpayload->size());
        }
        alignmentLen = std::max(alignmentLen, alignSize);
      } else {
        DataConfig tempConfig = DataConfig(dataConfig.begin() + start,
                                           dataConfig.begin() + end + 1);
        tempConfig[0] = "0x01100";
        tempConfig[tempConfig.size() - 1] = "0x011FF";
        std::shared_ptr<std::string> subpayload =
            std::make_shared<std::string>();
        uint32_t temp_alignSize =
            decodeMsgPayload(subpayload, data, dataIndex, tempConfig);
        uintptr_t ptr = mm.add_element(subpayload->data(), temp_alignSize,
                                       subpayload->size());
        setPadding(payload, sizeof(uintptr_t));
        payload->append((char *)&ptr, sizeof(uintptr_t));
        alignmentLen = std::max(alignmentLen, (uint16_t)sizeof(uintptr_t));
      }
      start = end + 1;
    } else if (sstr.substr(3, 2) == "12") {
      int struct_end = 1;
      int end = start + 1;
      int struct_size = std::stoi(dataConfig[start + 1], nullptr, 16);
      std::string estr = sstr.substr(0, sstr.size() - 2).append("FF");
      while (struct_end != 0) {
        end++;
        if (dataConfig[start] == dataConfig[end]) {
          struct_end += 1;
        } else if (dataConfig[end] == estr) {
          struct_end -= 1;
        }
      };
      if (sstr[2] == '0') {
        int valid_length = *((uint32_t *)(data + dataIndex));
        dataIndex += 4;
        std::shared_ptr<std::string> subpayload =
            std::make_shared<std::string>();
        setPadding(payload, sizeof(uintptr_t));
        payload->append((char *)&struct_size, 4);
        payload->append((char *)&valid_length, 4);
        DataConfig tempConfig = DataConfig(dataConfig.begin() + start,
                                           dataConfig.begin() + end + 1);
        tempConfig[0] = "0x11100";
        tempConfig[tempConfig.size() - 1] = "0x111FF";
        decodeMsgPayload(subpayload, data, dataIndex, tempConfig);
        payload->append(subpayload->data(), subpayload->size());
        bool flag = 0;
        payload->append((char *)&flag, 1);
        setPadding(payload, sizeof(uintptr_t));
        alignSize = sizeof(uintptr_t);
      } else {
        DataConfig tempConfig = DataConfig(dataConfig.begin() + start,
                                           dataConfig.begin() + end + 1);
        tempConfig[0] = "0x01200";
        tempConfig[tempConfig.size() - 1] = "0x012FF";
        std::shared_ptr<std::string> subpayload =
            std::make_shared<std::string>();
        uint32_t subalignSize =
            decodeMsgPayload(subpayload, data, dataIndex, tempConfig);
        uintptr_t ptr = mm.add_element(subpayload->data(), subalignSize,
                                       subpayload->size());
        setPadding(payload, sizeof(uintptr_t));
        payload->append((char *)&ptr, sizeof(uintptr_t));
        alignSize = sizeof(uintptr_t);
      }
      start = end + 1;

    } // union这里空着，先不写
    else if (sstr.substr(3, 2) == "20") {
      int union_end = 1;
      int end = start + 1;
      std::string estr = sstr.substr(0, sstr.size() - 2).append("FF");
      while (union_end != 0) {
        end++;
        if (dataConfig[start] == dataConfig[end]) {
          union_end += 1;
        } else if (dataConfig[end] == estr) {
          union_end -= 1;
        }
      };
      if (sstr[2] != 1) {
        // 首先需要将union字段的dataConfig全部给剥离开，然后对里面每个子类型进行解析
        std::vector<DataConfig> dataConfigList;
        for (int splitStart = start + 1; splitStart < end;) {
          DataConfig tempDataConfig;
          if (dataConfig[splitStart].substr(3, 2) == "00") {
            // 基本数据类型
            tempDataConfig.push_back(dataConfig[splitStart++]);
          } else if (dataConfig[splitStart].substr(3, 2) == "01" ||
                     dataConfig[splitStart].substr(3, 2) == "02") {
            // 定长结构体或变长结构体
            tempDataConfig.insert(
                tempDataConfig.end(),
                {dataConfig[splitStart++], dataConfig[splitStart++]});
          } else {
            int split_struct_end = 1;
            int splitEnd = splitStart;
            std::string split_estr =
                dataConfig[splitStart]
                    .substr(0, dataConfig[splitStart].size() - 2)
                    .append("FF");
            while (split_struct_end != 0) {
              splitEnd++;
              if (dataConfig[splitStart] == dataConfig[splitEnd]) {
                split_struct_end += 1;
              } else if (dataConfig[splitEnd] == split_estr) {
                split_struct_end -= 1;
              }
            };
            tempDataConfig.insert(tempDataConfig.end(),
                                  dataConfig.begin() + splitStart,
                                  dataConfig.begin() + splitEnd + 1);
            splitStart = splitEnd + 1;
          }
          dataConfigList.push_back(tempDataConfig);
        }
        int unionHashIndex = 0;
        int unionHashKey = *((int *)(payload->data() + payload->size() - 4));
        for (; unionHashIndex < curHashCode.size(); ++unionHashIndex) {
          if (unionHashKey == curHashCode[unionHashIndex]) {
            break;
          }
        }
        if (unionHashIndex == curHashCode.size()) {
          unionHashIndex = dataConfigList.size() - 1;
        } else {
          int tempUnionHashIndex = dataConfigList.size() - 1;
          while (curHashCode[unionHashIndex] != 0) {
            tempUnionHashIndex--;
            unionHashIndex++;
          }
          unionHashIndex = tempUnionHashIndex;
        }
        uint16_t unionAlignSize = 0;
        uint32_t unionSize = 0;

        std::shared_ptr<std::string> unionPayload;
        for (int dataConfigListIndex = 0;
             dataConfigListIndex < dataConfigList.size();
             ++dataConfigListIndex) {
          std::shared_ptr<std::string> subPayload =
              std::make_shared<std::string>();
          uint16_t ret = decodeMsgPayload(subPayload, data, dataIndex,
                                          dataConfigList[dataConfigListIndex]);
          unionAlignSize = std::max(ret, unionAlignSize);
          unionSize = std::max(unionSize, (uint32_t)subPayload->size());
          if (dataConfigListIndex == unionHashIndex) {
            unionPayload = subPayload;
          }
        }
        while (unionPayload->size() != unionSize) {
          unionPayload->push_back('\0');
        }

        setPadding(unionPayload, unionAlignSize);
        setPadding(payload, unionAlignSize);
        payload->append(*unionPayload);
        alignmentLen = std::max(alignmentLen, unionAlignSize);
      } else {
        DataConfig subDataConfig = DataConfig(dataConfig.begin() + start,
                                              dataConfig.begin() + end + 1);
        subDataConfig[0][2] = '0';
        subDataConfig[subDataConfig.size() - 1][2] = '0';
        std::shared_ptr<std::string> subPayload =
            std::make_shared<std::string>();
        alignSize =
            decodeMsgPayload(subPayload, data, dataIndex, subDataConfig);
        uintptr_t ptr =
            mm.add_element(subPayload->data(), alignSize, subPayload->size());
        setPadding(payload, sizeof(uintptr_t));
        payload->append((char *)&ptr, sizeof(uintptr_t));
        alignmentLen = std::max(alignmentLen, (uint16_t)8);
      }
      start = end + 1;
    }
  }

  setPadding(payload, alignmentLen);
  return alignmentLen;
}

uint16_t
ObjectEncoderDecoder::decodeMsgHeader(std::shared_ptr<Deserialization> desMsg,
                                      char *data) {
  // iotask and DDS dfine the length of messageHead
  uint16_t messageHeadLen = 32 + 10;

  // deserialization message header
  std::string guid = std::string(data, 32);
  std::vector<std::string> &topicAndmsg = guidDecodeData[guid];

  desMsg->topicName = topicAndmsg[0];

  desMsg->messageName = topicAndmsg[1];

  // tcs control signal
  memcpy((char *)(&(desMsg->tcs_tx)), data + 32, 10);

  return messageHeadLen;
}

std::shared_ptr<std::vector<std::shared_ptr<Deserialization>>>
ObjectEncoderDecoder::decodeMsg(char *data) {
  // get DDSConfig && typeCastingSizeRelation
  mm.clear();

  DDSConfigTemplate &DDSConfig = getDDSConfig((char *)("DDS.config.json"));

  // total length of received data
  unsigned int length = *((unsigned int *)data);
  data += sizeof(unsigned int);

  // number of message
  uint16_t msgNum = *((uint16_t *)data);
  data += sizeof(uint16_t);

  // create vector of deserialization message
  std::shared_ptr<std::vector<std::shared_ptr<Deserialization>>> messageArr =
      std::make_shared<std::vector<std::shared_ptr<Deserialization>>>();

  for (unsigned int index = 0; index < length - 6;) {

    uint32_t accord_b_index = index;

    std::shared_ptr<Deserialization> msg = std::make_shared<Deserialization>();
    messageArr->push_back(msg);

    std::string guid = std::string(data + index, 32);

    curHashCode = hashCodeMap[guid];

    index += decodeMsgHeader(msg, data + index);
    std::shared_ptr<std::string> payload = std::make_shared<std::string>();

    for (DDSConfigTemplate::iterator it = DDSConfig.begin();
         it != DDSConfig.end(); ++it) {
      if (it->first == guid) {
        curHashCode = hashCodeMap[guid];
        decodeMsgPayload(payload, data, index, it->second);
        break;
      }
    }

    uint32_t accord_e_index = index;

    uint8_t onChangeFlag = onChanged(data, accord_b_index, accord_e_index);
    msg->tcs_tx.IsChanged = onChangeFlag;
    //
    msg->dataLen = payload->size();
    msg->data = payload;
  }

  return messageArr;
}

// get the size of the cur  data type align size，for encoding
uint16_t ObjectEncoderDecoder::getCurDataAlignSize(DataConfig &dataConfig,
                                                   int begin, int end) {
  // basic type
  uint16_t ret = 0;
  while (begin < end) {
    if (dataConfig[begin][2] == '1') {
      ret = std::max(ret, (uint16_t)sizeof(uintptr_t));
      return ret;
    } else if (dataConfig[begin].substr(0, 5) == "0x000" ||
               dataConfig[begin].substr(0, 5) == "0x001") {
      // 基本，定长数组
      ret = std::max(ret, (uint16_t)castTypeStringToTypeSize(
                              typeCastingMap[dataConfig[begin]]));
      begin += 1;
    } else if (dataConfig[begin].substr(0, 5) == "0x002" ||
               dataConfig[begin].substr(0, 5) == "0x012") {
      // 变长数组，变长结构体
      if (dataConfig[begin] == "0x012FF") {
        begin += 1;
        continue;
      }
      ret = std::max(ret, (uint16_t)sizeof(uintptr_t));
      begin += 2;
    } else if (dataConfig[begin].substr(0, 5) == "0x010" ||
               dataConfig[begin].substr(0, 5) == "0x011") {
      // 基本结构体，定长结构体
      begin += 1;
      if (dataConfig[begin] == "0x01100") {
        begin += 1;
      }
    } else {
      // union
      begin += 1;
    }
  }
  return ret;
}

// to serialize payload，transform dds into iotask
uint16_t
ObjectEncoderDecoder::encodeMsgBasicType(std::shared_ptr<std::string> payload,
                                         char *data, uint32_t &dataIndex,
                                         std::string &typeString) {
  uint16_t alignSize = 1;
  if (typeString[2] == '1') {
    alignSize = sizeof(uintptr_t);
    dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

    uintptr_t ptr = *((uintptr_t *)(data + dataIndex));
    dataIndex += sizeof(uintptr_t);

    if (typeString[typeString.size() - 1] == 'E') {
      ptr = *((uintptr_t *)reinterpret_cast<char *>(ptr));
      char *c = reinterpret_cast<char *>(ptr);
      while (*c != 0) {
        payload->push_back(*c);
        c++;
      }
      payload->push_back('\0');
    } else {
      char *c = reinterpret_cast<char *>(ptr);
      payload->append(c, castTypeStringToTypeSize(typeCastingMap[typeString]));
    }
  } else {
    if (typeString[typeString.size() - 1] == 'E') {
      alignSize = sizeof(uintptr_t);
      dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

      uintptr_t ptr = *((uintptr_t *)(data + dataIndex));
      char *c = reinterpret_cast<char *>(ptr);
      while (*c != 0) {
        payload->push_back(*c);
        c++;
      }
      payload->push_back('\0');
      dataIndex += sizeof(uintptr_t);
    } else {
      alignSize = castTypeStringToTypeSize(typeCastingMap[typeString]);
      dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

      payload->append(data + dataIndex, alignSize);
      dataIndex += alignSize;
    }
  }
  return alignSize;
}

uint16_t ObjectEncoderDecoder::encodeMsgFixedArrayType(
    std::shared_ptr<std::string> payload, char *data, uint32_t &dataIndex,
    std::string &typeString, std::string &arrLength) {
  uint16_t alignSize = 1;
  int arrLen = std::stoi(arrLength, nullptr, 16);
  if (typeString[2] == '0') {
    alignSize = castTypeStringToTypeSize(typeCastingMap[typeString]);
    dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

    std::string tempString = typeString.substr(0, 4);
    tempString.push_back('0');
    tempString.append(typeString.substr(5));
    for (int i = 0; i < arrLen; ++i) {
      encodeMsgBasicType(payload, data, dataIndex, tempString);
    }
    return alignSize;
  } else {
    alignSize = sizeof(uintptr_t);
    dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

    std::string tempString = "0x000";
    tempString.append(typeString.substr(5));

    uintptr_t ptr = *(reinterpret_cast<uintptr_t *>(data + dataIndex));
    dataIndex += sizeof(uintptr_t);

    char *new_data = reinterpret_cast<char *>(ptr);
    uint32_t new_dataIndex = 0;
    for (int i = 0; i < arrLen; ++i) {
      encodeMsgBasicType(payload, new_data, new_dataIndex, tempString);
    }
    return alignSize;
  }
}

uint16_t ObjectEncoderDecoder::encodeMsgVariableArrayType(
    std::shared_ptr<std::string> payload, char *data, uint32_t &dataIndex,
    std::string &typeString, std::string &arrMaxLength) {
  uint16_t alignSize = 1;

  alignSize = sizeof(uintptr_t);
  dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

  if (typeString[2] == '0') {
    // 因为前四个是最大长度，不需要取出
    dataIndex += 4;
    payload->append(data + dataIndex, 4);
    dataIndex += 4;

    std::string tempString = typeString.substr(0, 4);
    tempString.push_back('1');
    tempString.append(typeString.substr(5));

    uintptr_t ptr = *(reinterpret_cast<uintptr_t *>(data + dataIndex));
    uint32_t new_dataIndex = 0;
    encodeMsgFixedArrayType(payload, reinterpret_cast<char *>(ptr),
                            new_dataIndex, tempString, arrMaxLength);
    dataIndex += alignSize;
    // 跳过flag
    dataIndex += alignSize;
  } else {
    uintptr_t ptr = *(reinterpret_cast<uintptr_t *>(data + dataIndex));
    dataIndex += sizeof(uintptr_t);
    char *new_data = reinterpret_cast<char *>(ptr);
    std::string tempString = typeString.substr(0, 2);
    tempString.push_back('0');
    tempString.append(typeString.substr(3));
    uint32_t new_dataIndex = 0;
    encodeMsgVariableArrayType(payload, new_data, new_dataIndex, tempString,
                               arrMaxLength);
  }
  return alignSize;
}

uint16_t
ObjectEncoderDecoder::encodeMsgPayload(std::shared_ptr<std::string> payload,
                                       char *data, uint32_t &dataIndex,
                                       DataConfig dataConfig) {
  if (dataConfig.size() == 0) {
    return 1;
  }

  uint16_t alignmentLen = 1;

  // ql add
  for (int begin = 0; begin < dataConfig.size();) {
    if (dataConfig[begin].substr(3, 2) == "00") {
      uint16_t alignSize =
          encodeMsgBasicType(payload, data, dataIndex, dataConfig[begin]);
      alignmentLen = std::max(alignmentLen, alignSize);
      begin += 1;
    } else if (dataConfig[begin].substr(3, 2) == "01") {
      uint16_t alignSize = encodeMsgFixedArrayType(
          payload, data, dataIndex, dataConfig[begin], dataConfig[begin + 1]);
      alignmentLen = std::max(alignmentLen, alignSize);
      begin += 2;
    } else if (dataConfig[begin].substr(3, 2) == "02") {
      uint16_t alignSize = encodeMsgVariableArrayType(
          payload, data, dataIndex, dataConfig[begin], dataConfig[begin + 1]);
      alignmentLen = std::max(alignmentLen, alignSize);
      begin += 2;
    } else if (dataConfig[begin].substr(3, 2) == "10") {
      uint16_t alignSize = 1;
      int struct_end = 1;
      int end = begin;
      std::string estr = dataConfig[begin]
                             .substr(0, dataConfig[begin].size() - 2)
                             .append("FF");
      while (struct_end != 0) {
        end++;
        if (dataConfig[begin] == dataConfig[end]) {
          struct_end += 1;
        } else if (dataConfig[end] == estr) {
          struct_end -= 1;
        }
      };

      if (dataConfig[begin][2] != '1') {
        alignSize = getCurDataAlignSize(dataConfig, begin + 1, end);
        dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

        encodeMsgPayload(payload, data, dataIndex,
                         DataConfig(dataConfig.begin() + begin + 1,
                                    dataConfig.begin() + end));
      } else {
        alignSize = sizeof(uintptr_t);
        dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

        uintptr_t ptr = *(reinterpret_cast<uintptr_t *>(data + dataIndex));
        dataIndex += sizeof(uintptr_t);

        char *new_data = reinterpret_cast<char *>(ptr);
        uint32_t new_dataIndex = 0;
        encodeMsgPayload(payload, new_data, new_dataIndex,
                         DataConfig(dataConfig.begin() + begin + 1,
                                    dataConfig.begin() + end));
      }
      begin = end + 1;
      alignmentLen = std::max(alignmentLen, alignSize);
    } else if (dataConfig[begin].substr(3, 2) == "11") {
      uint16_t alignSize = 1;
      uint32_t strctLen = std::stoi(dataConfig[begin + 1], nullptr, 16);
      int struct_end = 1;
      int end = begin + 1;
      std::string estr = dataConfig[begin]
                             .substr(0, dataConfig[begin].size() - 2)
                             .append("FF");
      while (struct_end != 0) {
        end++;
        if (dataConfig[begin] == dataConfig[end]) {
          struct_end += 1;
        } else if (dataConfig[end] == estr) {
          struct_end -= 1;
        }
      };

      if (dataConfig[begin][2] != '1') {
        alignSize = getCurDataAlignSize(dataConfig, begin, end);
        dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

        for (int i = 0; i < strctLen; ++i)
          encodeMsgPayload(payload, data, dataIndex,
                           DataConfig(dataConfig.begin() + begin + 2,
                                      dataConfig.begin() + end));
      } else {
        alignSize = sizeof(uintptr_t);
        dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

        uintptr_t ptr = *(reinterpret_cast<uintptr_t *>(data + dataIndex));
        dataIndex += sizeof(uintptr_t);

        char *new_data = reinterpret_cast<char *>(ptr);
        uint32_t new_dataIndex = 0;
        for (int i = 0; i < strctLen; ++i)
          encodeMsgPayload(payload, new_data, new_dataIndex,
                           DataConfig(dataConfig.begin() + begin + 2,
                                      dataConfig.begin() + end));
      }
      begin = end + 1;
      alignmentLen = std::max(alignmentLen, alignSize);
    } else if (dataConfig[begin].substr(3, 2) == "12") {
      uint16_t alignSize = 1;
      uint32_t strctMaxLen = std::stoi(dataConfig[begin + 1], nullptr, 16);
      int struct_end = 1;
      int end = begin + 1;
      std::string estr = dataConfig[begin]
                             .substr(0, dataConfig[begin].size() - 2)
                             .append("FF");
      while (struct_end != 0) {
        end++;
        if (dataConfig[begin] == dataConfig[end]) {
          struct_end += 1;
        } else if (dataConfig[end] == estr) {
          struct_end -= 1;
        }
      };

      if (dataConfig[begin][2] != '1') {
        alignSize = sizeof(uintptr_t);
        dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);
        dataIndex += 4;

        payload->append(data + dataIndex, 4);
        dataIndex += 4;

        uintptr_t ptr = *(reinterpret_cast<uintptr_t *>(data + dataIndex));
        dataIndex += sizeof(uintptr_t);

        char *new_data = reinterpret_cast<char *>(ptr);
        uint32_t new_dataIndex = 0;

        for (int i = 0; i < strctMaxLen; ++i)
          encodeMsgPayload(payload, new_data, new_dataIndex,
                           DataConfig(dataConfig.begin() + begin + 2,
                                      dataConfig.begin() + end));

        dataIndex += sizeof(uintptr_t);
      } else {
        alignSize = sizeof(uintptr_t);
        dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

        uintptr_t ptr = *(reinterpret_cast<uintptr_t *>(data + dataIndex));
        dataIndex += sizeof(uintptr_t);

        char *new_data = reinterpret_cast<char *>(ptr);

        payload->append(new_data + 4, 4);

        ptr = *(reinterpret_cast<uintptr_t *>(new_data + 8));
        new_data = reinterpret_cast<char *>(ptr);
        uint32_t new_dataIndex = 0;
        for (int i = 0; i < strctMaxLen; ++i)
          encodeMsgPayload(payload, new_data, new_dataIndex,
                           DataConfig(dataConfig.begin() + begin + 2,
                                      dataConfig.begin() + end));
      }
      begin = end + 1;
      alignmentLen = std::max(alignmentLen, alignSize);
    } else if (dataConfig[begin].substr(3, 2) == "20") {
      int struct_end = 1;
      int end = begin;
      std::string estr = dataConfig[begin]
                             .substr(0, dataConfig[begin].size() - 2)
                             .append("FF");
      while (struct_end != 0) {
        end++;
        if (dataConfig[begin] == dataConfig[end]) {
          struct_end += 1;
        } else if (dataConfig[end] == estr) {
          struct_end -= 1;
        }
      };
      if (dataConfig[begin][2] != 1) {
        // 首先需要将union字段的dataConfig全部给剥离开，然后对里面每个子类型进行解析
        std::vector<DataConfig> dataConfigList;
        for (int splitStart = begin + 1; splitStart < end;) {
          DataConfig tempDataConfig;
          if (dataConfig[splitStart].substr(3, 2) == "00") {
            // 基本数据类型
            tempDataConfig.push_back(dataConfig[splitStart++]);
          } else if (dataConfig[splitStart].substr(3, 2) == "01" ||
                     dataConfig[splitStart].substr(3, 2) == "02") {
            // 定长结构体或变长结构体
            tempDataConfig.insert(
                tempDataConfig.end(),
                {dataConfig[splitStart++], dataConfig[splitStart++]});
          } else {
            int split_struct_end = 1;
            int splitEnd = splitStart;
            std::string split_estr =
                dataConfig[splitStart]
                    .substr(0, dataConfig[splitStart].size() - 2)
                    .append("FF");
            while (split_struct_end != 0) {
              splitEnd++;
              if (dataConfig[splitStart] == dataConfig[splitEnd]) {
                split_struct_end += 1;
              } else if (dataConfig[splitEnd] == split_estr) {
                split_struct_end -= 1;
              }
            };
            tempDataConfig.insert(tempDataConfig.end(),
                                  dataConfig.begin() + splitStart,
                                  dataConfig.begin() + splitEnd + 1);
            splitStart = splitEnd + 1;
          }
          dataConfigList.push_back(tempDataConfig);
        }
        int unionHashIndex = 0;
        int unionHashKey = *((int *)(payload->data() + payload->size() - 4));
        for (; unionHashIndex < curHashCode.size(); ++unionHashIndex) {
          if (unionHashKey == curHashCode[unionHashIndex]) {
            break;
          }
        }
        if (unionHashIndex == curHashCode.size()) {
          unionHashIndex = dataConfigList.size() - 1;
        } else {
          int tempUnionHashIndex = dataConfigList.size() - 1;
          while (curHashCode[unionHashIndex] != 0) {
            tempUnionHashIndex--;
            unionHashIndex++;
          }
          unionHashIndex = tempUnionHashIndex;
        }

        uint16_t unionAlignSize = 0;
        uint32_t unionSize = 0;
        // 查找union中最大内存长度的字段，和最大的对齐长度。但是内存长度并没有对齐
        for (int dataConfigListIndex = 0;
             dataConfigListIndex < dataConfigList.size();
             ++dataConfigListIndex) {
          uint32_t subDataIndex = 0;
          std::shared_ptr<std::string> subPayload =
              std::make_shared<std::string>();
          uint16_t ret = encodeMsgPayload(subPayload, data, subDataIndex,
                                          dataConfigList[dataConfigListIndex]);
          unionAlignSize = std::max(ret, unionAlignSize);
          unionSize = std::max(unionSize, (uint32_t)subPayload->size());
        }

        for (int dataConfigListIndex = 0;
             dataConfigListIndex < dataConfigList.size();
             ++dataConfigListIndex) {
          uint32_t subDataIndex = 0;
          std::shared_ptr<std::string> subPayload =
              std::make_shared<std::string>();

          if (dataConfigListIndex != unionHashIndex) {
            encodeMsgPayload(subPayload, data, subDataIndex,
                             dataConfigList[dataConfigListIndex]);
            subDataIndex = subPayload->size();
            while (subDataIndex != 0) {
              payload->push_back('\0');
              subDataIndex--;
            }
          } else {
            dataIndex += (unionAlignSize - dataIndex % unionAlignSize) &
                         (unionAlignSize - 1);
            // 这里有问题
            uint32_t validSize = dataIndex;
            encodeMsgPayload(payload, data, dataIndex,
                             dataConfigList[dataConfigListIndex]);
            validSize = dataIndex - validSize;

            dataIndex -= validSize;
            dataIndex += unionSize;
            dataIndex += (unionAlignSize - dataIndex % unionAlignSize) &
                         (unionAlignSize - 1);
          }
        }

        alignmentLen = std::max(alignmentLen, unionAlignSize);
      } else {
        int16_t alignSize = sizeof(uintptr_t);
        dataIndex += (alignSize - dataIndex % alignSize) & (alignSize - 1);

        uintptr_t ptr = *(reinterpret_cast<uintptr_t *>(data + dataIndex));
        dataIndex += sizeof(uintptr_t);

        char *new_data = reinterpret_cast<char *>(ptr);

        DataConfig newDataConfig = DataConfig(dataConfig.begin() + begin,
                                              dataConfig.begin() + end + 1);
        newDataConfig[0][2] = '0';
        newDataConfig[newDataConfig.size() - 1][2] = '0';

        uint32_t new_dataIndex = 0;
        encodeMsgPayload(payload, new_data, new_dataIndex, newDataConfig);

        alignmentLen = std::max(alignmentLen, (uint16_t)sizeof(uintptr_t));
      }
      begin = end + 1;
    }
  }
  // ql end
  dataIndex += (alignmentLen - dataIndex % alignmentLen) & (alignmentLen - 1);
  return alignmentLen;
}

// to serialize data
std::shared_ptr<std::string> ObjectEncoderDecoder::encodeMsg(
    std::shared_ptr<std::vector<std::shared_ptr<Deserialization>>> data) {
  auto data_copy = [](std::shared_ptr<std::string> dest, const char *src,
                      int length) -> void {
    for (int i = 0; i < length; ++i) {
      dest->push_back(*(src + i));
    }
  };
  auto data_padding = [](std::shared_ptr<std::string> dest,
                         int length) -> void {
    for (int i = 0; i < length; ++i) {
      dest->push_back(uint8_t(0));
    }
  };
  // create send_data
  std::shared_ptr<std::string> ret = std::make_shared<std::string>();

  // get DDSConfig && typeCastingSizeRelation
  DDSConfigTemplate &DDSConfig = getDDSConfig((char *)("DDS.config.json"));

  for (int index = 0; index < data->size(); ++index) {
    std::shared_ptr<Deserialization> subdata = data->at(index);

    std::string topicName = subdata->topicName;
    std::string msgName = subdata->messageName;
    std::string guid = encodeGuidData[topicName.append(msgName)];

    curHashCode = hashCodeMap[guid];

    ret->append(guid.data(), 32);
    //
    ret->append((char *)(&(subdata->tcs_rx)), 6);
    // insert payload into message
    std::shared_ptr<std::string> payload = std::make_shared<std::string>();

    for (DDSConfigTemplate::iterator it = DDSConfig.begin();
         it != DDSConfig.end(); ++it) {
      if (it->first == guid) {
        uint32_t dataIndex = 0;
        encodeMsgPayload(payload, (char *)subdata->data->data(), dataIndex,
                         it->second);
        break;
      }
    }

    ret->append(*payload);
  }

  return ret;
}

} // namespace Hirain_Deserialization
