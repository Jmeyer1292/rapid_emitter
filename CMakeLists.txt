cmake_minimum_required (VERSION 2.6)
project (rapid_emitter)

include_directories(include)

add_library(rapid_emitter src/rapid_emitter.cpp)

add_executable(rapid_test src/test_main.cpp)
target_link_libraries(rapid_test rapid_emitter)
