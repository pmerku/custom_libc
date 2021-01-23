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
#include <cerrno>
#include <cstring>
#include <ft_string.h>

void	test_read() {
	for (size_t i = 0; i < 10; i++) {
		char	buf1[129];
		char	buf2[129];
		int fd1 = open(__FILE__, O_RDONLY);
		int fd2 = open(__FILE__, O_RDONLY);
		int ret1 = ft_read(fd1, buf1, 128);
		buf1[ret1] = '\0';
		int ret2 = read(fd2, buf2, 128);
		buf2[ret2] = '\0';
		close(fd1);
		close(fd2);
		ASSERT_EQUAL(ft_strcmp(buf1, buf2) == 0);
	}
	int ret1 = read(FOPEN_MAX + 1, nullptr, 128);
	std::string str1 = strerror(errno);
	int ret2 = ft_read(FOPEN_MAX + 1, nullptr, 128);
	std::string str2 = strerror(errno);
	ASSERT_EQUAL(str1 == str2);
	ASSERT_EQUAL(ret1 == ret2);
}

void 	test_write() {
	for (size_t i = 0; i < 10; i++) {
		std::string arr = "This is a test string!!!\n";
		int fd = open("../tests/text", O_WRONLY | O_CREAT | O_APPEND, 0777);
		int ret1 = ft_write(fd, arr.c_str(), arr.length());
		int ret2 = write(fd, arr.c_str(), arr.length());
		ASSERT_EQUAL(ret1 == ret2);
		int unused __attribute__((unused));
    	unused = system("rm ../tests/text");
	}
	int ret1 = write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	std::string str1 = strerror(errno);
	int ret2 = ft_write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n\n", 27);
	std::string str2 = strerror(errno);
	ASSERT_EQUAL(str1 == str2);
	ASSERT_EQUAL(ret1 == ret2);
}

int main() {
	test_read();
	test_write();
	return 0;
}