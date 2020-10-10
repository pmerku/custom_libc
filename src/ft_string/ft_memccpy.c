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

void	*ft_memccpy(void *dst, const void *src, int c, size_t n) {
	if (n) {
		unsigned char		*d = (unsigned char*)dst;
		const unsigned char	*s = (const unsigned char*)src;
		while (n--) {
			*d++ = *s++;
			if (*d == (unsigned char)c) { //TODO test this
				return (d + 1);
			}
		}
	}
	return (NULL);
}
