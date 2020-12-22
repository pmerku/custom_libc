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
 * Get last element in linked list
 *
 * @param  t_llist *      pointer to the linked list
 * @return t_llist_node * pointer to the element in the linked list
 */
t_llist_node	*ft_llist_last(t_llist *lst) {
	if (lst->head == NULL) {
		return NULL;
	}
	t_llist_node	*node = lst->head;
	while (node != NULL) {
		node = node->next;
	}
	return (node);
}
