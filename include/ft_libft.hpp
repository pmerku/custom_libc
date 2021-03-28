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

#ifndef FT_LIBFT_HPP
# define FT_LIBFT_HPP

# include <string>
# include <vector>

std::string					ft_itos(int x);
std::vector<std::string>	ft_split(const std::string& str, const std::string& del);
char						*ft_strdup(const std::string &str);

#endif
