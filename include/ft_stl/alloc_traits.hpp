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

#ifndef ALLOC_TRAITS_HPP
#define ALLOC_TRAITS_HPP 1

#include "move.hpp"

namespace ft {
	template<typename Alloc, typename = typename Alloc::value_type>
	struct alloc_traits {
		typedef Alloc alloc_type;

		typedef typename Alloc::pointer			pointer;
		typedef typename Alloc::const_pointer	const_pointer;
		typedef typename Alloc::value_type		value_type;
		typedef typename Alloc::reference		reference;
		typedef typename Alloc::const_reference	const_reference;
		typedef typename Alloc::size_type		size_type;
		typedef typename Alloc::difference_type	difference_type;

		static pointer allocate(Alloc &a, size_type n) { return a.allocate(n); }

		static void deallocate(Alloc &a, pointer p, size_type n) { a.deallocate(p, n); }

		template<typename Type>
		static void construct(Alloc &a, pointer p, const Type &arg) { a.construct(p, arg); }

		static void destroy(Alloc &a, pointer p) { a.destroy(p); }

		static size_type max_size(const Alloc &a) { return a.max_size(); }

		static const Alloc &self_select_on_copy(const Alloc &a) { return a; }

		static void self_on_swap(Alloc &a, Alloc &b) {
			if (a != b) {
				ft::swap(a, b);
			}
		}

		template<typename Type>
		struct rebind {
			typedef typename Alloc::template rebind<Type>::other other;
		};
	};

} // namespace ft

#endif