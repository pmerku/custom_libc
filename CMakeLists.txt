cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME "custom_libc")
project(${PROJECT_NAME} C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE HEADERS "include/**.h" "include/**.hpp")
file(GLOB_RECURSE SOURCES "src/**.c" "src/**.cpp")

file(GLOB_RECURSE TEST_SOURCES "tests/**.cpp")
include_directories(tests)

add_library(ft STATIC ${SOURCES})
add_executable(test ${TEST_SOURCES})

include_directories(include)

find_library(TEST_LIBRARY ft cmake-build-debug)
target_link_libraries(test LINK_PUBLIC ${TEST_LIBRARY})
