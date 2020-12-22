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
 * Count elements in the linked list
 *
 * @param  t_llist * pointer to the list to count
 * @return int       number of elements
 */
int		ft_llist_size(t_llist *lst) {
	int i = 0;
	t_llist_node *node = lst->head;
	while (node != NULL) {
		node = node->next;
		i++;
	}
	return (i);
}
