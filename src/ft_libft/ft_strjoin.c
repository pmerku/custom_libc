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
#include <ft_memory.h>

/*
 * Join two character arrays into one
 *
 * @param1  char const * first character array
 * @param2  char const * second character array
 * @return  char *       new character array
 */
char	*ft_strjoin(char const *s1, char const *s2) {
	if (!s1 || !s2)
		return (NULL);
	size_t len1 = ft_strlen(s1);
	size_t len2 = ft_strlen(s2);
	char *str = ft_malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1 + 1);
	ft_memcpy(str + len1, s2, len2 + 1);
	return (str);
}
