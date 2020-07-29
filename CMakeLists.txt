cmake_minimum_required(VERSION 3.5) # CMP0069 NEW

project(ops CXX)

###############################################
# option
###############################################
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

# component
set(SIMDJSON_DIR   "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/simdjson")
set(GOOGLETEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/googletest")
set(RUNTIME_DIR    "${CMAKE_CURRENT_SOURCE_DIR}/runtime")
set(EXECUTOR_DIR   "${CMAKE_CURRENT_SOURCE_DIR}/executor")
set(KERNELS_DIR    "${CMAKE_CURRENT_SOURCE_DIR}/kernels")
set(GRAPH_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/graph")
set(NODE_DIR       "${CMAKE_CURRENT_SOURCE_DIR}/node")
set(TESTS_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/tests")


###############################################
# configuration
###############################################
# simdjson
message(STATUS "[ simdjson ] ")
if(EXISTS "${SIMDJSON_DIR}/CMakeLists.txt")
  set(SIMDJSON_JUST_LIBRARY ON)
  add_subdirectory(${SIMDJSON_DIR})
else()
  message(FATAL_ERROR "dependencies simdjson not found.")
endif()

# goggletest
message(STATUS "[ googletest ]")
if(EXISTS "${GOOGLETEST_DIR}/CMakeLists.txt")
  set(BUILD_GMOCK OFF)
  set(INSTALL_GTEST OFF)
  add_subdirectory(${GOOGLETEST_DIR})
else()
  message(FATAL_ERROR "dependencies gtest not found.")
endif()

# runtime
message(STATUS "[ runtime ]")
if(EXISTS "${RUNTIME_DIR}/CMakeLists.txt")
  add_subdirectory(${RUNTIME_DIR})
else()
  message(FATAL_ERROR "dependencies gtest not found.")
endif()

message(STATUS "[ ops ]")
file(GLOB_RECURSE EXECUTOR_SOURCES "${EXECUTOR_DIR}/*.cpp")
file(GLOB_RECURSE KERNELS_SOURCES "${KERNELS_DIR}/*.cpp")
file(GLOB_RECURSE GRAPH_SOURCES "${GRAPH_DIR}/*.cpp")
file(GLOB_RECURSE NODE_SOURCES "${NODE_DIR}/*.cpp")
add_library(op SHARED ${EXECUTOR_SOURCES} ${KERNELS_SOURCES} ${GRAPH_SOURCES} ${NODE_SOURCES})


# tests
message(STATUS "[ tests ]")
if (EXISTS "${TESTS_DIR}")
  add_subdirectory(${TESTS_DIR})
else()
  message(FATAL_ERROR "tests not found.")
endif()
