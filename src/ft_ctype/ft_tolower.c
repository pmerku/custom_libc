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

/*
 * Convert char to lowercase
 *
 * @return  int value of converted char
 */
int		ft_tolower(int c) {
	if (c >= 'A' && c <= 'Z') {
		return (c + 32);
	}
	return (c);
}
