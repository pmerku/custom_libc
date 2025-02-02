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
#include <stdlib.h>

/*
 * Write the output to `fd` under the control of a format string that specifies how subsequent
 * arguments are converted for output and exit out the code.
 *
 * @param1	int          exit code
 * @param1	const char * format string
 * @param2  ...          variable length argument
 * @return  int          number of printed characters
 */
void	ft_eprintf(int code, const char *fmt, ...) {
	va_list			args;
	t_ft_printf		printf;
	t_buf			buf;
	t_buf_fd		fd_inner;

	buf_fd_create(&buf, &fd_inner, 2);
	buf_reset(&buf);
	buf_putstr(&buf, "\033[91m\033[4m\033[1mError\033[0m\033[91m ");
	printf.buf = &buf;
	va_start(args, fmt);
	printf.args = &args;
	ft_inner_printf(&printf, fmt);
	va_end(args);
	exit(code);
}
