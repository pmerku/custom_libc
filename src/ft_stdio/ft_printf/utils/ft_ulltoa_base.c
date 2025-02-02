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

static void		ft_ulltoa_inner(char *out, char *base, unsigned long long value, int *i) {
	unsigned long long base_size;

	base_size = (unsigned long long)ft_strlen(base);
	if (value >= base_size) {
		ft_ulltoa_inner(out, base, value / base_size, i);
	}
	out[*i] = base[value % base_size];
	(*i)++;
}

void			ft_ulltoa_base(char *out, char *base, unsigned long long value) {
	if (value == 0) {
		out[0] = base[0];
		out[1] = '\0';
		return ;
	}
	int i = 0;
	ft_ulltoa_inner(out, base, value, &i);
}
