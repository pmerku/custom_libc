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
#include <ft_string.h>

/*
 * Append a string to a 2d array
 *
 * @param1  char *** pointer to the array where the string will be appended
 * @param2  char *   string to appen
 * @return  void     no return
 */
void			ft_strarr_append(char ***arr, char *line) {
	if (*arr == NULL) {
		*arr = ft_checked_calloc(2, sizeof(char *));
		(*arr)[0] = line;
		return ;
	}
	char **new_arr = ft_checked_calloc(ft_strarr_size(*arr) + 2, sizeof(char *));
	if (new_arr != NULL) {
		int i = 0;
		while ((*arr)[i] != NULL) {
			new_arr[i] = (*arr)[i];
			i++;
		}
		new_arr[i] = line;
	}
	ft_free(*arr);
	*arr = new_arr;
}
