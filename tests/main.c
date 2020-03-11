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

int 	main(void)
{
	int		fd0;
	char	*line;
	int		s0;

	fd0 = open("tests/main.c", O_RDONLY);
	s0 = 1;
	while (s0 > 0)
	{
		s0 = get_next_line(fd0, &line);
		ft_printf("%s\n", line);
		free(line);
	}
	char	*s = ft_malloc(8);
	ft_bzero(s, 8);
	ft_printf("%d\n", ft_strlen(s));
	ft_printf("%s\n", ft_strdup("helpme"));
	ft_printf("%s\n", ft_strcpy(s, "helpme"));
	ft_printf("%d\n", ft_strcmp(s, "help"));
	ft_printf("%s\n", ft_memcpy(s, "hello", 6));
	return (0);
}
