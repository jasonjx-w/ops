cmake_minimum_required(VERSION 3.5) # CMP0077 NEW

set(MODULE_NAME ops)
project(${MODULE_NAME} CXX)

###############################################
# option
###############################################
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(LIBRARY_OUTPUT_PATH    "${CMAKE_BINARY_DIR}")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -ggdb -std=c++11")

# component
set(SIMDJSON_DIR   "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/simdjson")
set(GOOGLETEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/googletest")
set(SPDLOG_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog")
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
add_library(${MODULE_NAME} SHARED ${EXECUTOR_SOURCES} ${KERNELS_SOURCES} ${GRAPH_SOURCES} ${NODE_SOURCES})
target_include_directories(${MODULE_NAME} PRIVATE ${EXECUTABLE_OUTPUT_PATH}/include)  # .h of gperftools (together with output lib)
# .h of ops
target_include_directories(${MODULE_NAME} PRIVATE ${RUNTIME_DIR})
target_include_directories(${MODULE_NAME} PRIVATE ${EXECUTOR_DIR})
target_include_directories(${MODULE_NAME} PRIVATE ${KERNELS_DIR})
target_include_directories(${MODULE_NAME} PRIVATE ${GRAPH_DIR})
target_include_directories(${MODULE_NAME} PRIVATE ${NODE_DIR})
target_include_directories(${MODULE_NAME} PRIVATE ${SPDLOG_DIR}/include)         # .h of spdlog
target_include_directories(${MODULE_NAME} PRIVATE ${SIMDJSON_DIR}/include)         # .h of simdjson


# tests
if (OPS_JUST_LIBRARY)
  message(STATUS "Building just the library, omitting all tests.")
else()
  message(STATUS "Building the library and also all tests.")
  message(STATUS "[ tests ]")
  if (EXISTS "${TESTS_DIR}")
    add_subdirectory(${TESTS_DIR})
  else()
    message(FATAL_ERROR "tests not found.")
  endif()
endif()
