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

void			spec_char(t_ft_printf *pf, t_ft_fmt *fmt) {
	char	c;

	if (fmt->specifier == 'c') {
		c = (char) va_arg(*pf->args, int);
	}
	else {
		c = fmt->specifier;
	}
	if (fmt->left_justify == 0 && fmt->width > 1) {
		buf_putchars(pf->buf, fmt->leftpad_zeroes ? '0' : ' ', fmt->width - 1);
	}
	buf_putchar(pf->buf, c);
	if (fmt->width < -1) {
		buf_putchars(pf->buf, ' ', -fmt->width - 1);
	}
	if (fmt->width > 1 && fmt->left_justify == 1) {
		buf_putchars(pf->buf, ' ', fmt->width - 1);
	}
}
