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
 * Append at most n bytes from src to dst string
 *
 * @param1  char *       string where to append
 * @param2  const char * string to append
 * @param3  size_t       number of bytes to copy
 * @return  char *       pointer to dst
 */
char	*ft_strncat(char *dst, const char *src, size_t n) {
	size_t dst_len = ft_strlen(dst);
	size_t i;
	for (i = 0 ; i < n && src[i] != '\0' ; i++) {
		dst[dst_len + i] = src[i];
	}
	dst[dst_len + i] = '\0';

	return (dst);
}
