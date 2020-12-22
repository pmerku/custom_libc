cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME "custom_libc")
project(${PROJECT_NAME} C CXX)

# C compiler setup
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -D CMAKE_BUILD=1")

# CPP compiler setup
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -D CMAKE_BUILD=1")

# ASM copiler setup
enable_language(ASM_NASM)
set(CAN_USE_ASSEMBLER TRUE)
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)

# building static library
file(GLOB_RECURSE HEADERS "include/**.h" "include/**.hpp" "include/**.asm")
file(GLOB_RECURSE SOURCES "src/**.c" "src/**.cpp" "src/**.asm")

include_directories(include)
add_library(ft STATIC ${SOURCES})

# building test executable
file(GLOB_RECURSE TEST_SOURCES "tests/**.cpp")
include_directories(tests)
add_executable(test ${TEST_SOURCES})

target_link_libraries(test ft)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/tests)
