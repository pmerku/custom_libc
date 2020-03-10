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
#include <stdio.h>

int 	main(void)
{
	int		fd0;
	char	*line;
	int		s0;

	fd0 = open("tests/big.txt", O_RDONLY);
	s0 = 1;
	while (s0 > 0)
	{
		s0 = get_next_line(fd0, &line);
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
