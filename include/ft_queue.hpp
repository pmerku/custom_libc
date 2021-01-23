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

#ifndef FT_QUEUE_HPP
#define FT_QUEUE_HPP 1

#include "ft_deque.hpp"

namespace ft {

	template<typename Type, typename Sequence = deque<Type> >
	class queue {
		template<typename Type1, typename Sequence1>
		friend bool operator==(const queue<Type1, Sequence1> &, const queue<Type1, Sequence1> &);

		template<typename Type1, typename Sequence1>
		friend bool operator<(const queue<Type1, Sequence1> &, const queue<Type1, Sequence1> &);

	public:
		typedef typename Sequence::value_type value_type;
		typedef typename Sequence::reference reference;
		typedef typename Sequence::const_reference const_reference;
		typedef typename Sequence::size_type size_type;
		typedef Sequence container_type;

	protected:
		Sequence sequence;

	public:
		explicit queue(const Sequence &c = Sequence()) : sequence(c) { }

		bool empty() const { return sequence.empty(); }

		size_type size() const { return sequence.size(); }

		reference front() { return sequence.front(); }

		const_reference front() const { return sequence.front(); }

		reference back() { return sequence.back(); }

		const_reference back() const { return sequence.back(); }

		void push(const value_type &x) { sequence.push_back(x); }

		void pop() { sequence.pop_front(); }
	};

	template<typename Type, typename Sequence>
	inline bool operator==(const queue<Type, Sequence> &x, const queue<Type, Sequence> &y) {
		return x.sequence == y.sequence;
	}

	template<typename Type, typename Sequence>
	inline bool operator<(const queue<Type, Sequence> &x, const queue<Type, Sequence> &y) {
		return x.sequence < y.sequence;
	}

	template<typename Type, typename Sequence>
	inline bool operator!=(const queue<Type, Sequence> &x, const queue<Type, Sequence> &y) {
		return !(x == y);
	}

	template<typename Type, typename Sequence>
	inline bool operator>(const queue<Type, Sequence> &x, const queue<Type, Sequence> &y) {
		return y < x;
	}

	template<typename Type, typename Sequence>
	inline bool operator<=(const queue<Type, Sequence> &x, const queue<Type, Sequence> &y) {
		return !(y < x);
	}

	template<typename Type, typename Sequence>
	inline bool operator>=(const queue<Type, Sequence> &x, const queue<Type, Sequence> &y) {
		return !(x < y);
	}

} // namespace ft

#endif