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

#include <stdlib.h>

/*
 * Free allocated memory
 *
 * @param   void * pointer to allocated memory
 * @return  void * NULL is returned
 */
void	*ft_free(void *ptr) {
	size_t	*data = ptr;
	if (data) {
		data--;
		free(data);
	}
	return (NULL);
}
