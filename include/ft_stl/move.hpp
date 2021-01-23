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

#ifndef MOVE_HPP
#define MOVE_HPP 1

#include <cstddef>

namespace ft {

	template<typename Type>
	inline Type *addressof(Type &r) { return &r; }

	template<typename Type>
	inline void swap(Type &a, Type &b) {
		Type tmp = a;
		a = b;
		b = tmp;
	}

	template<typename Type, size_t Nm>
	inline void swap(Type (&a)[Nm], Type (&b)[Nm]) {
		for (size_t n = 0; n < Nm; ++n) {
			swap(a[n], b[n]);
		}
	}

} // namespace ft

#endif