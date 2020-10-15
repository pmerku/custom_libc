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

/*
 * Write a character to output fd
 *
 * @param1  char specified character
 * @param2  int  file descriptor to write to
 * @return  void no return
 */
void	ft_putchar_fd(char c, int fd) {
	ft_write(fd, &c, 1);
}
