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
#include <stdlib.h>

/*
 * Allocate memory of size
 *
 * @param   size_t size to allocate
 * @return  void * pointer to the allocated memory
 */
void	*ft_malloc(size_t n) {
	size_t *data = malloc((1 * sizeof(size_t)) + n);
	if (data) {
		*data = n;
		data++;
	}
	return (data);
}
