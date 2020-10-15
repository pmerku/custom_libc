---
layout: default
title: ft_stdio/ft_printf
parent: Home
nav_order: 10
---

## \#include \<ft_stdio/ft_printf\>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### Format string
The format string of these function follows the rules of the `printf` family. (man 3 printf)

### ft_printf
Write output to STDOUT, the standard output file descriptor.
Upon successful return, `ft_printf` returns the number of characters printed (excluding the null byte used
to end output to strings).
If an output error is encountered, a negative value is returned.

```c
/*
 * Write the output to STDOUT under the control of a format string that specifies how subsequent
 * arguments are converted for output.
 *
 * @param1  const char * format string
 * @param2  ...          variable length argument
 * @return  int          number of printed characters
 */
int     ft_printf(const char *str, ...);
```

### ft_fprintf
Write output to provided file descriptor.
Upon successful return, `ft_fprintf` returns the number of characters printed (excluding the null byte used
to end output to strings).
If an output error is encountered, a negative value is returned.

```c
/*
 * Write the output to `fd` under the control of a format string that specifies how subsequent
 * arguments are converted for output.
 *
 * @param1  int fd       output file descriptor
 * @param2  const char * format string
 * @param3  ...          variable length argument
 * @return  int          number of printed characters
 */
int     ft_fprintf(int fd, const char *str, ...);
```

### ft_vprintf
Write output to STDOUT, and reads arguments from the va_list of another function.
Upon successful return, `ft_vprintf` returns the number of characters printed (excluding the null byte used
to end output to strings).
If an output error is encountered, a negative value is returned.

```c
/*
 * Write the output to STDOUT under the control of a format string that specifies how subsequent
 * arguments are converted for output.
 *
 * @param1  const char * format string
 * @param2  va_list      variable length list
 * @return  int          number of printed characters
 */
int     ft_vprintf(const char *str, va_list arg);
```

### ft_vfprintf
Write output to provided file descriptor, and reads arguments from the va_list of another function.
Upon successful return, `ft_vfprintf` returns the number of characters printed (excluding the null byte used
to end output to strings).
If an output error is encountered, a negative value is returned.

```c
/*
 * Write the output to `fd` under the control of a format string that specifies how subsequent
 * arguments are converted for output.
 *
 * @param1  int          output file descriptor
 * @param2  const char * format string
 * @param3  va_list      variable length list
 * @return  int          number of printed characters
 */
int     ft_vfprintf(int fd, const char *str, va_list arg);
```

### ft_eprintf
Write output to STDERR, exiting the code afterwards.
Upon successful return, `ft_eprintf` returns the number of characters printed (excluding the null byte used
to end output to strings).
If an output error is encountered, a negative value is returned.

```c
/*
 * Write the output to `fd` under the control of a format string that specifies how subsequent
 * arguments are converted for output and exit out the code.
 *
 * @param1  int          exit code
 * @param1  const char * format string
 * @param2  ...          variable length argument
 * @return  int          number of printed characters
 */
int     ft_eprintf(int code, const char *str, ...);
```

### ft_snprintf
Write output to a string. Performs a formatted print, writing to a string. The string will always be
null-terminated. The print will continue running, even if there is no space left in the string.
Characters that do not fit in the string anymore will not be printed, though.
The function `ft_snprintf()` does not write more than `size` bytes (including the terminating  null byte ('\0')).
If the output was truncated due to this limit, then the return value is the number of characters
(excluding the terminating null byte) which would have been written to the final string if enough space
had been available. Thus, a return value of `size` or more means that the output was truncated.
If an output error is encountered, a negative value is returned.

```c
/*
 * Write the output to a string under the control of a format string that specifies how subsequent
 * arguments are converted for output.
 *
 * @param1  char *       output string
 * @param2  size_t       size to print
 * @param3  const char * format string
 * @param4  ...          variable length argument
 * @return  int          number of printed characters
 */
int     ft_snprintf(char *str, size_t size, const char *fmt, ...);
```
