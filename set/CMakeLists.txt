# cmake_minimum_required(VERSION 3.22.1)
# project(matrix VERSION 0.1.0)

# add_subdirectory(libs)

# file(GLOB SOURCES "*.cpp" "**/*.cpp")
# file(GLOB INCLUDE_DIRS libs)
# file(GLOB HEADERS "libs/*.h")

# add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
# target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})

# message("SOURCES = ${SOURCES}")

# add_subdirectory(tests)

cmake_minimum_required(VERSION 3.18.4)
project(set)

add_subdirectory(set_lib)

message("SET_LIB_INCLUDE_DIRS = ${SET_LIB_INCLUDE_DIRS}")
message("SET_LIB_LIBRARIES = ${SET_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.cpp)

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

target_include_directories(${PROJECT_NAME} PUBLIC ${SET_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SET_LIB_LIBRARIES})

add_subdirectory(tests)