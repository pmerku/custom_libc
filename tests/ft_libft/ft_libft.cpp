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

#include <ft_libft.h>
#include <tester.h>
#include <fcntl.h>
#include <unistd.h>
#include <ft_memory.h>
#include <ft_stdio.h>

void	ft_test_gnl() {
#ifdef CMAKE_BUILD
	return;
#endif
	size_t	i = 0;
	while (i++ < 10) {
		char *line;
		int fd = open("tests/main.cpp", O_RDONLY);
		int out = open("tests/text", O_CREAT | O_WRONLY | O_APPEND, 0777);
		int ret = 1;
		while ((ret = get_next_line(fd, &line)) > 0) {
			(ret == 0) ? ft_fprintf(out, "%s", line) : ft_fprintf(out, "%s\n", line);
			ft_free(line);
		}
		close(fd);
		close(out);
		ft_assert((system("diff tests/main.cpp tests/text > /dev/null") == 0));
		system("rm tests/text");
	}
}
