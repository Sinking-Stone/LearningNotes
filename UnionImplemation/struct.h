#ifndef HIRAIN_VOSMEIP_STRUCT_H_
#define HIRAIN_VOSMEIP_STRUCT_H_

#include <unistd.h>
#include <set>
#include <stdint.h>
#include <map>
#include <string>
#include <vector>

#define STRUCT_LEN  1
#define ARRAY_LEN   1
#define DDS_OR_SOMEIP   0 

typedef struct 
{
    std::vector<uint16_t> type;
    uint32_t    len;
}payload_info;

typedef std::map<std::string,payload_info> Msg_type;
// 数据结构从后往前数：第一位是基本数据类型int8,16等
//                 第二位是空值，第三位：1表示固定数组，2表示可变数组，可变之后会跟着具体的数据长度
//                 第四位：0表示基本数据类型，1表示结构体，2表示联合体
//                 第五位：0表示基本数据类型，1表示指针
//base type
#define INT8_TYPE       0x00001    
#define UINT8_TYPE      0x00002  
#define INT16_TYPE      0x00003   
#define UINT16_TYPE     0x00004  
#define INT32_TYPE      0x00005    
#define UINT32_TYPE     0x00006   
#define INT64_TYPE      0x00007
#define UINT64_TYPE     0x00008  
#define FLOAT32_TYPE    0x00009
#define FLOAT64_TYPE    0x0000A
#define UTF8_TYPE       0x0000B
#define UTF16LE_TYPE    0x0000C
#define UTF16BE_TYPE    0x0000D
//ql add
#define STRING64_TYPE    0x0000E

//Fixed length array, this type is immediately followed by length of type uint16
#define FIXED_INT8_TYPE       0x00101
#define FIXED_UINT8_TYPE      0x00102
#define FIXED_INT16_TYPE      0x00103
#define FIXED_UINT16_TYPE     0x00104
#define FIXED_INT32_TYPE      0x00105
#define FIXED_UINT32_TYPE     0x00106 
#define FIXED_INT64_TYPE      0x00107    
#define FIXED_UINT64_TYPE     0x00108 
#define FIXED_FLOAT32_TYPE    0x00109  
#define FIXED_FLOAT64_TYPE    0x0010A
#define FIXED_UTF8_TYPE       0x0010B  
#define FIXED_UTF16LE_TYPE    0x0010C
#define FIXED_UTF16BE_TYPE    0x0010D   
//ql add
#define FIXED_STRING64_TYPE    0x0010E

//Variable length array，this type is immediately followed by max length of type uint16 
#define VARIABLE_INT8_TYPE       0x00201    
#define VARIABLE_UINT8_TYPE      0x00202  
#define VARIABLE_INT16_TYPE      0x00203      
#define VARIABLE_UINT16_TYPE     0x00204  
#define VARIABLE_INT32_TYPE      0x00205   
#define VARIABLE_UINT32_TYPE     0x00206  
#define VARIABLE_INT64_TYPE      0x00207   
#define VARIABLE_UINT64_TYPE     0x00208 
#define VARIABLE_FLOAT32_TYPE    0x00209
#define VARIABLE_FLOAT64_TYPE    0x0020A
#define VARIABLE_UTF8_TYPE       0x0020B
#define VARIABLE_UTF16LE_TYPE    0x0020C
#define VARIABLE_UTF16BE_TYPE    0x0020D
//ql add
#define VARIABLE_STRING64_TYPE    0x0020E

//struct type,this type is immediately followed by length of type uint16
#define STRUCT_START_TYPE               0x01000
#define STRUCT_END_TYPE                 0x010FF
#define FIXED_STRUCT_START_TYPE         0x01100
#define FIXED_STRUCT_END_TYPE           0x011FF
#define VARIABLE_STRUCT_START_TYPE      0x01200
#define VARIABLE_STRUCT_END_TYPE        0x012FF
//union type
#define UNION_START_TYPE        0x02000
#define UNION_END_TYPE        0x020FF


//ql add
//base type
#define INT8_TYPE_PTR       0x10001    
#define UINT8_TYPE_PTR      0x10002  
#define INT16_TYPE_PTR      0x10003   
#define UINT16_TYPE_PTR     0x10004  
#define INT32_TYPE_PTR      0x10005    
#define UINT32_TYPE_PTR     0x10006   
#define INT64_TYPE_PTR      0x10007
#define UINT64_TYPE_PTR     0x10008  
#define FLOAT32_TYPE_PTR    0x10009
#define FLOAT64_TYPE_PTR    0x1000A
#define UTF8_TYPE_PTR       0x1000B
#define UTF16LE_TYPE_PTR    0x1000C
#define UTF16BE_TYPE_PTR    0x1000D
//ql add
#define STRING64_TYPE_PTR    0x1000E

//Fixed length array, this type is immediately followed by length of type uint16
#define FIXED_INT8_TYPE_PTR       0x10101
#define FIXED_UINT8_TYPE_PTR      0x10102
#define FIXED_INT16_TYPE_PTR      0x10103
#define FIXED_UINT16_TYPE_PTR     0x10104
#define FIXED_INT32_TYPE_PTR      0x10105
#define FIXED_UINT32_TYPE_PTR     0x10106
#define FIXED_INT64_TYPE_PTR      0x10107 
#define FIXED_UINT64_TYPE_PTR     0x10108 
#define FIXED_FLOAT32_TYPE_PTR    0x10109  
#define FIXED_FLOAT64_TYPE_PTR    0x1010A
#define FIXED_UTF8_TYPE_PTR       0x1010B  
#define FIXED_UTF16LE_TYPE_PTR    0x1010C
#define FIXED_UTF16BE_TYPE_PTR    0x1010D   
//ql add
#define FIXED_STRING64_TYPE_PTR    0x1010E

//Variable length array，this type is immediately followed by max length of type uint16 
#define VARIABLE_INT8_TYPE_PTR       0x10201    
#define VARIABLE_UINT8_TYPE_PTR      0x10202  
#define VARIABLE_INT16_TYPE_PTR      0x10203      
#define VARIABLE_UINT16_TYPE_PTR     0x10204  
#define VARIABLE_INT32_TYPE_PTR      0x10205   
#define VARIABLE_UINT32_TYPE_PTR     0x10206  
#define VARIABLE_INT64_TYPE_PTR      0x10207   
#define VARIABLE_UINT64_TYPE_PTR     0x10208 
#define VARIABLE_FLOAT32_TYPE_PTR    0x10209
#define VARIABLE_FLOAT64_TYPE_PTR    0x1020A
#define VARIABLE_UTF8_TYPE_PTR       0x1020B
#define VARIABLE_UTF16LE_TYPE_PTR    0x1020C
#define VARIABLE_UTF16BE_TYPE_PTR    0x1020D
//ql add
#define VARIABLE_STRING64_TYPE_PTR    0x1020E

//struct type,this type is immediately followed by length of type uint16
#define STRUCT_START_TYPE_PTR               0x11000
#define STRUCT_END_TYPE_PTR                 0x110FF
#define FIXED_STRUCT_START_TYPE_PTR         0x11100
#define FIXED_STRUCT_END_TYPE_PTR           0x111FF
#define VARIABLE_STRUCT_START_TYPE_PTR      0x11200
#define VARIABLE_STRUCT_END_TYPE_PTR        0x112FF
//union type
#define UNION_START_TYPE_PTR        0x12000
#define UNION_END_TYPE_PTR        0x120FF




#endif // HIRAIN_VOSMEIP_STRUCT_H_
