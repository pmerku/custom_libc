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
 * Compare n bytes of two strings
 *
 * @param1  const char * first string to compare
 * @param2  const char * second string to compare
 * @param3  size_t       number of bytes to compare
 * @return  int          comparison difference
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n) {
	if (n == 0) {
		return (0);
	}
	n -= 1;
	while (n && *s1 && *s2 && *s1 == *s2) {
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
