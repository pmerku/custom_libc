---
layout: default
title: ft_string
parent: Home
nav_order: 12
---

## \#include \<ft_string.h\>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### ft_memccpy
The `ft_memccpy()` function copies no more than `n` bytes from memory area `src` to memory area `dest`,
stopping when the character `c` is found.
If the memory areas overlap, the results are undefined.
The `ft_memccpy()` function returns a pointer to the next character in `dest` after `c`, or `NULL`
if `c` was not found in the first `n` characters of `src`.

```c
/*
 * Copy no more than n bytes from the src memory to the dest area
 * stopping when the character c is found
 * 
 * @param1  void *       pointer to the dest memory
 * @param2  const void * pointer to the src memory
 * @param3  int          character value
 * @param4  size_t       max bytes to copy
 * @return  void *       pointer to the next character in dest after c
 */
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
```

### ft_memchr
The `ft_memchr()` function scans the initial `n` bytes of the memory area pointed to by `s` for the
first instance of `c`. Both `c` and the bytes of the memory area pointed to by `s` are
interpreted as `unsigned char`.
The `ft_memchr()` function returns a pointer to the matching byte or `NULL` if the character
does not occur in the given memory area.

```c
/*
 * Find occurance of character c in no more than n bytes
 * in the memory pointer
 * 
 * @param1  const void * pointer to memory to search
 * @param2  size_t       max bytes to search
 * @return  void *       pointer 
 */
extern void     *ft_memchr(const void *s, int c, size_t n);
```

### ft_memcmp
The `ft_memcmp()` function compares the first `n` bytes (each interpreted as `unsigned char`) of
the memory areas `s1` and `s2`.
The function returns an integer less than, equal to, or greater than zero if the first `n` bytes of `s1`
is found, respectively, to be less than, to match, or be greater than the first `n` bytes of `s2`.
For a nonzero return value, the sign is determined by the sign of the difference between the first pair of
bytes (interpreted as `unsigned char`) that differ in `s1` and `s2`.
If `n` is zero, the return value is zero.

```c
/*
 * Compare at max n bytes in two memory areas
 * 
 * @param1  const void * memory area 1
 * @param2  const void * memory area 2
 * @param3  size_t       max number of bytes to compare
 * @return  int          difference of comparison
 */
int     ft_memcmp(const	void *s1, const	void *s2, size_t n);
```

### ft_memcpy
The function copies `n` bytes from memory area `src` to memory area `dst`. 
The memory areas must not overlap, use `ft_memmove` in that case.
The function returns a pointer to `dst`.

```c
/*
 * Copy n bytes from src into dst
 * 
 * @param1  void *       dst memory area
 * @param2  const void * src memory area
 * @param3  size_t       number of bytes to copy
 * @return  void *       pointer to dst
 */
extern void     *ft_memcpy(void *dst, const void *src, size_t n);
```

### ft_memmove
The function copies `n` bytes from memory area `src` to memory area `dst`.
The memory areas may overlap: copying takes place in reverse.
The function returns a pointer to `dst`.

```c
/*
 * Copy n bytes from src into dst
 * 
 * @param1  void *       dst memory area
 * @param2  const void * src memory area
 * @param3  size_t       number of bytes to copy
 * @return  void *       pointer to dst
 */
void    *ft_memmove(void *dst, const void *src, size_t len);
```

### ft_memset
The function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c`.
The function returns a pointer to the memory area `s`.

```c
/*
 * Set n bytes in s to the character c
 * 
 * @param1  void * pointer to memory to fill
 * @param2  int    character value
 * @param3  size_t number of bytes to set
 * @return  void * pointer to filled memory
 */
void	*ft_memset(void *s, int c, size_t n);
```

### ft_strcat
The function appends the `src` string to the `dst` string, overwriting the terminating null byte ('\0')
at the end of `dst`, and then adds a terminating null byte. The strings may not overlap, and the `dst` string
must have enough space for the result. If `dst` is not large enough, program behavior is unpredictable.
The function returns a pointer to the resulting string `dst`.

```c
/*
 * Append src string to dst string
 * 
 * @param1  char *       string where to append
 * @param2  const char * string to append
 * @return  char *       pointer to dst
 */
extern char     *ft_strcat(char *dst, const char *src);
```

### ft_strncat
The function appends the at most `n` bytes from `src` string to the `dst` string,
overwriting the terminating null byte ('\0') at the end of `dst`, and then adds a
terminating null byte. The strings may not overlap, and the `dst` string must have enough
space for the result. If `src` contains `n` or more bytes, `ft_strncat()` writes `n+1` bytes
to `dst` (`n` from `src` plus the terminating null byte). 
Therefore, the size of `dst` must be at least `ft_strlen(dest)+n+1`.
The function returns a pointer to the resulting string `dst`.

```c
/*
 * Append at most n bytes from src to dst string
 * 
 * @param1  char *       string where to append
 * @param2  const char * string to append
 * @param3  size_t       number of bytes to append
 * @return  char *       pointer to dst
 */
char	*ft_strncat(char *dst, const char *src, size_t n);
```

### ft_strlcat
This function appends the null-terminated string `src` to the string `dst`,
copying at most `size - ft_strlen(dst) - 1` from `src`, and adds a terminating null
byte to the result, unless `size` is less than `ft_strlen(dst)`.
The function returns the length of the string `ft_strlcat()` tried to create; if the
return value is greater than or equal to `size`, data loss occurred.

```c
/*
 * Append at most size bytes of src string to 
 * dst string and return size of new dst string
 * 
 * @param1  char *       string where to append
 * @param2  const char * string to append
 * @param3  size_t       number of bytes to append
 * @return  size_t       size of new dst
 */
size_t  ft_strlcat(char *dst, const char *src, size_t size);
```

### ft_strchr
The function returns a pointer to the first occurrence of the character `c` in the string `s`.
If character is not found or `s` is empty then `NULL` is returned.

```c
/*
 * Find first occurrence of c in s
 * 
 * @param1  const char * string to search
 * @param2  int          character to find
 * @return  char *       pointer to the matched character
 */
extern char    *ft_strchr(const char *s, int c);
```

### ft_strrchr
The function returns a pointer to the last occurrence of the character `c` in the string `s`.
If character is not found or `s` is empty then `NULL` is returned.

```c
/*
 * Find last occurrence of c in s
 * 
 * @param1  const char * string to search
 * @param2  int          character to find
 * @return  char *       pointer to the matched character
 */
char    *ft_strrchr(const char *s, int c);
```

### ft_strcmp
The function compares the two strings `s1` and `s2`. It returns an integer less than,
equal to, or greater than zero if `s1` is found, respectively, to be less than,
to match, or be greater than `s2`.

```c
/*
 * Compare two string
 * 
 * @param1  const char * first string to compare
 * @param2  const char * second string to compare
 * @return  int          comparison difference
 */
extern int      ft_strcmp(const char *s1, const char *s2);
```

### ft_strncmp
The function compares `n` bytes of the two strings `s1` and `s2`. It returns an integer less than,
equal to, or greater than zero if `s1` is found, respectively, to be less than,
to match, or be greater than `s2`.

```c
/*
 * Compare n bytes of two strings
 * 
 * @param1  const char * first string to compare
 * @param2  const char * second string to compare
 * @param3  size_t       number of bytes to compare
 * @return  int          comparison difference
 */
int     ft_strncmp(const char *s1, const char *s2, size_t n);
```

### ft_strcpy
The function copies the string pointed to by `src`, including the terminating null byte ('\0'), to the
buffer pointed to by `dst`. The strings may not overlap, and the destination string `dst` must be large enough
to receive the copy.
The function returns a pointer to the destination string `dst`.

```c
/*
 * Copy src string to dst buffer
 * 
 * @param1  char *       string where to copy
 * @param2  const char * string to copy
 * @return  char *       pointer to dst string
 */
extern char     *ft_strcpy(char *dst, const char *src);
```

### ft_strncpy
The function copies at most `n` bytes from string pointed to by `src`, including the
terminating null byte ('\0'), to the buffer pointed to by `dst`. The strings may not overlap,
and the destination string `dst` must be large enough to receive the copy.
If the length of `src` is less than `n`, `ft_strncpy()` writes additional null bytes to `dst` to
ensure that a total of `n` bytes are written.
The function returns a pointer to the destination string `dst`.

```c
/*
 * Copy at most n bytes from src string to dst buffer
 * 
 * @param1  char *       string where to copy
 * @param2  const char * string to copy
 * @param3  size_t       number of bytes to copy
 * @return  char *       pointer to dst string
 */
char	*ft_strncpy(char *dest, const char *src, size_t n);
```

### ft_strlcpy
This function is similar to `ft_strncpy()`, but it copies at most `size - 1` bytes to `dst`,
always adds a terminating null byte, and does not pad the destination with (further) null bytes.
The return value of the function is the length of `src`, which allows truncation to be easily  detected:
if the return value is greater than or equal to size, truncation occurred.

```c
/*
 * Copy at most n bytes from src string to dst buffer and
 * return size of new dst string
 * 
 * @param1  char *       string where to copy
 * @param2  const char * string to copy
 * @param3  size_t       number of bytes to copy
 * @return  size_t       size of new dst string
 */
size_t 	ft_strlcpy(char *dst, const char *src, size_t size);
```

### ft_strdup
The function returns a pointer to a new string which is a duplicate of the string `s`. Memory for the
new string is obtained with `ft_malloc()`, and can be freed with `ft_free()`.
On allocation error, `NULL` is returned.

```c
/*
 * Duplicate and allocate a new string
 * 
 * @param   const char * string to duplicate
 * @return  char *       pointer to new allocated string
 */
extern char		*ft_strdup(const char *s);
```

### ft_strlen
The `ft_strlen()` function returns the number of bytes in the string pointed to by `s`,
excluding the terminating null byte ('\0').

```c
/*
 * Get size of string
 * 
 * @param   const char * string to calculate size
 * @return  size_t       calculated size
 */
extern size_t	ft_strlen(const char *s);
```

### ft_strnlen
The function returns `ft_strlen(s)`, if that is less than `n`, or `n` if there is no
null terminating ('\0') among the first `n` characters pointed to by `s`.

```c
/*
 * Get size of string in max n bytes
 * 
 * @param1  const char * string to calculate size
 * @param2  size_t       max number of bytes to look
 * @return  size_t       calculated size
 */
size_t  ft_strnlen(const char *s, size_t n);
```

### ft_strnstr
The `ft_strnstr()` function finds the first occurrence of the substring `needle` in at max `n` bytes
of the string `haystack`. The terminating null bytes ('\0') are not compared.
The function returns a pointer to the beginning of the located substring, or `NULL` if the substring is not
found.

```c
/*
 * Find substring inside string, search for max n bytes
 * 
 * @param1  const char * string where to search
 * @param2  const char * string to find
 * @param3  size_t       max number of bytes to search
 * @return  char *       pointer to the beginning of needle
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
```
