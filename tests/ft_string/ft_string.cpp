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

void test_strlen() {
	char buff[501] = { 0 };
	for (size_t i = 0; i < 500; i++) {
		size_t j = 0;
		buff[i] = (char)('a' + i % 26);
		while (j++ < i) {
			ASSERT_THROW(ft_strlen(buff + j), strlen(buff + j));
		}
	}
}

void test_strdup() {
	char buff[501] = { 0 };
	for (size_t i = 0; i < 500; i++) {
		buff[i] = (char)('a' + i % 26);
		char *tmp = ft_strdup(buff);
		ASSERT_THROW(ft_memcmp(buff, tmp, ft_strlen(buff) + 1), 0);
		ft_free(tmp);
	}
}

int main() {
	test_strlen();
	test_strdup();
	return 0;
}