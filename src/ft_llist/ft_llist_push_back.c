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

#include <ft_llist.h>
#include <ft_memory.h>

void	ft_llist_push_back(t_llist *lst, void *data) {
	ft_nullcheck(lst);
	t_llist_node *node = ft_malloc(sizeof(t_llist_node));
	node->data = data;
	node->next = NULL;
	if (lst->head == NULL) {
		lst->head = node;
	}
	else {
		t_llist_node *iter = lst->head;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = node;
	}
}
