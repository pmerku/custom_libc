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
- `ft_printf`
- `ft_snprintf`
- `ft_fprintf`
- `ft_vsnprintf`
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
- `ft_pow`
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
- `ft_llist_new`
- `ft_llist_clear`
- `ft_llist_free`
- `ft_llist_iter`
- `ft_llist_push`
- `ft_llist_push_back`
- `ft_llist_size`
- `ft_lstmap`
### ft_dllist.h
- `ft_dlstnew`
- `ft_dlstadd_back`
- `ft_dlstadd_front`
- `ft_dlstclear`
- `ft_dlstdelone`
- `ft_dlstiter`
- `ft_dlstlast`
- `ft_dlstmap`
- `ft_dlstsize`
### ft_libasm.h
- `ft_list_push_front`
- `ft_list_size`
- `ft_list_sort`
- `ft_list_remove_if`

## TODO:
Documentation generator/extractor, man pages, Continuous integration, unit testing