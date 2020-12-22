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

#include <ft_string.h>
#include <tester.h>
#include <ft_memory.h>
#include <cstring>

void ft_test_strlen() {
	char buff[501];
	size_t	i = 0;
	ft_bzero(buff, 501);
	while (i++ < 500) {
		size_t j = 0;
		buff[i] = (char)('a' + i % 26);
		while (j++ < i) {
			ft_assert(ft_strlen(buff + j) == strlen(buff + j));
		}
	}
}

void ft_test_strdup() {
	char buff[501];
	size_t i = 0;
	ft_bzero(buff, 501);
	while (i++ < 500) {
		buff[i] = (char)('a' + i % 26);
		char *tmp = ft_strdup(buff);
		ft_assert(!ft_memcmp(buff, tmp, ft_strlen(buff) + 1));
		ft_free(tmp);
	}
}