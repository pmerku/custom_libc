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
#include <ft_string.h>
#include <fstream>

void	test_gnl() {
	char *line;
	int fd = open(__FILE__, O_RDONLY);
	char str[10001];
	ft_bzero(str, 10001);
	int offset = 0;
	while (get_next_line(fd, &line)) {
		int ret = ft_snprintf(str + offset, sizeof(str) - offset, "%s\n", line);
		if (ret < 0)
			break;
		offset += ret;
		ft_free(line);
	}
	ft_snprintf(str + offset, sizeof(str) - offset, "\n");
	close(fd);
	std::ifstream file(__FILE__);
	std::string s, total;
	while (!file.eof()) {
		getline(file, s);
		total += s + "\n";
	}
	file.close();
	ASSERT_EQUAL(ft_strcmp(str, total.c_str()) == 0);
}

int main() {
	for (int i = 0; i < 5; i++)
		test_gnl();
	return 0;
}
