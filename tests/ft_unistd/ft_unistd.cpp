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

#include <ft_unistd.h>
#include <tester.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <ft_string.h>

void	ft_test_read() {
	size_t	i = 0;
	while (i++ < 10) {
		char	buf1[129];
		char	buf2[129];
		int fd1 = open("Makefile", O_RDONLY);
		int fd2 = open("Makefile", O_RDONLY);
		int ret1 = ft_read(fd1, buf1, 128);
		buf1[ret1] = '\0';
		int ret2 = read(fd2, buf2, 128);
		buf2[ret2] = '\0';
		close(fd1);
		close(fd2);
		ft_assert((ft_strcmp(buf1, buf2) == 0));
	}
	int ret1 = ft_read(FOPEN_MAX + 1, NULL, 128);
	int ret2 = read(FOPEN_MAX + 1, NULL, 128);
	ft_assert(ret1 == ret2);
}

void 	ft_test_write() {
	size_t	i = 0;
	while (i++ < 10) {
		std::string arr = "This is a test string!!!\n";
		int fd = open("tests/text", O_WRONLY | O_CREAT | O_APPEND, 0777);
		int ret1 = ft_write(fd, arr.c_str(), arr.length());
		int ret2 = write(fd, arr.c_str(), arr.length());
		ft_assert(ret1 == ret2);
		system("rm tests/text");
	}
	int ret1 = write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	errno = 100;
	int ret2 = ft_write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n\n", 27);
	ft_assert(ret1 == ret2);
}
