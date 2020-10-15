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
 * Write a string with a new line to output fd
 *
 * @param1  char * string to write
 * @param2  int    file descriptor to write to
 * @return  void   no return
 */
void	ft_putendl_fd(char *s, int fd) {
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
