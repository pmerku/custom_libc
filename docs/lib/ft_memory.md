---
layout: default
title: ft_memory
parent: Home
nav_order: 8
---

## \#include <ft_memory.h>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### ft_bzero
Erase `n` bytes of the memory in an array, by writing zeros
(bytes containing '\0') to that area.

```c
/*
 * Zero out `n` bytes in an array
 * 
 * @param1  void * array to zero out
 * @param2  size_t number or bytes
 * @return  void   no return
 */
void	ft_bzero(void *s, size_t n);
```

### ft_calloc
Allocates memory for an array of `count` elements of `size` bytes each and 
returns a pointer to the allocated memory. The memory is set to zero. If `count`
or `size` is 0, then `ft_calloc()` returns either `NULL`, or a unique pointer value than
can later be successfully passed to `ft_free()`. If the multiplication of `count` and `size`
would result in integer overflow or an allocation error occurs, `NULL` is returned.

```c
/*
 * Allocate a zeroed array of count * size
 * 
 * @param1  size_t count of elements
 * @param2  size_t size of elements
 * @return  void * pointer to the allocated memory
 */
void	*ft_calloc(size_t count, size_t size);
```

### ft_checked_calloc
Allocates memory for an array of `count` elements of `size` bytes each and 
returns a pointer to the allocated memory. The memory is set to zero. If `count`
or `size` is 0, then `ft_calloc()` returns either `NULL`, or a unique pointer value than
can later be successfully passed to `ft_free()`. If the multiplication of `count` and `size`
would result in integer overflow or an allocation error occurs an error message is sent to 
the user and the program exits.

```c
/*
 * Allocate a zeroed array of count * size, exits
 * the program on error
 * 
 * @param1  size_t count of elements
 * @param2  size_t size of elements
 * @return  void * pointer to the allocated memory
 */
void	*ft_checked_calloc(size_t count, size_t size)
```

### ft_checked_malloc
Allocates memory for an array of `size` bytes and 
returns a pointer to the allocated memory.
On allocation error an error message is sent to the
user and the program exits.

```c
/*
 * Allocate memory of size, exits the program on 
 * error
 * 
 * @param   size_t size to allocate
 * @return  void * pointer to the allocated memory
 */
void    *ft_checked_malloc(size_t size);
```

### ft_free
The `ft_free()` function frees the memory space pointed to by ptr, which must have been returned by a 
previous call to `ft_malloc()`, `ft_calloc()`, or `ft_realloc()`.  Otherwise, or if `ft_free(ptr)` 
has already been called before, undefined behavior occurs. 
If `ptr` is `NULL`, no operation is performed. `NULL` is always returned.

```c
/*
 * Free allocated memory
 * 
 * @param   void * pointer to allocated memory
 * @return  void * NULL is returned
 */
void	*ft_free(void *ptr);
```

### ft_free_array
The `ft_free_array()` function frees a 2d sized array, deeply.
`NULL` is always returned.

```c
/*
 * Free allocated 2d array
 * 
 * @param   void ** pointer to the 2d allocated array
 * @return  void ** NULL is returned
 */
char	**ft_free_array(char **arr);
```

### ft_getsize

```c
/*
 * Get size of allocated memory
 * 
 * @param   void * pointer to allocated memory
 * @return  size_t size of allocated memory
 */
size_t  ft_getsize(void *ptr);
```

### ft_malloc
Allocates memory for an array of `size` bytes and 
returns a pointer to the allocated memory.
On allocation error, `NULL` is returned.

```c
/*
 * Allocate memory of size
 * 
 * @param   size_t size to allocate
 * @return  void * pointer to the allocated memory
 */
void    *ft_malloc(size_t size);
```

### ft_nullcheck
Checks if a pointer points to allocated memory. If no error occurs the checked
pointer is returned.
On error an error message is sent to the user and the program exits.

```c
/*
 * Check if pointer points to allocated memory, exits
 * program if pointer points to NULL
 * 
 * @param   void * pointer to check
 * @return  void * pointer to check
 */
void	*ft_nullcheck(void *data);
```

### ft_realloc
The `ft_realloc()` function changes the size of the memory block pointed
to by `ptr` to `size` bytes. The contents will be unchanged in the range from
the start of the region up to the minimum of the old and new sizes. If the new size is 
larger than the old size, the added memory will not be initialized. 
If ptr is `NULL`, then the call is equivalent to `ft_malloc(size)`, for all values of size;
if `size` is equal to zero, and `ptr` is not `NULL`, then the call is equivalent 
to `ft_free(ptr)`. Unless `ptr` is `NULL`, it must have been returned by an earlier call
to `ft_malloc()`, `ft_calloc()`, or `ft_realloc()`. If the area pointed to was
moved, a `ft_free(ptr)` is done.

```c
/*
 * Reallocate memory to new size
 * 
 * @param1  void * pointer to allocate memory to reallocate
 * @param2  size_t size of new allocation
 * @return  void * pointer to reallocated memory
 */
void	*ft_realloc(void *ptr, size_t size);
```
