cmake_minimum_required(VERSION 3.7)
project(word-count)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES main.cpp src/WordExtractor.cpp src/WordExtractor.hpp tests/TestWordExtractor.cpp tests/TestWordOccurrenceContainer.cpp src/WordOccurrenceContainer.cpp src/WordOccurrenceContainer.hpp tests/TestWordCounter.cpp src/WordCounter.cpp src/WordCounter.hpp)
add_executable(word-count ${SOURCE_FILES})
target_link_libraries(word-count gtest gtest_main)