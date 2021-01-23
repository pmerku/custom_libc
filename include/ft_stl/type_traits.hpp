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

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP 1

namespace ft {

	struct true_type { };
	struct false_type { };

	template<bool>
	struct truth_type { typedef false_type type; };

	template<>
	struct truth_type<true> { typedef true_type type; };

	template<typename Sp, typename Type>
	struct traitor {
		enum { value = bool(Sp::value) || bool(Type::value) };
		typedef typename truth_type<value>::type type;
	};

	template<typename, typename>
	struct are_same {
		enum { value = 0 };
		typedef false_type type;
	};

	template<typename Type>
	struct are_same<Type, Type> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename Type>
	struct is_void {
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_void<void> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename Type>
	struct is_integer {
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_integer<bool> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<char> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<signed char> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned char> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<wchar_t> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<short> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned short> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<int> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned int> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<long> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned long> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<long long> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned long long> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename Type>
	struct is_floating {
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_floating<float> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_floating<double> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_floating<long double> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename Type>
	struct is_pointer {
		enum { value = 0 };
		typedef false_type type;
	};

	template<typename Type>
	struct is_pointer<Type*> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename Type>
	struct is_arithmetic : public traitor<is_integer<Type>, is_floating<Type> > { };

	template<typename Type>
	struct is_scalar : public traitor<is_arithmetic<Type>, is_pointer<Type> > { };

	template<typename Type>
	struct is_char {
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_char<char> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_char<wchar_t> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename Type>
	struct is_byte {
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_byte<char> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_byte<signed char> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_byte<unsigned char> {
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename Type>
	struct is_move_iterator {
		enum { value = 0 };
		typedef false_type type;
	};

	template<bool, typename> struct enable_if { };

	template<typename Type> struct enable_if<true, Type> { typedef Type type; };

	template<bool Cond, typename Iftrue, typename Iffalse> struct conditional_type { typedef Iftrue type; };

	template<typename Iftrue, typename Iffalse> struct conditional_type<false, Iftrue, Iffalse> { typedef Iffalse type; };

} // namespace ft

#endif