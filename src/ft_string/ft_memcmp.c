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

int		ft_memcmp(const	void *s1, const	void *s2, size_t n) {
	if (n) {
		unsigned char	*src1 = (unsigned char*)s1;
		unsigned char	*src2 = (unsigned char*)s2;
		while (n--) {
			if (*src1 != *src2)
				return (*src1 - *src2);
			src1++;
			src2++;
		}
	}
	return (0);
}
