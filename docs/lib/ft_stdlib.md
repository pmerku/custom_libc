---
layout: default
title: ft_stdlib
parent: Home
nav_order: 11
---

## \#include <ft_stdlib.h>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### ft_abs
Get the absolute value of an integer.

```c
/*
 * Get absolute value of an integer
 * 
 * @param   int number to use
 * @return  int absolute value
 */
int     ft_abs(int n);
```

### ft_atoi
Convert a character array into an integer.

```c
/*
 * Convert a character array into an integer
 * 
 * @param   const char * array to convert
 * @return  int          converted integer
 */
int		ft_atoi(const char *str);
```

### ft_dabs
Get the absolute value of a double.

```c
/*
 * Get absolute value of a double
 * 
 * @param   double number to use
 * @return  double absolute value
 */
double	ft_dabs(double n);
```

### ft_exit
Exits the program with a provided exit code.

```c
/*
 * Exit the program with a provided exit code
 * 
 * @param   int  exit code
 * @return  void no return
 */
extern void    ft_exit(int status);
```

### ft_max.c
Get the bigger number out of two numbers. If the numbers are
equal, the second number will be returned.

```c
/*
 * Get the bigger number
 * 
 * @param1  int number 1
 * @param2  int number 2
 * @return  int the bigger number
 */
int     ft_max(int a, int b);
```

### ft_min.c
Get the smaller number out of two numbers. If the numbers are
equal, the second number will be returned.

```c
/*
 * Get the smaller number
 * 
 * @param1  int number 1
 * @param2  int number 2
 * @return  int the smaller number
 */
int     ft_min(int a, int b);
```
