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

t_spec				spec_get(char spec) {
	if (spec == 's') {
		return (&spec_string);
	}
	else if (spec == 'd' || spec == 'i') {
		return (&spec_signed_int);
	}
	else if (spec == 'u') {
		return (&spec_unsigned_int);
	}
	else if (spec == 'o') {
		return (&spec_base);
	}
	else if (spec == 'x') {
		return (&spec_base);
	}
	else if (spec == 'X') {
		return (&spec_base);
	}
	else if (spec == 'p') {
		return (&spec_ptr);
	}
	if (spec == 'c') {
		return (&spec_char);
	}
	else if (spec == 'n') {
		return (&spec_charsprinted);
	}
	return (&spec_char);
}
