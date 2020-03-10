## Custom_libc
Personal version of some c libraries
### ft_string.h
- `ft_stpcpy`
- `ft_strcat` | `ft_strncat` | `ft_strlcat`
- `ft_strchr` ok | `ft_strrchr` ok
- `ft_strcmp` todo | `ft_strncmp` ok
- `ft_strcpy` | `ft_strncpy` | `ft_strlcpy`
- `ft_strerror`
- `ft_strlen` ok | `ft_strnlen` ok
- `ft_strpbrk`
- `ft_strsep`
- `ft_strspn` | `ft_strcspn`
- `ft_strstr` todo | `ft_strnstr` ok
- `ft_strtok`
- `ft_strdup` ok | `ft_strndup`
- `ft_strlwr`
- `ft_strupr`
- `ft_strrev`
- `ft_strset`
- `ft_strnset`
- `ft_memcpy` ok | `ft_memccpy` ok
- `ft_memset` ok
- `ft_memmove` ok
- `ft_memcmp` ok
- `ft_memchr` ok
### ft_memory.h
- `ft_malloc` ok
- `ft_calloc` ok
- `ft_realloc`
- `ft_free` ok
- `ft_bzero` ok
- `ft_free_array` ok
### ft_stdio.h
- `ft_printf` ok <- refactor
- `ft_snprintf` ok <- refactor
- `ft_fprintf` ok <- refactor
- `ft_vprintf` ok <- refactor
- `ft_eprintf` ok <- refactor
- `ft_vfprintf` ok <- refactor
### ft_stdlib.h
- `ft_abs` ok | `ft_dabs` ok
- `ft_max` ok
- `ft_min` ok
- `ft_atoi` ok
- `ft_atoi_base`
- `ft_atol` | `ft_atoll`
- `ft_atol_base` | `ft_atoll_base`
### ft_unistd.h
- `ft_write` ok
- `ft_read` ok
- `ft_putchar_fd` ok
- `ft_pustr_fd` ok
- `ft_putnbr_fd` ok
- `ft_putnbr_fd_base`
### ft_libft.h
- `get_next_line` ok
- `ft_intlen` ok | `ft_intlen_base` ok
- `ft_itoa` ok
- `ft_ltoa` | `ft_lltoa`
- `ft_itoa_base` ok
- `ft_ltoa_base` | `ft_lltoa_base`
- `ft_split` ok | `ft_nsplit` ok
- `ft_strempty` ok
- `ft_strip_chars` ok
- `ft_strjoin` ok
- `ft_strtrim` ok
- `ft_substr` ok
### ft_math.h
- `ft_ceil`
- `ft_floor`
- `ft_pow` ok
- `ft_sqrt`
### ft_ctype.h
- `ft_isalnum` ok
- `ft_isalpha` ok
- `ft_isascii` ok
- `ft_isdigit` ok
- `ft_islower` ok
- `ft_isprint` ok
- `ft_isspace` ok
- `ft_isupper` ok
- `ft_tolower` ok
- `ft_toupper` ok
### ft_llist.h
- `ft_llist_new` ok
- `ft_llist_clear` ok
- `ft_llist_free` ok
- `ft_llist_iter` ok
- `ft_llist_push_front` ok
- `ft_llist_push_back` ok
- `ft_llist_size` ok
- `ft_lstlast` todo?
- `ft_lstmap` todo?
- `ft_llist_push_front` todo in asm
- `ft_llist_size` todo in asm
- `ft_llist_sort`
- `ft_llist_remove_if`
### ft_dllist.h
- `ft_dllist_new`
- `ft_dllist_push_back`
- `ft_dllist_push_front`
- `ft_dllist_clear`
- `ft_dllist_free`
- `ft_dllist_iter`
- `ft_dllist_last`
- `ft_dllist_map`
- `ft_dllist_size`

## TODO:
Documentation generator/extractor, man pages, Continuous integration, unit testing
