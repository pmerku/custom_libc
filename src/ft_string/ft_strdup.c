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
#include <ft_string.h>
#include <ft_memory.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*mem;

	len = ft_strlen(s1);
	mem = ft_malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, len + 1);
	return (mem);
}
