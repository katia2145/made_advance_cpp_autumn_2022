# cmake_minimum_required(VERSION 3.18.4)
# project(custom_set)

# file(GLOB SOURCES *.cpp)
# file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

# add_library(${PROJECT_NAME} ${SOURCES})

# set(FIB_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
# set(FIB_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)


cmake_minimum_required(VERSION 3.18.4)
project(custom_set)

add_subdirectory(set_lib)

message("FIB_LIB_INCLUDE_DIRS = ${FIB_LIB_INCLUDE_DIRS}")
message("FIB_LIB_LIBRARIES = ${FIB_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${FIB_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${FIB_LIB_LIBRARIES})

add_subdirectory(tests)