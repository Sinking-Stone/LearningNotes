#include_directories("include/")

project(QL_DE)
add_compile_options(-std=c++11)

file(GLOB SOURCES "*.cpp")
# debug
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(a.out ${SOURCES})