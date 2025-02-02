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
 * @param1  int    number to convert
 * @param2  int    base to use
 * @return  char * number in a string
 */
char	*ft_itoa_base(int n, int base) {
	size_t	len = ft_intlen_base(n, base);
	char	*str = ft_malloc(sizeof(char) * (len + 1));

	if (!str) {
		return (NULL);
	}
	if (n < 0 && base == 10) {
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
		str[len - 1] = BASE_SET[-(n % base)];
		n /= base;
		len--;
	}
	return (str);
}
