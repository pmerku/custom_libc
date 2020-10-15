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
 * Copy no more than n bytes from the src memory to the dest area
 * stopping when the character c is found
 *
 * @param1  void *       pointer to the dest memory
 * @param2  const void * pointer to the src memory
 * @param3  int          character value
 * @param4  size_t       max bytes to copy
 * @return  void *       pointer to the next character in dest after c
 */
void	*ft_memccpy(void *dst, const void *src, int c, size_t n) {
	if (n) {
		unsigned char		*d = (unsigned char*)dst;
		const unsigned char	*s = (const unsigned char*)src;
		while (n--) {
			*d++ = *s++;
			if (*d == (unsigned char)c) { //TODO test this
				return (d + 1);
			}
		}
	}
	return (NULL);
}
