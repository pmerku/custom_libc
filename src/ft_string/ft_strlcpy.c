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
 * Copy at most n bytes from src string to dst buffer and
 * return size of new dst string
 *
 * @param1  char *       string where to copy
 * @param2  const char * string to copy
 * @param3  size_t       number of bytes to copy
 * @return  size_t       size of new dst string
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t size) {
	if (!dst || !src) {
		return (0);
	}
	size_t slen = ft_strlen(src);
	if (slen + 1 < size) {
		ft_memcpy(dst, src, slen + 1);
	}
	else if (size != 0) {
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (slen);
}
