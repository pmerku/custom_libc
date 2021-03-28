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

#include <string>

/*
 * Convert integer to std::string
 *
 * @param   int         number to convert
 * @return  std::string converted number
 */
std::string ft_itos(int x) {
	if (x < 0)
		return std::string("-") + ft_itos(-x);
	if (x < 10)
		return std::string(1, x + '0');
	return ft_itos(x / 10) + ft_itos(x % 10);
}
