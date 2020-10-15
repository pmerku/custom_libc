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
 * Calculate x raised to the power of n
 *
 * @param1  double number to raise
 * @param2  double exponent
 * @return  double calculated number
 */
double		ft_pow(double x, double n) {
	while (n) {
		x *= x;
		n--;
	}
	return (x);
}
