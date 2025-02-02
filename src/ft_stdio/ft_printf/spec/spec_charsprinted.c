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

void	spec_charsprinted(t_ft_printf *pf, t_ft_fmt *fmt) {
	(void)fmt;
	signed int *ptr = va_arg(*pf->args, signed int*);
	*ptr = buf_chars_printed(pf->buf);
}
