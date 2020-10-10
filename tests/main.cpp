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

#include <ft_stdio/ft_printf.h>
#include <ft_string.h>
#include <stdlib.h>
#include <ft_libft.h>
#include <fcntl.h>
#include <ft_memory.h>
#include <MutantStack.hpp>
#include <iostream>
#include <vector>
#include <unistd.h>

int 	main(void)
{
	int		fd;
	char	*line;
	int		s0 = 1;

	if ((fd = open("./tests/main.cpp", O_RDONLY)) == -1) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	while (s0 > 0) {
		s0 = get_next_line(fd, &line);
		ft_printf("[%d][%d]=> [%s]\n", fd, s0, line);
		free(line);
	}
	close(fd);
	char	*s = static_cast<char *>(ft_malloc(8));
	ft_bzero(s, 8);
	ft_printf("%d\n", ft_strlen(s));
	ft_printf("%s\n", ft_strdup("helpme"));
	ft_printf("%s\n", ft_strcpy(s, "helpme"));
	ft_printf("%d\n", ft_strcmp(s, "help"));
	ft_printf("%s\n", ft_memcpy(s, "hello", 6));

	std::cout << "-----------------\n";
	MutantStack<int, std::vector<int> > vstack;

	for (int i = 0; i < 11; ++i) {
		vstack.push(rand() % 100);
	}
	std::cout << "top: " << vstack.top() << "\n";
	vstack.pop();
	std::cout << "size: " << vstack.size() << "\n";
	MutantStack<int, std::vector<int> >::const_iterator it = vstack.begin();
	MutantStack<int, std::vector<int> >::const_iterator ite = vstack.end();
	std::cout << "VStack = ";
	while (it != ite) {
		std::cout << *it << " | ";
		++it;
	}
	vstack.pop();
	std::cout << "\ntop: " << vstack.top() << '\n';
	return 0;
}
