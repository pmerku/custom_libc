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
#include <ft_memory.h>
#include <ft_llist.h>

/*
 * Free linked list
 *
 * @param  t_llist **lst pointer to the linked list
 * @return void
 */
void	ft_llist_free(t_llist **lst)
{
	if (*lst == NULL) {
		return;
	}
	t_llist_node *node = (*lst)->head;
	while (node != NULL) {
		t_llist_node *next = node->next;
		(*lst)->del_fn(node->data);
		ft_free(node);
		node = next;
	}
	ft_free(*lst);
	*lst = NULL;
}
