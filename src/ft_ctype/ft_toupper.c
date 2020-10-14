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
 * Convert char to uppercase
 *
 * @return  int value of converted char
 */
int		ft_toupper(int c) {
	if (c >= 'a' && c <= 'z') {
		return (c - 32);
	}
	return (c);
}
