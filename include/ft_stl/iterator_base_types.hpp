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

#ifndef ITERATOR_BASE_TYPES
#define ITERATOR_BASE_TYPES 1

#include <cstddef>

namespace ft {

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template<typename Category, typename Type, typename Distance = ptrdiff_t,
			typename Pointer = Type*, typename Reference = Type&>
	struct iterator {
		typedef Category	iterator_category;
		typedef Type		value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	template<typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template<typename Type>
	struct iterator_traits<Type*> {
		typedef random_access_iterator_tag	iterator_category;
		typedef Type						value_type;
		typedef ptrdiff_t 					difference_type;
		typedef Type						*pointer;
		typedef Type						&reference;
	};

	template<typename Type>
	struct iterator_traits<const Type*> {
		typedef random_access_iterator_tag	iterator_category;
		typedef Type						value_type;
		typedef ptrdiff_t 					difference_type;
		typedef const Type					*pointer;
		typedef const Type					&reference;
	};

	template<typename Iter>
	inline typename iterator_traits<Iter>::iterator_category get_iterator_category(const Iter&) {
		return typename iterator_traits<Iter>::iterator_category();
	}

	template<typename Iterator, bool HasBase>
	struct IterBase {
		typedef Iterator iterator_type;
		static iterator_type self_base(Iterator it) { return it; }
	};

	template<typename Iterator>
	struct IterBase<Iterator, true> {
		typedef typename Iterator::iterator_type iterator_type;
		static iterator_type self_base(Iterator it) { return it.base(); }
	};

} // namespace ft

#endif