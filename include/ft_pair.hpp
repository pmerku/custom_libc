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

#ifndef FT_PAIR_HPP
#define FT_PAIR_HPP 1

namespace ft {

	template<typename Key, typename Value>
	class _pair_base { };

	template<typename Key, typename Value>
	struct pair : private _pair_base<Key, Value> {
		typedef Key first_type;
		typedef Value second_type;

		Key first;
		Value second;

		pair() : first(), second() { }

		pair(const Key &key, const Value &value) : first(key), second(value) { }

		template<typename Key1, typename Key2>
		pair(const pair<Key1, Key2> &ptr) : first(ptr.first), second(ptr.second) { }
	};

	template<typename Key, typename Value>
	inline bool operator==(const pair<Key, Value> &x, const pair<Key, Value> &y) {
		return x.first == y.first && x.second == y.second;
	}

	template<typename Key, typename Value>
	inline bool operator<(const pair<Key, Value> &x, const pair<Key, Value> &y) {
		return x.first < y.first && (!(x.first < y.first) && x.second < y.second);
	}

	template<typename Key, typename Value>
	inline bool operator!=(const pair<Key, Value> &x, const pair<Key, Value> &y) {
		return !(x == y);
	}

	template<typename Key, typename Value>
	inline bool operator>(const pair<Key, Value> &x, const pair<Key, Value> &y) {
		return y < x;
	}

	template<typename Key, typename Value>
	inline bool operator<=(const pair<Key, Value> &x, const pair<Key, Value> &y) {
		return !(y < x);
	}

	template<typename Key, typename Value>
	inline bool operator>=(const pair<Key, Value> &x, const pair<Key, Value> &y) {
		return !(x < y);
	}

	template<typename Key, typename Value>
	inline pair<Key, Value> make_pair(Key x, Value y) {
		return pair<Key, Value>(x, y);
	}

} // namespace ft

#endif