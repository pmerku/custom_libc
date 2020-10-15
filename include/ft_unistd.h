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

#ifdef __cplusplus
extern "C" {
#endif
#ifndef FT_UNISTD_H
# define FT_UNISTD_H

# include <sys/types.h>

/*
 * Write nbytes from buffer to a file descriptor
 *
 * @param1  int          file descriptor where to write
 * @param2  const void * buffer where bytes to write are stored
 * @param3  size_t       number of bytes to write
 * @return  ssize_t      number of written bytes
 */
extern ssize_t	ft_write(int fd, const void *buf, size_t nbyte);

/*
 * Read nbytes from file descriptor and store
 * the read bytes inside the buffer buf
 *
 * @param1  int     file descriptor to read
 * @param2  void *  buffer to store read bytes
 * @param3  size_t  number of bytes to read
 * @return  ssize_t number of bytes read
 */
extern ssize_t	ft_read(int fds, void *buf, size_t nbyte);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
#ifdef __cplusplus
}
#endif
