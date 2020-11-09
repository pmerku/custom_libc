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

#ifndef TESTER_H
# define TESTER_H

# include <cstddef>
# include <string>

struct		s_test {
	std::string	name;
	void		(*test)();
};

void	assert(int expression);

/*
 * ctype tests
 */
void	ft_test_isalnum();
void	ft_test_isalpha();
void	ft_test_isascii();
void	ft_test_isdigit();
void	ft_test_islower();
void	ft_test_isprint();
void	ft_test_isspace();
void	ft_test_isupper();
void	ft_test_tolower();
void	ft_test_toupper();

/*
 * libft tests
 */
void 	ft_test_gnl();

/*
 * unistd tests
 */
void 	ft_test_read();
void 	ft_test_write();

void	ft_test_mstack();

#endif
