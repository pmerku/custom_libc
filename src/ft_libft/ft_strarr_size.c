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
 * Get size of an array
 *
 * @param   char ** array to get the size
 * @return  int     size of the array
 */
int		ft_strarr_size(char **arr) {
	int size = 0;
	while (arr[size] != NULL) {
		size++;
	}
	return (size);
}

