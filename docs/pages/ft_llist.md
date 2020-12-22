---
layout: default
title: ft_llist
parent: Home
nav_order: 6
---

## \#include \<ft_llist.h\>
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### Structure
The data structure of my linked list.

```c
/*
** Private struct - don't use.
*/
typedef struct			s_llist_node {
	void				*data;
	struct s_llist_node	*next;
}						t_llist_node;

typedef struct			s_llist {
	void				(*del_fn)(void *);
	t_llist_node		*head;
}						t_llist;
```

### ft_llist_new
Allocates a new node that can be added to an existent linked list.

```c
/*
 * Creates a new linked list node
 * 
 * @param  void *    pointer to a void function that gets as parameter a memory pointer
 * @return t_llist * pointer to the allocated node
 */
t_llist *ft_llist_new(void (*del_fn)(void *));
```

### ft_llist_push_front
Allocates a new node and sets it as head of the current linked list.

```c
/*
 * Allocate a new node and set it as head of linked list
 * 
 * @param1 t_llist * pointer to the linked list
 * @param2 void *    pointer to the data that will be stored in the node
 * @return void
 */
void ft_llist_push_front(t_llist *lst, void *data);
```

### ft_llist_push_back
Allocates a new node and sets it as tail of the current linked list.

```c
/*
 * Allocate a new node and set it as tail of linked list
 * 
 * @param1 t_llist * pointer to the linked list
 * @param2 void *    pointer to the data that will be stored in the node
 * @return void
 */
void ft_llist_push_back(t_llist *lst, void *data);
```

### ft_llist_size
Counts number of elements in the linked list.

```c
/*
 * Count elements in the linked list
 * 
 * @param  t_llist * pointer to the list to count
 * @return int       number of elements
 */
int ft_llist_size(t_llist *lst);
```

### ft_llist_last
Returns the pointer to the last element of the linked list.

```c
/*
 * Get last element in linked list
 * 
 * @param  t_llist *      pointer to the linked list
 * @return t_llist_node * pointer to the element in the linked list
 */
t_llist_node *ft_llist_last(t_llist *lst);
```

### ft_llist_free
Frees the memory allocated to the linked list and sets the list to `NULL`.

```c
/*
 * Frees the linked list
 * 
 * @param  t_llist **lst pointer to the linked list
 * @return void
 */
void ft_llist_free(t_llist **lst);
```

### ft_llist_clear
Clear the linked list, not setting the list to `NULL`, but removing all entries.

```c
/*
 * Clears the linked list
 * 
 * @param  t_llist * pointer to the linked list
 * @return void
 */
void ft_llist_clear(t_llist *lst);
```

### ft_llist_iter
Iterate through a linked list and apply the function to each of it's elements data.

```c
/*
 * Iterate through the list and apply the function to the elements
 * of the list
 * 
 * @param1 t_llist * pointer to the linked list
 * @param2 void *    pointer to the function that gets as parameter a memory pointer
 */
void ft_llist_iter(t_llist *lst, void (*f)(void *));
```