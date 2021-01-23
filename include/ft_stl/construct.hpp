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

#ifndef CONSTRUCT_HPP
#define CONSTRUCT_HPP 1

#include "move.hpp"
#include "iterator_base_types.hpp"
#include "alloc_traits.hpp"
#include "iterator_base_funcs.hpp"
#include <memory>
#include <new>

namespace ft {

	template<typename Type1, typename Type2>
	inline void construct(Type1 *p, const Type2 &value) {
		::new(static_cast<void*>(p)) Type1(value);
	}

	template<typename Type1>
	inline void construct(Type1 *p) {
		::new(static_cast<void*>(p)) Type1;
	}

	template<typename Type>
	inline void destroy(Type *pointer) { pointer->~Type(); }

	template<bool>
	struct destroy_aux {
		template<typename ForwardIterator>
		static void destroy(ForwardIterator first, ForwardIterator last) {
			for (; first != last; ++first) {
				ft::destroy(ft::addressof(*first));
			}
		}
	};

	template<>
	struct destroy_aux<true> {
		template<typename ForwardIterator>
		static void destroy(ForwardIterator, ForwardIterator) { }
	};

	template<typename ForwardIterator>
	inline void destroy(ForwardIterator first, ForwardIterator last) {
		ft::destroy_aux<true>::destroy(first, last);
	}

	template<bool>
	struct destroy_n_aux {
		template<typename ForwardIterator, typename Size>
		static ForwardIterator destroy_n(ForwardIterator first, Size count) {
			for (; count > 0; (void)++first, --count) {
				ft::destroy(ft::addressof(*first));
			}
			return first;
		}
	};

	template<>
	struct destroy_n_aux<true> {
		template<typename ForwardIterator, typename Size>
		static ForwardIterator destroy_n(ForwardIterator first, Size count) {
			ft::advance(first, count);
			return first;
		}
	};

	template<typename ForwardIterator, typename Size>
	inline ForwardIterator destroy_n(ForwardIterator first, Size count) {
		return ft::destroy_n_aux<true>::destroy_n(first, count);
	}

	template<typename ForwardIterator, typename Allocator>
	void destroy(ForwardIterator first, ForwardIterator last, Allocator &alloc) {
		typedef alloc_traits<Allocator> traits;
		for (; first != last; ++first) {
			traits::destroy(alloc, ft::addressof(*first));
		}
	}

	template<typename ForwardIterator, typename Type>
	inline void destroy(ForwardIterator first, ForwardIterator last, std::allocator<Type> &) {
		destroy(first, last);
	}

} // namespace ft

#endif