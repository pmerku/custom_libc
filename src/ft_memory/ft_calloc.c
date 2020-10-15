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

#include <limits.h>
#include <stddef.h>
#include <ft_memory.h>

/*
 * Allocate a zeroed array of count * size
 *
 * @param1  size_t count of elements
 * @param2  size_t size of elements
 * @return  void * pointer to the allocated memory
 */
void	*ft_calloc(size_t count, size_t size) {
	size_t value = count * size;
	if (value > INT_MAX) {
		return (NULL);
	}
	void *mem = ft_malloc(value);
	if (!mem) {
		return (NULL);
	}
	ft_bzero(mem, value);
	return (mem);
}
