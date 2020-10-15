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
 * Set n bytes in s to the character c
 *
 * @param1  void * pointer to memory to fill
 * @param2  int    character value
 * @param3  size_t number of bytes to set
 * @return  void * pointer to filled memory
 */
void	*ft_memset(void *s, int c, size_t n) {
	unsigned char *ptr = (unsigned char*)s;
	while (n--) {
		*ptr = (char)c;
		ptr++;
	}
	return (s);
}
