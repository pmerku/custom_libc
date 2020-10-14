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
 * Write the output to a string under the control of a format string that specifies how subsequent
 * arguments are converted for output.
 *
 * @param1	char *       output string
 * @param2  size_t       size to print
 * @param3	const char * format string
 * @param4  ...          variable length argument
 * @return  int          number of printed characters
 */
int		ft_snprintf(char *str, size_t size, const char *fmt, ...) {
	va_list			args;
	t_ft_printf		printf;
	t_buf			buf;
	t_buf_str		buf_inner;
	int				ret_val;

	if (size == 0)
		return (0);
	buf_str_create(&buf, &buf_inner, str, size);
	buf_reset(&buf);
	printf.buf = &buf;
	va_start(args, fmt);
	printf.args = &args;
	ret_val = ft_inner_printf(&printf, fmt);
	va_end(args);
	str[buf_chars_printed(&buf)
		- ((size_t)buf_chars_printed(&buf) == size ? 1 : 0)] = '\0';
	return (ret_val);
}
