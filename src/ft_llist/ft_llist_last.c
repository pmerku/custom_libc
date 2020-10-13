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
