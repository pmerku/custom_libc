cmake_minimum_required(VERSION 3.15)
project(github_libc)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(github_libc
        tests/main.c
        src/ft_string/ft_strlen.s
        src/ft_memory/ft_bzero.c src/ft_string/ft_memset.c include/ft_memory.h src/ft_stdlib/ft_atoi.c include/ft_ctype.h include/ft_stdlib.h src/ft_ctype/ft_isspace.c src/ft_ctype/ft_isdigit.c src/ft_memory/ft_calloc.c src/ft_memory/ft_malloc.c src/ft_memory/ft_free.c src/ft_ctype/ft_isalnum.c src/ft_ctype/ft_isalpha.c src/ft_ctype/ft_isascii.c src/ft_ctype/ft_isprint.c src/ft_ctype/ft_tolower.c src/ft_ctype/ft_toupper.c src/ft_ctype/ft_islower.c src/ft_ctype/ft_isupper.c src/ft_libft/ft_itoa.c include/ft_libft.h src/ft_libft/ft_intlen.c src/ft_libft/ft_itoa_base.c src/ft_libft/ft_intlen_base.c src/ft_string/ft_memccpy.c src/ft_string/ft_memchr.c src/ft_string/ft_memcp.c src/ft_string/ft_memcpy.c src/ft_string/ft_memmove.c include/ft_unistd.h src/ft_unistd/ft_putchar_fd.c src/ft_unistd/ft_putstr_fd.c src/ft_unistd/ft_putendl_fd.c src/ft_unistd/ft_putnbr_fd.c src/ft_libft/ft_split.c src/ft_memory/ft_free_array.c src/ft_string/ft_strchr.c src/ft_string/ft_strdup.c src/ft_libft/ft_strjoin.c src/ft_string/ft_strncmp.c src/ft_string/ft_strnlen.c src/ft_string/ft_strnstr.c src/ft_string/ft_strrchr.c src/ft_libft/ft_strtrim.c src/ft_libft/ft_strempty.c src/ft_libft/ft_substr.c src/ft_libft/get_next_line.c)
