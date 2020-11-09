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

#include <cstdio>
#include <tester.h>
#include <ctime>

static int				g_test_count = 0;
static int				g_failed_tests = 0;
static struct s_test	g_tests[] = {
		{.name = "ft_isalnum()", .test = &ft_test_isalnum},
		{.name = "ft_isalpha())", .test = &ft_test_isalpha},
		{.name = "ft_isascii())", .test = &ft_test_isascii},
		{.name = "ft_isdigit())", .test = &ft_test_isdigit},
		{.name = "ft_islower())", .test = &ft_test_islower},
		{.name = "ft_isprint())", .test = &ft_test_isprint},
		{.name = "ft_isspace())", .test = &ft_test_isspace},
		{.name = "ft_isupper())", .test = &ft_test_isupper},
		{.name = "ft_tolower())", .test = &ft_test_tolower},
		{.name = "ft_toupper())", .test = &ft_test_toupper},
		{.name = "get_next_line())", .test = &ft_test_gnl},
		{.name = "ft_read())", .test = &ft_test_read},
		{.name = "ft_write())", .test = &ft_test_write},
		{.name = "MutantStack", .test = &ft_test_mstack},
		{.name = "", .test = nullptr }
};

void	ft_assert(int expression) {
	g_test_count++;
	if (!expression) {
		printf("Assertion %d failed\n", g_test_count);
		g_failed_tests++;
	}
}

int 	main() {
	size_t	i = 0;
	int		ret = 0;
	double	time;

	while (!g_tests[i].name.empty()) {
		time = clock();
		printf("[%f s] Testing: %s\n", time / CLOCKS_PER_SEC, g_tests[i].name.c_str());
		g_tests[i].test();
		time = clock();
		printf("[%f s] %d out of %d tests failed\n", time / CLOCKS_PER_SEC, g_failed_tests, g_test_count);
		if (g_failed_tests) {
			ret = (-1);
		}
		g_test_count = 0;
		g_failed_tests = 0;
		i++;
	}
	return ret;
}
