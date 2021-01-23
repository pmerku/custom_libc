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

#ifndef FUNCTION_HPP
#define FUNCTION_HPP 1

#include <cstddef>

namespace ft {

	template<typename Argument, typename Result>
	struct unary_function {
		typedef Argument argument_type;
		typedef Result result_type;
	};

	template<typename Arg1, typename Arg2, typename Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template<typename Type>
	struct plus : public binary_function<Type, Type, Type> {
		Type operator()(const Type &x, const Type &y) const { return x + y; }
	};

	template<typename Type>
	struct minus : public binary_function<Type, Type, Type> {
		Type operator()(const Type &x, const Type &y) const { return x - y; }
	};

	template<typename Type>
	struct multiples : public binary_function<Type, Type, Type> {
		Type operator()(const Type &x, const Type &y) const { return x * y; }
	};

	template<typename Type>
	struct divides : public binary_function<Type, Type, Type> {
		Type operator()(const Type &x, const Type &y) const { return x / y; }
	};

	template<typename Type>
	struct modulus : public binary_function<Type, Type, Type> {
		Type operator()(const Type &x, const Type &y) const { return x % y; }
	};

	template<typename Type>
	struct negate : public unary_function<Type, Type> {
		Type operator()(const Type &x) const { return -x; }
	};

	template<typename Type>
	struct equal_to : public binary_function<Type, Type, bool> {
		bool operator()(const Type &x, const Type &y) const { return x == y; }
	};

	template<typename Type>
	struct not_equal_to : public binary_function<Type, Type, bool> {
		bool operator()(const Type &x, const Type &y) const { return x != y; }
	};

	template<typename Type>
	struct greater : public binary_function<Type, Type, bool> {
		bool operator()(const Type &x, const Type &y) const { return x > y; }
	};

	template<typename Type>
	struct less : public binary_function<Type, Type, bool> {
		bool operator()(const Type &x, const Type &y) const { return x < y; }
	};

	template<typename Type>
	struct greater_equal : public binary_function<Type, Type, bool> {
		bool operator()(const Type &x, const Type &y) const { return x >= y; }
	};

	template<typename Type>
	struct less_equal : public binary_function<Type, Type, bool> {
		bool operator()(const Type &x, const Type &y) const { return x <= y; }
	};

	template<typename Type>
	struct greater<Type*> : public binary_function<Type*, Type*, bool> {
		bool operator()(Type *x, Type *y) const { return (ptrdiff_t)x > (ptrdiff_t)y; }
	};

	template<typename Type>
	struct less<Type*> : public binary_function<Type*, Type*, bool> {
		bool operator()(Type *x, Type *y) const { return (ptrdiff_t)x < (ptrdiff_t)y; }
	};

	template<typename Type>
	struct greater_equal<Type*> : public binary_function<Type*, Type*, bool> {
		bool operator()(Type *x, Type *y) const { return (ptrdiff_t)x >= (ptrdiff_t)y; }
	};

	template<typename Type>
	struct less_equal<Type*> : public binary_function<Type*, Type*, bool> {
		bool operator()(Type *x, Type *y) const { return (ptrdiff_t)x <= (ptrdiff_t)y; }
	};

	template<typename Type>
	struct logical_and : public binary_function<Type, Type, bool> {
		bool operator()(const Type &x, const Type &y) const { return x && y; }
	};

	template<typename Type>
	struct logical_or : public binary_function<Type, Type, bool> {
		bool operator()(const Type &x, const Type &y) const { return x || y; }
	};

	template<typename Type>
	struct logical_not : public unary_function<Type, bool> {
		bool operator()(const Type &x) const { return !x; }
	};

	template<typename Type>
	struct bit_and : public binary_function<Type, Type, Type> {
		Type operator()(const Type &x, const Type &y) const { return x & y; }
	};

	template<typename Type>
	struct bit_or : public binary_function<Type, Type, Type> {
		Type operator()(const Type &x, const Type &y) const { return x | y; }
	};

	template<typename Type>
	struct bit_xor : public binary_function<Type, Type, Type> {
		Type operator()(const Type &x, const Type &y) const { return x ^ y; }
	};

	template<typename Type>
	struct bit_not : public unary_function<Type, Type> {
		Type operator()(const Type &x) const { return ~x; }
	};

	template<typename Type>
	struct Identity : public unary_function<Type, Type> {
		Type &operator()(Type &x) const { return x; }
		const Type &operator()(const Type &x) const { return x; }
	};

	template<typename Type>
	struct Identity<const Type> : Identity<Type> { };

	template<typename Pair>
	struct SelectFirst : public unary_function<Pair, typename Pair::first_type> {
		typename Pair::first_type &operator()(Pair &x) const { return x.first; }
		const typename Pair::first_type &operator()(const Pair &x) const { return x.first; }
	};

	template<typename Pair>
	struct SelectSecond : public unary_function<Pair, typename Pair::second_type> {
		typename Pair::second_type &operator()(Pair &x) const { return x.second; }
		const typename Pair::second_type &operator()(const Pair &x) const { return x.second; }
	};

} // namespace ft

#endif