cmake_minimum_required(VERSION 3.10)
project(KMPCXX)

set(CMAKE_CXX_STANDARD 14)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# dirs
include_directories(header src test)

# source
add_executable(KMP src/main1.cpp src/KMP.cpp src/prefix_func.cpp)
add_executable(cycle_shift src/main2.cpp src/prefix_func.cpp src/cycle_shift.cpp)

# tests
add_executable(KMP_test test/KMP_test.cpp src/KMP.cpp src/prefix_func.cpp)
target_link_libraries(KMP_test ${GTEST_LIBRARIES} pthread)

add_executable(cycle_shift_test test/cycle_shift_test.cpp src/prefix_func.cpp src/cycle_shift.cpp)
target_link_libraries(cycle_shift_test ${GTEST_LIBRARIES} pthread)