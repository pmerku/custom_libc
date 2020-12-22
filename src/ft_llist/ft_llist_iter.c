/* ************************************************************************** */
/*                                                                            */
/*   Project: custom_libc                                 ::::::::            */
/*   Members: dvoort, prmerku                           :+:    :+:            */
/*   Copyright: 2020                                   +:+                    */
/*                                                    +#+                     */
/*                                                   +#+                      */
/*                                                  #+#    #+#                */
/*   while (!(succeed = try()));                   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_llist.h>

/*
 * Iterate through the list and apply the function to the elements
 * of the list
 *
 * @param1 t_llist * pointer to the linked list
 * @param2 void *    pointer to the function that gets as parameter a memory pointer
 */
void	ft_llist_iter(t_llist *lst, void (*f)(void *)) {
	t_llist_node *node = lst->head;
	while (node != NULL) {
		f(node->data);
		node = node->next;
	}
}
