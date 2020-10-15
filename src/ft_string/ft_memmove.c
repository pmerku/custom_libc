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

/*
 * Copy n bytes from src into dst
 *
 * @param1  void *       dst memory area
 * @param2  const void * src memory area
 * @param3  size_t       number of bytes to copy
 * @return  void *       pointer to dst
 */
void	*ft_memmove(void *dst, const void *src, size_t len) {
	char *d = (char*)dst;
	char *s = (char*)src;
	if (!d && !s) {
		return (NULL);
	}
	if (d < s) {
		ft_memcpy(dst, src, len);
	}
	else {
		char *d_end = d + (len - 1);
		char *s_end = s + (len - 1);
		while (len--) {
			*d_end-- = *s_end--;
		}
	}
	return (dst);
}
