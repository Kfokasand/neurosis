cmake_minimum_required (VERSION 2.6)
project(neurosis)

set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(googletest)
include_directories(${gtest_SOURCEDIR}/include  ${gtest_SOURCE_DIR})

add_executable (neurosis neuron.cpp simulation.cpp main.cpp)
add_executable (unittest neuron.cpp simulation.cpp)

target_link_libraries(unittest gtest gtest_main)
add_test(unittest unittest)
