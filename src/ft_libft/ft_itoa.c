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
#include <ft_memory.h>

/*
 * Convert integer to string
 *
 * @param   int    number to convert
 * @return  char * number in a string
 */
char		*ft_itoa(int n) {
	size_t	len = ft_intlen(n);
	char	*str = ft_malloc(sizeof(char) * (len + 1));

	if (!str) {
		return (NULL);
	}
	if (n < 0) {
		str[0] = '-';
	}
	else if (n == 0) {
		str[0] = '0';
	}
	else {
		n *= -1;
	}
	str[len] = '\0';
	while (len && n) {
		str[len - 1] = -(n % 10) + 48;
		n /= 10;
		len--;
	}
	return (str);
}
