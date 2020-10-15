---
layout: default
title: ft_errno
parent: Home
nav_order: 4
---

## \#include \<ft_errno.h\>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### g_errno
Global integer error value. Set to 0 by default.

```c
/*
 * Error value
 */
extern int		g_errno;
```

### set_errno
Set value of `g_errno` to an error value defined in `ft_errno.h`

```c
/*
 * Set g_errno value
 * 
 * @param  int  error value
 * @return void no return
 */
void	set_errno(int errno_value);
```

### get_errno
Get value of `g_error`

```c
/*
 * Get value of g_errno
 * 
 * @param  void
 * @return int  value of g_errno
 */
int     get_errno(void);
```

### ft_strerror
The `ft_strerror()` function returns a pointer to a string that describes the error code
passed in the argument `errno_value`.
If `errno_value` is unknown, the string `"Unknown error"` will be returned instead.

```c
/*
 * Get error string message
 * 
 * @param  int    error value
 * @return char * message string
 */
char    *ft_strerror(int errno_value);
```
