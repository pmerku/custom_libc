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
 * Find last occurrence of c in s
 *
 * @param1  const char * string to search
 * @param2  int          character to find
 * @return  char *       pointer to the matched character
 */
char	*ft_strrchr(const char *s, int c) {
	char *ptr = NULL;
	if (c == '\0') {
		return (ft_strchr(s, '\0'));
	}
	while (*s) {
		char pos = *s;
		if (c == pos) {
			ptr = (char *) s;
		}
		s++;
	}
	return (ptr);
}
