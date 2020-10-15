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
 * Find substring inside string, search for max n bytes
 *
 * @param1  const char * string where to search
 * @param2  const char * string to find
 * @param3  size_t       max number of bytes to search
 * @return  char *       pointer to the beginning of needle
 */
char	*ft_strnstr(const char *haystack, const	char *needle, size_t len) {
	size_t pos = 0;
	size_t nlen = ft_strlen(needle);
	if (nlen == 0) {
		return ((char *) haystack);
	}
	while (haystack[pos] != '\0') {
		if (pos + nlen > len) {
			return (NULL);
		}
		if (ft_strncmp(haystack + pos, needle, nlen) == 0) {
			return ((char *) haystack + pos);
		}
		pos++;
	}
	return (NULL);
}
