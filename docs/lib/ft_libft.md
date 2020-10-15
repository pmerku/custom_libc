---
layout: default
title: ft_libft
parent: Home
nav_order: 5
---

## \#include \<ft_libft.h\>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### ft_intlen
Get length of number by counting digits of the number.

```c
/*
 * Get length of number
 * 
 * @param   int number to count
 * @return  int length of number
 */
int     ft_intlen(int n);
```

### ft_intlen_base
Get length of number in specific base by counting digits of the number.
Supported bases are from base 2 - to including base 16.

```c
/*
 * Get length of number
 * 
 * @param1   int number to count
 * @param2   int base to use
 * @return   int length of number
 */
int     ft_intlen_base(int n, int base);
```

### ft_itoa
Convert integer to a character string.
If allocation fails `NULL` is returned.

```c
/*
 * Convert integer to string
 * 
 * @param   int    number to convert
 * @return  char * number in a string
 */
char    *ft_itoa(int n);
```

### ft_itoa_base
Convert integer in a specific base to a character string 
Supported bases are from base 2 - to including base 16.
If allocation fails `NULL` is returned.

```c
/*
 * Convert integer to string
 * 
 * @param1  int    number to convert
 * @param2  int    base to use
 * @return  char * number in a string
 */
char    *ft_itoa_base(int n, int base);
```

### ft_nsplit
Split a character array into a 2d array. The splits happen on the
character delimiter. `ft_split` will split the array until the array
to split ends.
On error `NULL` is returned.

```c
/*
 * Split a character array based on a delimiter, until the
 * end of the array.
 * 
 * @param1  const char * array to split
 * @param2  char         delimiter to split on
 * @return  char **      2d sized array
 */
char	**ft_split(const char *str, char delim);
```

### ft_nsplit
Split a character array into a 2d array. The splits happen on the
character delimiter. `ft_nsplit` will split the array until the array
to split ends or the number of max splits is reached.
On error `NULL` is returned.

```c
/*
 * Split a character array based on a delimiter, until the
 * end of the array or max number of splits.
 * 
 * @param1  const char * array to split
 * @param2  char         delimiter to split on
 * @param3  int          max number of splits
 * @return  char **      2d sized array
 */
char	**ft_nsplit(const char *str, char delim, int max);
```

### ft_strarr_append
Append a string to an existing 2d sized array.

```c
/*
 * Append a string to a 2d array
 * 
 * @param1  char *** pointer to the array where the string will be appended
 * @param2  char *   string to appen
 * @return  void     no return
 */
void    ft_strarr_append(char ***arr, char *line);
```

### ft_strarr_size
Get the size of a string array.

```c
/*
 * Get size of an array
 * 
 * @param   char ** array to get the size
 * @return  int     size of the array
 */
int		ft_strarr_size(char **arr);
```

### ft_strempty
Create a new empty character array.
On allocation error, `NULL` is returned.

```c
/*
 * Create empty character array
 * 
 * @param   void no argument
 * @return  char * pointer to the new array
 */
char	*ft_strempty(void);
```

### ft_strip_chars
Strip a specific character from a character array.

```c
/*
 * Strip characters away from a character array
 * 
 * @param1  char * character array where to strip
 * @param2  char   character to strip
 * @return  char * the stripped character array
 */
char	*ft_strip_chars(char *str, char c);
```

### ft_strjoin
Join two character arrays into one.
If one of the arrays are empty or an allocation error occurs, `NULL` is returned.

```c
/*
 * Join two character arrays into one
 * 
 * @param1  char const * first character array
 * @param2  char const * second character array
 * @return  char *       new character array
 */
char	*ft_strjoin(char const *s1, char const *s2);
```

### ft_strtrim
Create a new character array without the set of characters.
If the array to trim or the set are empty, `NULL` is returned. 

```c
/*
 * Trim a set out of a character array
 * 
 * @param1  const char * array to trim
 * @param2  const char * set to trim
 * @return  char *       new array without the trimmed set
 */
char	*ft_strtrim(const char *s1, const char *set);
```

### ft_substr
Allocates and returns a substring from the source string. The substring begins at index
`start` and is of maximum size `len`.
If allocation fails, `NULL` is returned.

```c
/*
 * Get a substring out of a character array
 * 
 * @param1  const char * array where to get the substring
 * @param2  unsigned int index where to start the substring
 * @param3  size_t       size of the substring
 * @return  char *       pointer to the substring
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
```

### get_next_line
Read from a file descriptor and store the value of what was read inside the 
argument buffer.
Calling the function in a loop will allow to read the text available on a 
file descriptor one line at a time until the `EOF`.

```c
/*
 * Read from a file descriptor and store the read line without
 * a `\n` at the end
 * 
 * @param1  int     file descriptor for reading
 * @param2  char ** the value of what was read
 * @return  int     1 if a line was read, 0 EOF has been reached and -1 on error
 */
int		get_next_line(int fd, char **line);
```
