## Custom_libc
Personal version of some C/CPP libraries
### ft_string.h
- `ft_stpcpy`
- `ft_strcat` | `ft_strncat` | `ft_strlcat`
- `ft_strchr` ok | `ft_strrchr` ok
- `ft_strcmp` ok | `ft_strncmp` ok
- `ft_strcpy` ok | `ft_strncpy` | `ft_strlcpy`
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
- `ft_realloc` ok
- `ft_free` ok
- `ft_bzero` ok
- `ft_free_array` ok
- `ft_get_size` ok
### ft_rbtree.h
- `ft_rb_parent`
- `ft_rb_rotate_left`
- `ft_rb_rotate_right`
- `ft_rb_insert`
- `ft_rb_insert_recurse`
- `ft_rb_insert_recurse`
- `ft_rb_insert_fixup`
- `ft_rb_print`
- `ft_rb_search`
- `ft_rb_replace_node`
- `ft_rb_delete_one_child`
- `ft_rb_delete`
- `ft_rb_delete_fixup`
### ft_stdio.h
- `ft_printf` ok
- `ft_snprintf` ok
- `ft_fprintf` ok
- `ft_vprintf` ok
- `ft_eprintf` ok
- `ft_vfprintf` ok
### ft_stdlib.h
- `ft_abs` ok | `ft_dabs` ok
- `ft_max` ok
- `ft_min` ok
- `ft_atoi` ok
- `ft_atoi_base`
- `ft_atol` | `ft_atoll`
- `ft_atol_base` | `ft_atoll_base`
- `ft_exit` ok
### ft_unistd.h
- `ft_write` ok
- `ft_read` ok
- `ft_putchar_fd` ok
- `ft_pustr_fd` ok
- `ft_putnbr_fd` ok | `ft_putnbr_fd_base`
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
- `ft_llist_last` ok
- `ft_llist_push_front` ok
- `ft_llist_size` ok
- `ft_llist_sort` ok
- `ft_llist_remove_if` ok
### ft_dllist.h
- `ft_dllist_new` ok
- `ft_dllist_push_back` ok
- `ft_dllist_push_front` ok
- `ft_dllist_clear` ok
- `ft_dllist_rclear` ok
- `ft_dllist_free` ok
- `ft_dllist_rfree` ok
- `ft_dllist_iter` ok
- `ft_dllist_riter` ok
- `ft_dllist_last` ok
- `ft_dllist_size` ok
- `ft_dllist_rsize` ok
### ft_fcntl.h
- `ft_open`
- `ft_close`
- `ft_fopen`
- `ft_fclose`
### ft_errno.h - ok
- `ft_strerror` ok
### ft_limits.h
### ft_signal.h
### ft_stdbool.h
### ft_stddef.h
### MutantStack.hpp - ok

## TODO:
Documentation generator/extractor, man pages, Continuous integration, unit testing
