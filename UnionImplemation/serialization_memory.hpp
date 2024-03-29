#ifndef SERIALIZATION_MEMORY
#define SERIALIZATION_MEMORY

#include <sys/types.h>
#include <iostream>

//limit : default_memory_length%8 must equal 0
#define default_memory_length 131072

namespace serialization_memory{

class memory_manager{
    private:
    char * buf;
    ssize_t buf_max_length;
    ssize_t buf_index;
    public:
    memory_manager();
    ~memory_manager();
    //true:src data insert into buf[buf_index+(alias-buf_index%alias_size)&(alias_size-1)]
    uintptr_t add_element(const char * data,ssize_t alias_size,ssize_t data_size);
    uintptr_t add_string(const char * data,uint32_t & strLen);

    //clear buf
    void clear();

};

}

#endif