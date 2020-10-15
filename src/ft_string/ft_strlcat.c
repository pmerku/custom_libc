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

size_t		ft_strlcat(char *dst, const char *src, size_t size) {
	size_t dlen = ft_strlen(dst);
	size_t slen = ft_strlen(src);
	if (size == 0) {
		return (slen);
	}
	if (size < dlen) {
		slen = slen + size;
	}
	else {
		slen = slen + dlen;
	}
	size_t i = 0;
	while (src[i] != '\0' && dlen < size - 1 && dst != src) {
		dst[dlen] = src[i];
		i++;
		dlen++;
	}
	if (dlen <= size) {
		dst[dlen] = '\0';
	}
	return (slen);
}
