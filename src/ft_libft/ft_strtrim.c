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
#include <ft_libft.h>

/*
 * Trim a set out of a character array
 *
 * @param1  const char * array to trim
 * @param2  const char * set to trim
 * @return  char *       new array without the trimmed set
 */
char		*ft_strtrim(const char *s1, const char *set) {
	if (s1 == NULL || set == NULL) {
		return (NULL);
	}
	if (ft_strlen(s1) == 0) {
		return (ft_strempty());
	}
	unsigned int start = 0;
	unsigned int endi = 0;
	unsigned int end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) != NULL) {
		start++;
	}
	while (end >= start && ft_strchr(set, s1[end - endi]) != NULL) {
		endi++;
	}
	if (start + endi > end) {
		return (ft_strempty());
	}
	return (ft_substr(s1, start, ft_strlen(s1) - start - endi));
}
