/* ************************************************************************** */
/*                                                                            */
/*   main.c                                               ::::::::            */
/*   prmerku                                            :+:    :+:            */
/*   prmerku@student.codam.nl                          +:+                    */
/*                                                    +#+                     */
/*                                                   +#+                      */
/*   while (!(succeed = try()))                    #+#    #+#                 */
/*   Project: github_libc                          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_string.h>

int 	main(void)
{
	char	*s = "hello";

	printf("%zu\n", ft_strlen(s));
	return (0);
}