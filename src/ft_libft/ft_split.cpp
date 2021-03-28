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

#include <vector>
#include <string>

/*
 * Split a string based on a delimiter, until the
 * end and return a vector of strings
 *
 * @param1  const std::string & string to split
 * @param2  const std::string & delimiter to split on
 * @return  std::vector<std::string>      vector of strings
 */
std::vector<std::string>	ft_split(const std::string& str, const std::string& del) {
	std::vector<std::string> array;

	for (std::vector<std::string>::size_type end = 0; end != str.npos;) {
		std::vector<std::string>::size_type start = str.find_first_not_of(del, end);
		end = str.find_first_of(del, start);
		if (end != std::string::npos || start != std::string::npos)
			array.push_back(str.substr(start, end - start));
	}
	return array;
}
