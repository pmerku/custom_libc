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
