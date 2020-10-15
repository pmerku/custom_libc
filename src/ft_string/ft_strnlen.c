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
 * Get size of string in max n bytes
 *
 * @param1  const char * string to calculate size
 * @param2  size_t       max number of bytes to look
 * @return  size_t       calculated size
 */
size_t	ft_strnlen(const char *s, size_t n) {
	size_t	len = 0;
	while (len < n) {
		if (!*s)
			break ;
		len++;
		s++;
	}
	return (len);
}
