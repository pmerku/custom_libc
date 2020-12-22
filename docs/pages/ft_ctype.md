---
layout: default
title: ft_ctype
parent: Home
nav_order: 2
---

## \#include \<ft_ctype.h\>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### ft_isalnum
Checks for an alphanumeric character; it is equivalent to `(ft_isalpha(c) || ft_isdigit(c))`.
The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

```c
/*
 * Check if character is alphanumerical
 *
 * @param   int character value
 * @return  int 1 if true and 0 if false
 */
int     ft_isalnum(int c);
```

### ft_isalpha
Checks for an alphabetic character; in the standard "C" locale, it is equivalent to `(ft_isupper(c) || ft_islower(c))`.
In some locales, there may be additional characters for  which  `ft_isalpha()`  is  true—letters which are neither 
uppercase nor lowercase.
The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

```c
/*
 * Check if character is alphabetical
 *
 * @param   int character value
 * @return  int 1 if true and 0 if false
 */
int     ft_isalpha(int c);
```

### ft_isascii
Checks whether `c` is a 7-bit unsigned char value that fits into the ASCII character set.
The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

```c
/*
 * Check if character is part of the ASCII table
 *
 * @param   int character value
 * @return  int 1 if true and 0 if false
 */
int     ft_isascii(int c);
```

### ft_isdigit
Checks for a digit (0 through 9).
The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

```c
/*
 * Check if character is a digit
 *
 * @param   int character value
 * @return  int 1 if true and 0 if false
 */
int     ft_isdigit(int c);
```

### ft_islower
Checks for a lowercase character.
The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

```c
/*
 * Check if character is lowercase
 *
 * @param   int character value
 * @return  int 1 if true and 0 if false
 */
int     ft_islower(int c);
```

### ft_isprint
Checks for any printable character including space.
The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

```c
/*
 * Check if character is printable
 *
 * @param   int character value
 * @return  int 1 if true and 0 if false
 */
int     ft_isprint(int c);
```

### ft_isspace
Checks for white-space characters. In the "C" and "POSIX" locales, these are: space, form-feed ('\f'),
newline ('\n'), carriage return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').
The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

```c
/*
 * Check if character is a white-space
 *
 * @param   int character value
 * @return  int 1 if true and 0 if false
 */
int     ft_isspace(int c);
```

### ft_isupper
Checks for an uppercase letter.
The values returned are nonzero if the character `c` falls into the tested class, and zero if not.

```c
/*
 * Check if character is uppercase
 *
 * @param   int character value
 * @return  int 1 if true and 0 if false
 */
int     ft_isupper(int c);
```

### ft_tolower
If `c` is an uppercase letter, `ft_tolower()` returns its lowercase equivalent.
The value returned is that of the converted letter, or `c` if the conversion was not possible.

```c
/*
 * Convert char to lowercase
 *
 * @param   int character value
 * @return  int value of converted char
 */
int     ft_tolower(int c);
```

### ft_toupper
If `c` is an lowercase letter, `ft_toupper()` returns its uppercase equivalent.
The value returned is that of the converted letter, or `c` if the conversion was not possible.

```c
/*
 * Convert char to uppercase
 *
 * @param   int character value
 * @return  int value of converted char
 */
int     ft_toupper(int c);
```
