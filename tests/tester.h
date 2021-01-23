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

#ifndef TESTER_H
# define TESTER_H

# include <stdexcept>
# include <string>

#define ASSERT_THROW(a, b) do { \
    if ((a) != (b)) { \
        throw std::runtime_error(std::string(__FILE__) \
        	+ std::string(":") + std::to_string(__LINE__) \
        	+ std::string(" in ") + std::string(__func__)); \
    } \
} while(0)

#define ASSERT_EQUAL(condition) do { \
    if (!(condition)) { \
        throw std::runtime_error( std::string(__FILE__) \
        	+ std::string(":") + std::to_string(__LINE__)     \
        	+ std::string(" in " ) + std::string(__func__));\
    } \
} while(0)

#endif
