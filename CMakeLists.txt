cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME "custom_libc")
project(${PROJECT_NAME} C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# C compiler setup
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -D CMAKE_BUILD=1 -O3")

# CPP compiler setup
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -D CMAKE_BUILD=1 -O3")

# ASM copiler setup
enable_language(ASM_NASM)
set(CAN_USE_ASSEMBLER TRUE)

if (UNIX)
    set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
elseif (APPLE)
    set(CMAKE_ASM_NASM_OBJECT_FORMAT macho64)
endif ()

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
