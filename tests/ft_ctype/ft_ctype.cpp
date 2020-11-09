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

#include <cctype>
#include <ft_ctype.h>
#include <tester.h>

void	ft_test_isalnum() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_isalnum(i) == (isalnum(i) > 0));
	}
}

void	ft_test_isalpha() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_isalpha(i) == (isalpha(i) > 0));
	}
}

void	ft_test_isascii() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_isascii(i) == (isascii(i) > 0));
	}
}

void	ft_test_isdigit() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_isdigit(i) == (isdigit(i) > 0));
	}
}

void	ft_test_islower() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_islower(i) == (islower(i) > 0));
	}
}

void	ft_test_isprint() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_isprint(i) == (isprint(i) > 0));
	}
}

void	ft_test_isspace() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_isspace(i) == (isspace(i) > 0));
	}
}

void	ft_test_isupper() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_isupper(i) == (isupper(i) > 0));
	}
}

void	ft_test_tolower() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_tolower(i) == tolower(i));
	}
}

void	ft_test_toupper() {
	size_t	i = 0;
	while (i++ < 128) {
		assert(ft_toupper(i) == toupper(i));
	}
}
