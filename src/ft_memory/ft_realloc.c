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

/*
 * Reallocate memory to new size
 *
 * @param1  void * pointer to allocate memory to reallocate
 * @param2  size_t size of new allocation
 * @return  void * pointer to reallocated memory
 */
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
