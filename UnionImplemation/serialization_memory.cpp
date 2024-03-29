#include "serialization_memory.hpp"
#include <string.h>

//limit : default_memory_length%8 must equal 0
#define default_memory_length 131072

namespace serialization_memory{

memory_manager::memory_manager(){
    buf=nullptr;
    buf=(char *)(new double[default_memory_length/sizeof(double)]);
    // buf为什么要设置这样一个奇怪的大小(wfl)
    if(buf==nullptr){
        perror("new memory fail");
    }
    // 131072有什么特殊含义？(wfl)
    buf_max_length=default_memory_length;
    buf_index=0;
}

memory_manager::~memory_manager(){
    if(buf!=nullptr){
        delete buf;
    }
}

//true:src data insert into buf[buf_index+(alias-buf_index%alias_size)&(alias_size-1)]/////??????(wfl)
uintptr_t memory_manager::add_element(const char * data,ssize_t alias_size,ssize_t data_size){

    buf_index+=((alias_size-buf_index%alias_size)&(alias_size-1));

    if(buf_max_length<=buf_index || buf_max_length<=buf_index+data_size){
        perror("Out of memory");
        return 0;
    }

    memcpy((void *)(buf+buf_index),(void *)data,data_size);
    buf_index+=data_size;

    return reinterpret_cast<uintptr_t>(buf+buf_index-data_size);
}

uintptr_t memory_manager::add_string(const char * data,uint32_t & strLen){
    uintptr_t ptr = reinterpret_cast<uintptr_t>(buf+buf_index);
    do{
        buf[buf_index++]=data[strLen++];
    }while(data[strLen-1]!=0);
    return ptr;
}

//clear buf
void memory_manager::clear(){
    buf_index=0;
}

};

