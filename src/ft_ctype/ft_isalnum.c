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
 * Check if character is alphanumerical
 *
 * @return  int 1 if true and 0 if false
 */
int		ft_isalnum(int c) {
	return (ft_isalpha(c) || ft_isdigit(c));
}
