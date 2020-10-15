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
 * Strip characters away from a character array
 *
 * @param1  char * character array where to strip
 * @param2  char   character to strip
 * @return  char * the stripped character array
 */
char	*ft_strip_chars(char *str, char c) {
	size_t src = 0;
	size_t pos = 0;
	while (str[src] != '\0') {
		if (str[src] != c) {
			str[pos] = str[src];
			pos++;
		}
		src++;
	}
	str[pos] = '\0';
	return (str);
}
