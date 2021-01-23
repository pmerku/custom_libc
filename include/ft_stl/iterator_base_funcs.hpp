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

#ifndef ITERATOR_BASE_FUNCS_HPP
#define ITERATOR_BASE_FUNCS_HPP 1

#include "iterator_base_types.hpp"

namespace ft {

	template<typename InputIterator>
	inline typename iterator_traits<InputIterator>::difference_type __distance(InputIterator first, InputIterator last, input_iterator_tag) {
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last) {
			++first;
			++n;
		}
		return n;
	}

	template<typename RandomAccessIterator>
	inline typename iterator_traits<RandomAccessIterator>::difference_type distance(RandomAccessIterator first, RandomAccessIterator last,
																				 random_access_iterator_tag) {
		return last - first;
	}

	template<typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last) {
		return ft::__distance(first, last, ft::get_iterator_category(first));
	}

	template<typename InputIterator, typename Distance>
	inline void __advance(InputIterator &i, Distance n, input_iterator_tag) {
		while (n--) {
			++i;
		}
	}

	template<typename BidirectionalIterator, typename Distance>
	inline void __advance(BidirectionalIterator &i, Distance n, bidirectional_iterator_tag) {
		if (n > 0) {
			while (n--) {
				++i;
			}
		}
		else {
			while (n++) {
				--i;
			}
		}
	}

	template<typename RandomAccessIterator, typename Distance>
	inline void __advance(RandomAccessIterator &i, Distance n, random_access_iterator_tag) {
		if (n == 1) {
			++i;
		}
		else if (n == -1) {
			--i;
		}
		else {
			i += n;
		}
	}

	template<typename InputIterator, typename Distance>
	inline void advance(InputIterator &i, Distance n) {
		typename iterator_traits<InputIterator>::difference_type d = n;
		ft::__advance(i, d, ft::get_iterator_category(i));
	}

} // namespace ft

#endif
