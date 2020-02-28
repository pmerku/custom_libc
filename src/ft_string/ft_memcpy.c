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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n || dst != src)
	{
		d = (char*)dst;
		s = (const char*)src;
		if (!d && !s)
			return (NULL);
		while (n)
		{
			*d = *s;
			d++;
			s++;
			n--;
		}
	}
	return (dst);
}
