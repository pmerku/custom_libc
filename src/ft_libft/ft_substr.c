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
#include <ft_libft.h>
#include <ft_string.h>
#include <ft_memory.h>

/*
 * Get a substring out of a character array
 *
 * @param1  const char * array where to get the substring
 * @param2  unsigned int index where to start the substring
 * @param3  size_t       size of the substring
 * @return  char *       pointer to the substring
 */
char	*ft_substr(const char *s, unsigned int start, size_t len) {
	if (len == 0 || start > ft_strlen(s)) {
		return (ft_strempty());
	}
	if (!s) {
		return (NULL);
	}
	if (len > ft_strlen(s) - start) {
		len = ft_strlen(s) - start;
	}
	char *str = ft_malloc(sizeof(char) * (len + 1));
	if (!str) {
		return (NULL);
	}
	ft_memcpy(str, s + start, len + 1);
	return (str);
}
