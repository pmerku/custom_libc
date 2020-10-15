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

/*
 * Get size of allocated memory
 *
 * @param   void * pointer to allocated memory
 * @return  size_t size of allocated memory
 */
size_t	ft_getsize(void *ptr) {
	size_t *data = ptr;
	if (data) {
		data--;
		return *data;
	}
	return 0;
}
