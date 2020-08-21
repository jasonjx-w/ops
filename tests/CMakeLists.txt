cmake_minimum_required(VERSION 3.5)

set(MODULE_NAME tests)
project(${MODULE_NAME} CXX)

message(STATUS "Configuring ${MODULE_NAME} ... ")

file(GLOB_RECURSE SOURCES "${${MODULE_NAME}_SOURCE_DIR}/*.cpp")
# add_executable(${MODULE_NAME} ${SOURCES})

# target_link_libraries(${MODULE_NAME} PRIVATE ops)

