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

#include <ft_string.h>
#include <ft_unistd.h>

/*
 * Write a string to output fd
 *
 * @param1  char * string to write
 * @param2  int    file descriptor to write to
 * @return  void   no return
 */
void	ft_putstr_fd(char *s, int fd) {
	ft_write(fd, s, ft_strlen(s));
}
