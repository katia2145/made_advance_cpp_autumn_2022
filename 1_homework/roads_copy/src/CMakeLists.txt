cmake_minimum_required(VERSION 3.22.1)

project(road)

set(SOURCE_EXE main.c)
set(SOURCE_LIB ReadCsv.c)

add_library(ReadCsv STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})
target_link_libraries(main ReadCsv)