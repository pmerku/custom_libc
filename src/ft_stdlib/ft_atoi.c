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

#include <ft_ctype.h>

/*
 * Convert a character array into an integer
 *
 * @param   const char * array to convert
 * @return  int          converted integer
 */
int		ft_atoi(const char *str) {
	long long num = 0;
	int prefix = 1;
	while (ft_isspace(*str)) {
		str++;
	}
	if (*str == '-' || *str == '+') {
		prefix = (*str == '-') ? -1 : 1;
		str++;
	}
	while (ft_isdigit(*str)) {
		num = num * 10 + *str - '0';
		str++;
	}
	return ((int)(num * prefix));
}
