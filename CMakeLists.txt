cmake_minimum_required(VERSION 3.10)
project(KMPCXX)

set(CMAKE_CXX_STANDARD 14)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# dirs
include_directories(header src test)

# source
add_executable(KMP src/main.cpp src/KMP.cpp src/prefix_func.cpp)

# tests
add_executable(prefix_func_test test/prefix_func_test.cpp src/prefix_func.cpp)
add_executable(KMP_test test/KMP_test.cpp src/KMP.cpp src/prefix_func.cpp)
target_link_libraries(prefix_func_test ${GTEST_LIBRARIES} pthread)
target_link_libraries(KMP_test ${GTEST_LIBRARIES} pthread)