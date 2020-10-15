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

#include <ft_memory.h>

/*
 * Free allocated 2d array
 *
 * @param   void ** pointer to the 2d allocated array
 * @return  void ** NULL is returned
 */
char	**ft_free_array(char **arr) {
	int i = 0;
	while (arr[i] != NULL) {
		ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
	return (NULL);
}
