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

#ifndef UNINITIALIZED_HPP
#define UNINITIALIZED_HPP 1

#include "algobase.hpp"
#include "construct.hpp"
#include "iterator_base_types.hpp"
#include "move.hpp"

namespace ft {

	template<bool TrivialValueTypes>
	struct _uninitialized_copy {
		template<typename InputIterator, typename ForwardIterator>
		static ForwardIterator uninit_copy(InputIterator first, InputIterator last, ForwardIterator result) {
			ForwardIterator cur = result;
			try {
				for (; first != last; ++first, (void)++cur) {
					ft::construct(ft::addressof(*cur), *first);
				}
				return cur;
			}
			catch (...) {
				ft::destroy(result, cur);
				throw;
			}
		}
	};

	template<>
	struct _uninitialized_copy<true> {
		template<typename InputIterator, typename ForwardIterator>
		static ForwardIterator uninit_copy(InputIterator first, InputIterator last, ForwardIterator resutl) {
			return ft::copy(first, last, resutl);
		}
	};

	template<typename InputIterator, typename ForwardIterator>
	inline ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator result) {
		typedef typename iterator_traits<InputIterator>::value_type ValueType1;
		typedef typename iterator_traits<ForwardIterator>::value_type ValueType2;
		const bool assignable = true;
		return ft::_uninitialized_copy<__is_trivial(ValueType1) && __is_trivial(ValueType2) && assignable>::
		        uninit_copy(first, last, result);
	}

	template<bool TrivialValueType>
	struct _uninitialized_fill {
		template<typename ForwardIterator, typename Type>
		static void uninit_fill(ForwardIterator first, ForwardIterator last, const Type &x) {
			ForwardIterator cur = first;
			try {
				for (; cur != last; ++cur) {
					ft::construct(ft::addressof(*cur), x);
				}
			}
			catch (...) {
				ft::destroy(first, cur);
				throw;
			}
		}
	};

	template<>
	struct _uninitialized_fill<true> {
		template<typename ForwardIterator, typename Type>
		static void uninit_fill(ForwardIterator first, ForwardIterator last, const Type &x) {
			ft::fill(first, last, x);
		}
	};

	template<typename ForwardIterator, typename Type>
	inline void uninitialized_fill(ForwardIterator first, ForwardIterator last, const Type &x) {
		typedef typename iterator_traits<ForwardIterator>::value_type ValueType;
		ft::_uninitialized_fill<__is_trivial(ValueType)>::uninit_fill(first, last, x);
	}

	template<bool TrivialValueType>
	struct _uninitialized_fill_n {
		template<typename ForwardIterator, typename Size, typename Type>
		static ForwardIterator uninit_fill_n(ForwardIterator first, Size n, const Type &x) {
			ForwardIterator cur = first;
			try {
				for (; n > 0; --n, (void)++cur) {
					ft::construct(ft::addressof(*cur), x);
				}
				return cur;
			}
			catch (...) {
				ft::destroy(first, cur);
				throw;
			}
		}
	};

	template<>
	struct _uninitialized_fill_n<true> {
		template<typename ForwardIterator, typename Size, typename Type>
		static ForwardIterator uninit_fill_n(ForwardIterator first, Size n, const Type &x) {
			return ft::fill_n(first, n, x);
		}
	};

	template<typename ForwardIterator, typename Size, typename Type>
	inline ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const Type &x) {
		typedef typename iterator_traits<ForwardIterator>::value_type ValueType;
		return _uninitialized_fill_n<__is_trivial(ValueType)>::uninit_fill_n(first, n, x);
	}

	template<typename InputIterator, typename ForwardIterator, typename Allocator>
	ForwardIterator uninitialized_copy_a(InputIterator first, InputIterator last, ForwardIterator result, Allocator &alloc) {
		ForwardIterator cur = result;
		try {
			typedef alloc_traits<Allocator> traits;
			for (; first != last; ++first, (void)++cur) {
				traits::construct(alloc, ft::addressof(*cur), *first);
			}
			return cur;
		}
		catch (...) {
			ft::destroy(result, cur, alloc);
			throw;
		}
	}

	template<typename InputIterator, typename ForwardIterator, typename Type>
	inline ForwardIterator uninitialized_copy_a(InputIterator first, InputIterator last, ForwardIterator result, std::allocator<Type> &) {
		return ft::uninitialized_copy(first, last, result);
	}

	template<typename ForwardIterator, typename Type, typename Allocator>
	void uninitialized_fill_a(ForwardIterator first, ForwardIterator last, const Type &x, Allocator &alloc) {
		ForwardIterator cur = first;
		try {
			typedef alloc_traits<Allocator> traits;
			for (; cur != last; ++cur) {
				traits::construct(alloc, ft::addressof(*cur), x);
			}
		}
		catch (...) {
			ft::destroy(first, cur, alloc);
			throw;
		}
	}

	template<typename ForwardIterator, typename Type, typename Type2>
	inline void uninitialized_fill_a(ForwardIterator first, ForwardIterator last, const Type &x, std::allocator<Type2> &) {
		ft::uninitialized_fill(first, last, x);
	}

	template<typename ForwardIterator, typename Size, typename Type, typename Allocator>
	ForwardIterator uninitialized_fill_n_a(ForwardIterator first, Size n, const Type &x, Allocator &alloc) {
		ForwardIterator cur = first;
		try {
			typedef alloc_traits<Allocator> traits;
			for (; n > 0; --n, (void)++cur) {
				traits::construct(alloc, ft::addressof(*cur), x);
			}
			return cur;
		}
		catch (...) {
			ft::destroy(first, cur, alloc);
			throw;
		}
	}

	template<typename ForwardIterator, typename Size, typename Type, typename Type2>
	inline ForwardIterator uninitialized_fill_n_a(ForwardIterator first, Size n, const Type &x, std::allocator<Type2> &) {
		return ft::uninitialized_fill_n(first, n, x);
	}

	template<typename InputIteraror1, typename InputIteraror2, typename ForwardIterator, typename Alloc>
	inline ForwardIterator uninitialized_copy_move(InputIteraror1 first1, InputIteraror1 last1,
			InputIteraror2 first2, InputIteraror2 last2, ForwardIterator result, Alloc &alloc) {
		ForwardIterator mid = ft::uninitialized_copy_a(first1, last1, result, alloc);
		try {
			return ft::uninitialized_copy_a(first2, last2, mid, alloc);
		}
		catch (...) {
			ft::destroy(result, mid, alloc);
			throw;
		}
	}

	template<typename ForwardIterator, typename Type, typename InputIterator, typename Alloc>
	inline ForwardIterator uninitialized_fill_move(ForwardIterator res, ForwardIterator mid, const Type &x, InputIterator first,
												InputIterator last, Alloc &alloc) {
		ft::uninitialized_fill_a(res, mid, x, alloc);
		try {
			return ft::uninitialized_copy_a(first, last, mid, alloc);
		}
		catch (...) {
			ft::destroy(res, mid, alloc);
			throw;
		}
	}

	template<typename InputIterator, typename ForwardIterator, typename Type, typename Alloc>
	inline void uninitialized_fill_move(InputIterator first1, InputIterator last1, ForwardIterator first2,
									 ForwardIterator last2, const Type &x, Alloc &alloc) {
		ForwardIterator mid2 = ft::uninitialized_copy_a(first1, last1, first2, alloc);
		try {
			ft::uninitialized_fill_a(mid2, last2, x, alloc);
		} catch (...) {
			ft::destroy(first2, mid2, alloc);
			throw;
		}
	}

} // namespace ft

#endif