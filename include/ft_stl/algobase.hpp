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

#ifndef ALGOBASE_HPP
#define ALGOBASE_HPP 1

#include "iterator_base_types.hpp"
#include "type_traits.hpp"
#include <cstring>

namespace ft {

	template<typename Type>
	inline const Type &min(const Type &a, const Type &b) {
		return b < a ? b : a;
	}

	template<typename Type>
	inline const Type &max(const Type &a, const Type &b) {
		return a < b ? b : a;
	}

	template<typename InputIterator, typename OutputIterator>
	inline OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
		for (; first != last; ++first, (void)++result) {
			*result = *first;
		}
		return result;
	}

	template<typename BidirectionalIterator1, typename BidirectionalIterator2>
	inline BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 resutl) {
		while (first != last) {
			*--resutl = *--last;
		}
		return resutl;
	}

	template<typename OutputIterator, typename Size, typename Type>
	inline OutputIterator fill_n(OutputIterator first, Size num, const Type &value) {
		for (; num > 0; ++first, (void)--num) {
			*first = value;
		}
		return first;
	}

	template<typename ForwardIterator, typename Type>
	inline void __fill(ForwardIterator first, ForwardIterator last, const Type &value, forward_iterator_tag) {
		for (; first != last; ++first) {
			*first = value;
		}
	}

	template<typename ForwardIterator, typename Type>
	inline void fill(ForwardIterator first, ForwardIterator last, const Type &value) {
		ft::__fill(first, last, value, typename iterator_traits<ForwardIterator>::iterator_category());
	}

	template<bool BoolType>
	struct __equal {
		template<typename InputIterator1, typename InputIterator2>
		static bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
			for (; first1 != last1; ++first1, (void)++first2) {
				if (!(*first1 == *first2)) {
					return false;
				}
			}
			return true;
		}
	};

	template<>
	struct __equal<true> {
		template<typename Type>
		static bool equal(const Type *first1, const Type *last1, const Type *first2) {
			if (const size_t len = (last1 - first1)) {
				return !std::memcmp(first1, first2, sizeof(Type) * len);
			}
			return true;
		}
	};

	template<typename InputIterator1, typename InputIterator2>
	inline bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		typedef typename iterator_traits<InputIterator1>::value_type ValueType1;
		typedef typename iterator_traits<InputIterator2>::value_type ValueType2;
		const bool simple = ((is_integer<ValueType1>::value || is_pointer<ValueType1>::value)
							 && is_pointer<InputIterator1>::value && is_pointer<InputIterator2>::value
							 && are_same<ValueType1, ValueType2>::value);
		return ft::__equal<simple>::equal(first1, last1, first2);
	}

	template<typename InputIterator1, typename InputIterator2>
	inline bool equal_aux(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		typedef typename iterator_traits<InputIterator1>::value_type ValueType1;
		typedef typename iterator_traits<InputIterator2>::value_type ValueType2;
		const bool simple = ((is_integer<ValueType1>::value || is_pointer<ValueType1>::value)
				&& is_pointer<InputIterator1>::value && is_pointer<InputIterator2>::value
				&& are_same<ValueType1, ValueType2>::value);
		return ft::__equal<simple>::equal(first1, last1, first2);
	}

	template<typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		for (; first1 != last1; ++first1, (void)++first2) {
			if (first2 == last2 || *first2 < *first1) {
				return false;
			}
			else if (*first1 < *first2)
				return true;
		}
		return (first2 != last2);
	}

} // namespace ft

#endif