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
 * Duplicate and allocate a new string
 *
 * @param   const std::string & string to duplicate
 * @return  char *              pointer to new allocated string
 */
char	*ft_strdup(const std::string &str) {
	size_t len = str.length();
	char *mem = new char[len + 1]();
	for (size_t i = 0; i < len; i++)
		mem[i] = str[i];
	return mem;
}
