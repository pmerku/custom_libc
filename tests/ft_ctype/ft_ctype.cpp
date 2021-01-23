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

void	test_isalnum() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_isalnum(i), (isalnum(i) > 0));
	}
}

void	test_isalpha() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_isalpha(i), (isalpha(i) > 0));
	}
}

void	test_isascii() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_isascii(i), (isascii(i) > 0));
	}
}

void	test_isdigit() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_isdigit(i), (isdigit(i) > 0));
	}
}

void	test_islower() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_islower(i), (islower(i) > 0));
	}
}

void	test_isprint() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_isprint(i), (isprint(i) > 0));
	}
}

void	test_isspace() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_isspace(i), (isspace(i) > 0));
	}
}

void	test_isupper() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_isupper(i), (isupper(i) > 0));
	}
}

void	test_tolower() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_tolower(i), tolower(i));
	}
}

void	test_toupper() {
	for (size_t i = 0; i < 128; i++) {
		ASSERT_THROW(ft_toupper(i), toupper(i));
	}
}

int 	main() {
	test_isalnum();
	test_isalpha();
	test_isascii();
	test_isdigit();
	test_islower();
	test_isprint();
	test_isspace();
	test_isupper();
	test_tolower();
	test_toupper();
	return 0;
}
