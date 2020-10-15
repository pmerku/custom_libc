---
layout: default
title: ft_unistd
parent: Home
nav_order: 13
---

## \#include <ft_unistd.h>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### ft_putchar_fd
This function writes a character into the chosen file descriptor.

```c
/*
 * Write a character to output fd
 * 
 * @param1  char character to write
 * @param2  int  file descriptor to write to
 * @return  void no return
 */
void	ft_putchar_fd(char c, int fd)
```

### ft_putendl_fd
This function writes a string into the chosen file descriptor and adds a new line at the end.

```c
/*
 * Write a string with a new line to output fd
 * 
 * @param1  char * string to write
 * @param2  int    file descriptor to write to
 * @return  void   no return
 */
void	ft_putendl_fd(char *s, int fd);
```

### ft_putnbr_fd
This function writes an integer into the chosen file descriptor.

```c
/*
 * Write an integer to output fd
 * 
 * @param1  int  number to write
 * @param2  int  file descriptor to write to
 * @return  void no return
 */
void	ft_putnbr_fd(int n, int fd);
```

### ft_putstr_fd
This function writes a string into the chosen file descriptor.

```c
/*
 * Write a string to output fd
 * 
 * @param1  char * string to write
 * @param2  int    file descriptor to write to
 * @return  void   no return
 */
void	ft_putstr_fd(char *s, int fd);
```

### ft_read
`ft_read()` attempts to read up to `nbyte` bytes from file descriptor `fd` into the buffer starting at `buf`.
On success, the number of bytes read is returned (zero indicates end of file), and the file position
is advanced by this number. On error, -1 is returned, and `errno` is set appropriately.

```c
/*
 * Read nbytes from file descriptor and store
 * the read bytes inside the buffer buf
 * 
 * @param1  int     file descriptor to read
 * @param2  void *  buffer to store read bytes
 * @param3  size_t  number of bytes to read
 * @return  ssize_t number of bytes read
 */
extern ssize_t	ft_read(int fd, void *buf, size_t nbyte);
```

### ft_write
`ft_write()` writes up to `nbytes` bytes from the buffer starting at `buf` to the file referred to by
the file descriptor `fd`.
On success, the number of bytes written is returned. On error, -1 is returned, and `errno` is
set to indicate the cause of the error.

```c
/*
 * Write nbytes from buffer to a file descriptor
 * 
 * @param1  int          file descriptor where to write
 * @param2  const void * buffer where bytes to write are stored
 * @param3  size_t       number of bytes to write
 * @return  ssize_t      number of written bytes
 */
extern ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
```
