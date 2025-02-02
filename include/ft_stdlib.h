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

#ifdef __cplusplus
extern "C" {
#endif
#ifndef FT_STDLIB_H
# define FT_STDLIB_H

int		ft_atoi(const char *str);
int		ft_abs(int n);
double	ft_dabs(double n);
int		ft_max(int a, int b);
int 	ft_min(int a, int b);

/*
 * Exit the program with a provided exit code
 *
 * @param   int  exit code
 * @return  void no return
 */
extern void	ft_exit(int status);

#endif
#ifdef __cplusplus
}
#endif
