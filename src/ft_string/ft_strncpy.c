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
 * Copy at most n bytes from src string to dst buffer
 *
 * @param1  char *       string where to copy
 * @param2  const char * string to copy
 * @param3  size_t       number of bytes to copy
 * @return  char *       pointer to dst string
 */
char	*ft_strncpy(char *dest, const char *src, size_t n) {
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	for ( ; i < n; i++) {
		dest[i] = '\0';
	}
	return (dest);
}