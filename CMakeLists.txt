cmake_minimum_required(VERSION 3.15)
project(github_libc)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(github_libc
        tests/main.c
        include/ft_stdio/ft_printf.h
        include/ft_stdio/ft_printf_utils.h
        include/ft_ctype.h
        include/ft_libft.h
        include/ft_memory.h
        include/ft_stdlib.h
        include/ft_string.h
        include/ft_unistd.h
        src/ft_stdio/
        src/ft_ctype/
        src/ft_memory/
        src/ft_string/
        src/ft_unistd/
        src/ft_stdlib/
        src/ft_libft/
        include/ft_llist.h
        src/ft_llist/
        src/ft_math/
        include/ft_math.h
        )
