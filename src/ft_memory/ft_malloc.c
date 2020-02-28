/* ************************************************************************** */
/*                                                                            */
/*   Project: github_libc                                 ::::::::            */
/*   Members: prmerku                                   :+:    :+:            */
/*   Copyright: 2020                                   +:+                    */
/*                                                    +#+                     */
/*                                                   +#+                      */
/*                                                  #+#    #+#                */
/*   while (!(succeed = try()));                   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_malloc(size_t n)
{
	void *data;

	data = malloc(n);
	return (data);
}
