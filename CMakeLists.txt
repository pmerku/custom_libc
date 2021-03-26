cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME custom_libc)
project(${PROJECT_NAME} C CXX)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${dir}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${dir}/build)

# C compiler setup
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -O3")

# CPP compiler setup
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -O3")

# ASM compiler setup
enable_language(ASM_NASM)
set(CAN_USE_ASSEMBLER TRUE)

if (UNIX)
    set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
elseif (APPLE)
    set(CMAKE_ASM_NASM_OBJECT_FORMAT macho64)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-DAPPLE=1")
endif ()

# building static library
file(GLOB_RECURSE HEADERS "include/**.h" "include/**.hpp" "include/**.asm")
file(GLOB_RECURSE SOURCES "src/**.c" "src/**.cpp" "src/**.asm")

include_directories(include)
add_library(ft STATIC ${SOURCES})

# tests
enable_testing()

file(GLOB TEST_FOLDER tests/*)

foreach (folder IN ITEMS ${TEST_FOLDER})
    if (IS_DIRECTORY ${folder})
        # generate test name
        get_filename_component(test_name ${folder} NAME)
        file(GLOB_RECURSE test_source ${folder}/*)

        # build executable
        add_executable(test_${test_name} ${test_source})
        target_link_libraries(test_${test_name} ft)
        target_include_directories(test_${test_name} PRIVATE ${PROJECT_SOURCE_DIR}/include)
        target_include_directories(test_${test_name} PRIVATE ${PROJECT_SOURCE_DIR}/tests)

        # generate test
        add_test(NAME ${test_name} COMMAND test_${test_name} DEPENDS test_${test_name})
    endif ()
endforeach ()
