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
#include <ft_stdio/ft_printf.h>

/*
 * Allocate memory of size, exits the program on
 * error
 *
 * @param   size_t size to allocate
 * @return  void * pointer to the allocated memory
 */
void		*ft_checked_malloc(size_t n) {
	void *data = ft_malloc(n);
	if (data == NULL) {
		ft_eprintf(1, "Checked malloc failed\n");
	}
	return (data);
}
