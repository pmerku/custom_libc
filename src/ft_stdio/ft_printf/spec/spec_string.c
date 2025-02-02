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
#include <ft_string.h>

void			spec_string(t_ft_printf *pf, t_ft_fmt *fmt) {
	char prefix = fmt->leftpad_zeroes == 1 ? '0' : ' ';
	char *str = va_arg(*(pf->args), char*);
	str = (str == NULL ? "(null)" : str);
	int strlen = ft_strlen(str);
	int to_print = strlen;
	if (fmt->precision_set == 1 && fmt->orig_precision >= 0) {
		to_print = (fmt->precision < strlen ? fmt->precision : strlen);
	}
	if (fmt->left_justify == 0 && (int)fmt->width != 0 && (int)fmt->width > to_print) {
		buf_putchars(pf->buf, prefix, fmt->width - to_print);
	}
	buf_putstri(pf->buf, str, to_print);
	if (fmt->left_justify == 1 && (int)fmt->width != 0 && (int)fmt->width > to_print) {
		buf_putchars(pf->buf, ' ', fmt->width - to_print);
	}
}
