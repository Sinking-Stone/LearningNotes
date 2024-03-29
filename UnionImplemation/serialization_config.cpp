#include "serialization_config.hpp"

namespace serialization_config{

std::map<std::string,std::string>  getTypeCastingMap(){
    std::map<std::string,std::string> typeCastingMap;
    //base type
    typeCastingMap["0x00001"]=std::string("INT8_TYPE");//char - char bool
    typeCastingMap["0x00002"]=std::string("UINT8_TYPE");//uchar - octet
    typeCastingMap["0x00003"]=std::string("INT16_TYPE");//short - short
    typeCastingMap["0x00004"]=std::string("UINT16_TYPE");//ushort - ushort
    typeCastingMap["0x00005"]=std::string("INT32_TYPE");//int - long
    typeCastingMap["0x00006"]=std::string("UINT32_TYPE");//uint - ulong
    typeCastingMap["0x00007"]=std::string("INT64_TYPE");//llong - llong
    typeCastingMap["0x00008"]=std::string("UINT64_TYPE");//ullong - ullong
    typeCastingMap["0x00009"]=std::string("FLOAT32_TYPE");//float - float
    typeCastingMap["0x0000A"]=std::string("FLOAT64_TYPE");//double - double
    typeCastingMap["0x0000B"]=std::string("UTF8_TYPE");
    typeCastingMap["0x0000C"]=std::string("UTF16LE_TYPE");
    typeCastingMap["0x0000D"]=std::string("UTF16BE_TYPE");
    typeCastingMap["0x0000E"]=std::string("STRING64_TYPE");
    //fixed length array
    typeCastingMap["0x00101"]=std::string("FIXED_INT8_TYPE");
    typeCastingMap["0x00102"]=std::string("FIXED_UINT8_TYPE");
    typeCastingMap["0x00103"]=std::string("FIXED_INT16_TYPE");
    typeCastingMap["0x00104"]=std::string("FIXED_UINT16_TYPE");
    typeCastingMap["0x00105"]=std::string("FIXED_INT32_TYPE");
    typeCastingMap["0x00106"]=std::string("FIXED_UINT32_TYPE");
    typeCastingMap["0x00107"]=std::string("FIXED_INT64_TYPE");
    typeCastingMap["0x00108"]=std::string("FIXED_UINT64_TYPE");
    typeCastingMap["0x00109"]=std::string("FIXED_FLOAT32_TYPE");
    typeCastingMap["0x0010A"]=std::string("FIXED_FLOAT64_TYPE");
    typeCastingMap["0x0010B"]=std::string("FIXED_UTF8_TYPE");
    typeCastingMap["0x0010C"]=std::string("FIXED_UTF16LE_TYPE");
    typeCastingMap["0x0010D"]=std::string("FIXED_UTF16BE_TYPE");
    typeCastingMap["0x0010E"]=std::string("FIXED_STRING64_TYPE");
    //variable length array
    typeCastingMap["0x00201"]=std::string("VARIABLE_INT8_TYPE");
    typeCastingMap["0x00202"]=std::string("VARIABLE_UINT8_TYPE");
    typeCastingMap["0x00203"]=std::string("VARIABLE_INT16_TYPE");
    typeCastingMap["0x00204"]=std::string("VARIABLE_UINT16_TYPE");
    typeCastingMap["0x00205"]=std::string("VARIABLE_INT32_TYPE");
    typeCastingMap["0x00206"]=std::string("VARIABLE_UINT32_TYPE");
    typeCastingMap["0x00207"]=std::string("VARIABLE_INT64_TYPE");
    typeCastingMap["0x00208"]=std::string("VARIABLE_UINT64_TYPE");
    typeCastingMap["0x00209"]=std::string("VARIABLE_FLOAT32_TYPE");
    typeCastingMap["0x0020A"]=std::string("VARIABLE_FLOAT64_TYPE");
    typeCastingMap["0x0020B"]=std::string("VARIABLE_UTF8_TYPE");
    typeCastingMap["0x0020C"]=std::string("VARIABLE_UTF16LE_TYPE");
    typeCastingMap["0x0020D"]=std::string("VARIABLE_UTF16BE_TYPE");
    typeCastingMap["0x0020E"]=std::string("VARIABLE_STRING64_TYPE");
    //struct
    typeCastingMap["0x01000"]=std::string("STRUCT_START_TYPE");
    typeCastingMap["0x010FF"]=std::string("STRUCT_END_TYPE");
    typeCastingMap["0x01100"]=std::string("FIXED_STRUCT_START_TYPE");
    typeCastingMap["0x011FF"]=std::string("FIXED_STRUCT_END_TYPE");
    typeCastingMap["0x01200"]=std::string("VARIABLE_STRUCT_START_TYPE");
    typeCastingMap["0x012FF"]=std::string("VARIABLE_STRUCT_END_TYPE");
    //union
    typeCastingMap["0x02000"]=std::string("UNION_START_TYPE");
    typeCastingMap["0x03000"]=std::string("UNION_ELE_START_TYPE");
    typeCastingMap["0x030FF"]=std::string("UNION_ELE_END_TYPE");
    typeCastingMap["0x020FF"]=std::string("UNION_END_TYPE");
    //base type using ptr point to it
    typeCastingMap["0x10001"]=std::string("INT8_TYPE_PTR");
    typeCastingMap["0x10002"]=std::string("UINT8_TYPE_PTR");
    typeCastingMap["0x10003"]=std::string("INT16_TYPE_PTR");
    typeCastingMap["0x10004"]=std::string("UINT16_TYPE_PTR");
    typeCastingMap["0x10005"]=std::string("INT32_TYPE_PTR");
    typeCastingMap["0x10006"]=std::string("UINT32_TYPE_PTR");
    typeCastingMap["0x10007"]=std::string("INT64_TYPE_PTR");
    typeCastingMap["0x10008"]=std::string("UINT64_TYPE_PTR");
    typeCastingMap["0x10009"]=std::string("FLOAT32_TYPE_PTR");
    typeCastingMap["0x1000A"]=std::string("FLOAT64_TYPE_PTR");
    typeCastingMap["0x1000B"]=std::string("UTF8_TYPE_PTR");
    typeCastingMap["0x1000C"]=std::string("UTF16LE_TYPE_PTR");
    typeCastingMap["0x1000D"]=std::string("UTF16BE_TYPE_PTR");
    typeCastingMap["0x1000E"]=std::string("STRING64_TYPE_PTR");
    //fixed length array using ptr point to it
    typeCastingMap["0x10101"]=std::string("FIXED_INT8_TYPE_PTR");
    typeCastingMap["0x10102"]=std::string("FIXED_UINT8_TYPE_PTR");
    typeCastingMap["0x10103"]=std::string("FIXED_INT16_TYPE_PTR");
    typeCastingMap["0x10104"]=std::string("FIXED_UINT16_TYPE_PTR");
    typeCastingMap["0x10105"]=std::string("FIXED_INT32_TYPE_PTR");
    typeCastingMap["0x10106"]=std::string("FIXED_UINT32_TYPE_PTR");
    typeCastingMap["0x10107"]=std::string("FIXED_INT64_TYPE_PTR");
    typeCastingMap["0x10108"]=std::string("FIXED_UINT64_TYPE_PTR");
    typeCastingMap["0x10109"]=std::string("FIXED_FLOAT32_TYPE_PTR");
    typeCastingMap["0x1010A"]=std::string("FIXED_FLOAT64_TYPE_PTR");
    typeCastingMap["0x1010B"]=std::string("FIXED_UTF8_TYPE_PTR");
    typeCastingMap["0x1010C"]=std::string("FIXED_UTF16LE_TYPE_PTR");
    typeCastingMap["0x1010D"]=std::string("FIXED_UTF16BE_TYPE_PTR");
    typeCastingMap["0x1010E"]=std::string("FIXED_STRING64_TYPE_PTR");
    //variable length array using ptr point to it
    typeCastingMap["0x10201"]=std::string("VARIABLE_INT8_TYPE_PTR");
    typeCastingMap["0x10202"]=std::string("VARIABLE_UINT8_TYPE_PTR");
    typeCastingMap["0x10203"]=std::string("VARIABLE_INT16_TYPE_PTR");
    typeCastingMap["0x10204"]=std::string("VARIABLE_UINT16_TYPE_PTR");
    typeCastingMap["0x10205"]=std::string("VARIABLE_INT32_TYPE_PTR");
    typeCastingMap["0x10206"]=std::string("VARIABLE_UINT32_TYPE_PTR");
    typeCastingMap["0x10207"]=std::string("VARIABLE_INT64_TYPE_PTR");
    typeCastingMap["0x10208"]=std::string("VARIABLE_UINT64_TYPE_PTR");
    typeCastingMap["0x10209"]=std::string("VARIABLE_FLOAT32_TYPE_PTR");
    typeCastingMap["0x1020A"]=std::string("VARIABLE_FLOAT64_TYPE_PTR");
    typeCastingMap["0x1020B"]=std::string("VARIABLE_UTF8_TYPE_PTR");
    typeCastingMap["0x1020C"]=std::string("VARIABLE_UTF16LE_TYPE_PTR");
    typeCastingMap["0x1020D"]=std::string("VARIABLE_UTF16BE_TYPE_PTR");
    typeCastingMap["0x1020E"]=std::string("VARIABLE_STRING64_TYPE_PTR");
    //struct using ptr point to it
    typeCastingMap["0x11000"]=std::string("STRUCT_START_TYPE_PTR");
    typeCastingMap["0x110FF"]=std::string("STRUCT_END_TYPE_PTR");
    typeCastingMap["0x11100"]=std::string("FIXED_STRUCT_START_TYPE_PTR");
    typeCastingMap["0x111FF"]=std::string("FIXED_STRUCT_END_TYPE_PTR");
    typeCastingMap["0x11200"]=std::string("VARIABLE_STRUCT_START_TYPE_PTR");
    typeCastingMap["0x112FF"]=std::string("VARIABLE_STRUCT_END_TYPE_PTR");
    //union using ptr point to it
    typeCastingMap["0x12000"]=std::string("UNION_START_TYPE_PTR");
    // typeCastingMap["0x13000"]=std::string("UNION_ELE_START_TYPE_PTR");
    // typeCastingMap["0x130FF"]=std::string("UNION_ELE_END_TYPE_PTR");
    typeCastingMap["0x120FF"]=std::string("UNION_END_TYPE_PTR");

    return typeCastingMap;

}

}