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

/*
 * Get length of number
 *
 * @param1   int number to count
 * @param2   int base to use
 * @return   int length of number
 */
int		ft_intlen_base(int n, int base)
{
	if (base < 2 || base > 16) {
		return (0);
	}
	int len = (n <= 0);
	while (n) {
		n /= base;
		len++;
	}
	return (len);
}
