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
#include <ft_stdio/ft_printf.h>

/*
 * Check if pointer points to allocated memory, exits
 * program if pointer points to NULL
 *
 * @param   void * pointer to check
 * @return  void * pointer to check
 */
void	*ft_nullcheck(void *data) {
	if (data == NULL) {
		ft_eprintf(1, "Error\nData null-check failed (got null, data expected)\n");
	}
	return (data);
}
