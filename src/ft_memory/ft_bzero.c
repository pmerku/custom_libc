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
#include <ft_string.h>

/*
 * Zero out `n` bytes in an array
 *
 * @param1  void * array to zero out
 * @param2  size_t number or bytes
 * @return  void   no return
 */
void	ft_bzero(void *s, size_t n) {
	ft_memset(s, '\0', n);
}
