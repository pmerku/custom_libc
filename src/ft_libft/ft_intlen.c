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
 * @param   int number to count
 * @return  int length of number
 */
int		ft_intlen(int n) {
	int len = (n <= 0) ? 1 : 0;
	while (n) {
		n /= 10;
		len++;
	}
	return (len);
}
