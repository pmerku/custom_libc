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

#include <ft_memory.h>
#include <ft_string.h>

void	*ft_realloc(void *ptr, size_t size) {
	size_t	old_size = ft_getsize(ptr);
	if (size == 0) {
		ft_free(ptr);
		return (NULL);
	}
	else if (size <= old_size) {
		return (ptr);
	}
	else {
		void *new_ptr = ft_malloc(size);
		if (new_ptr) {
			ft_memcpy(new_ptr, ptr, old_size);
			ft_free(ptr);
		}
		return (new_ptr);
	}
}
