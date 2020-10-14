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

#include <ft_stdio/ft_printf_utils.h>

/*
 * Write the output to `fd` under the control of a format string that specifies how subsequent
 * arguments are converted for output.
 *
 * @param1	int fd       output file descriptor
 * @param2	const char * format string
 * @param3  ...          variable length argument
 * @return  int          number of printed characters
 */
int		ft_fprintf(int fd, const char *fmt, ...) {
	va_list			args;
	t_ft_printf		printf;
	t_buf			buf;
	t_buf_fd		fd_inner;
	int				ret_val;

	buf_fd_create(&buf, &fd_inner, fd);
	buf_reset(&buf);
	printf.buf = &buf;
	va_start(args, fmt);
	printf.args = &args;
	ret_val = ft_inner_printf(&printf, fmt);
	va_end(args);
	return (ret_val);
}
