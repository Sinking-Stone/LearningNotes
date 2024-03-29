#ifndef _IOTask_interaction_DDS
#define _IOTask_interaction_DDS

#include "serialization_memory.hpp"
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace Hirain_Deserialization {

// set of pair<topic-type>
typedef std::map<std::string, std::vector<std::string>> DDSConfigTemplate;

// mapping from "0x0006" to UINT32_TYPE
typedef std::map<std::string, std::string> TypeCastingMap;

// set of struct's types
typedef std::vector<std::string> DataConfig;

struct TCS_TX {
  uint16_t SchedFifo;
  uint16_t SchedRate;
  uint16_t PauseResume;
  uint16_t TxOnChange;
  uint16_t TxNow;
  uint16_t IsChanged;
};

struct TCS_RX {
  uint16_t Error;
  uint16_t Rxnumber;
  uint16_t Timestamp;
};

struct Deserialization {
  std::string topicName;
  std::string messageName;
  //   uint8_t onChangeFlag;
  uint16_t dataLen;
  TCS_TX tcs_tx;
  TCS_RX tcs_rx;
  std::shared_ptr<std::string> data;
};

// 单例模式
class ObjectEncoderDecoder {
public:
  char *historyData;
  // 需要进行初始化，但是还没有操作，这里需要赋值
  std::map<std::string, std::vector<int>> hashCodeMap;
  std::vector<int> curHashCode;

private:
  TypeCastingMap typeCastingMap;
  serialization_memory::memory_manager mm;

  // guid -> topicname,msgname
  std::map<std::string, std::vector<std::string>> guidDecodeData;
  // topicname,msgname -> guid
  std::map<std::string, std::string> encodeGuidData;
  // guid -> typeList
  DDSConfigTemplate mapData;

public:
  static ObjectEncoderDecoder &getInstance() {
    static ObjectEncoderDecoder instance;
    return instance;
  }

  ObjectEncoderDecoder();
  ~ObjectEncoderDecoder();

  std::string getECUName(std::string guid);

  TypeCastingMap &getTypeCastingMap();
  DDSConfigTemplate &getDDSConfig(char *filename);

  // The following functionality is primarily used for data decoding.
  void setPadding(std::shared_ptr<std::string> payload, int alignSize);
  uint16_t castTypeStringToTypeSize(std::string &typeString);

  bool onChanged(char *data, uint32_t b_index,
                 uint32_t e_index); //[b_index,e_index)

  // The following functionality is primarily used for data decoding.from IOTask
  // to DDS
  uint16_t getCurDataAlignSize(DataConfig &dataConfig, int begin, int end);

  uint16_t decodeMsgBasicType(std::shared_ptr<std::string> payload, char *data,
                              uint32_t &dataIndex, std::string &typeString);

  uint16_t decodeMsgFixedArrayType(std::shared_ptr<std::string> payload,
                                   char *data, uint32_t &dataIndex,
                                   std::string &typeString,
                                   std::string &arrLength);

  uint16_t decodeMsgVariableArrayType(std::shared_ptr<std::string> payload,
                                      char *data, uint32_t &dataIndex,
                                      std::string &typeString,
                                      std::string &arrMaxLength);

  uint16_t decodeMsgHeader(std::shared_ptr<Deserialization> createdMsg,
                           char *data);

  uint16_t decodeMsgPayload(std::shared_ptr<std::string> payload, char *data,
                            uint32_t &dataIndex, DataConfig dataConfig);

  std::shared_ptr<std::vector<std::shared_ptr<Deserialization>>>
  decodeMsg(char *data);

  // from DDS to IOTask
  uint16_t encodeMsgBasicType(std::shared_ptr<std::string> payload, char *data,
                              uint32_t &dataIndex, std::string &typeString);

  uint16_t encodeMsgFixedArrayType(std::shared_ptr<std::string> payload,
                                   char *data, uint32_t &dataIndex,
                                   std::string &typeString,
                                   std::string &arrLength);

  uint16_t encodeMsgVariableArrayType(std::shared_ptr<std::string> payload,
                                      char *data, uint32_t &dataIndex,
                                      std::string &typeString,
                                      std::string &arrMaxLength);

  uint16_t encodeMsgPayload(std::shared_ptr<std::string> payload, char *data,
                            uint32_t &dataIndex, DataConfig dataConfig);

  std::shared_ptr<std::string> encodeMsg(
      std::shared_ptr<std::vector<std::shared_ptr<Deserialization>>> data);
};

} // namespace Hirain_Deserialization
#endif
