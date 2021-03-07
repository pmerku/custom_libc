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

#ifndef FT_MULTISET_HPP
#define FT_MULTISET_HPP 1

#include "ft_tree.hpp"
#include "ft_pair.hpp"
#include "ft_stl/function.hpp"
#include <memory>

namespace ft {
	template<typename Key, typename Compare, typename Alloc>
	class set;

	template<typename Key, typename Compare = ft::less<Key>, typename Alloc = std::allocator<Key> >
	class multiset {
	public:
		typedef Key key_type;
		typedef Key value_type;
		typedef Compare key_compare;
		typedef Compare value_compare;
		typedef Alloc allocator_type;

	private:
		typedef typename alloc_traits<Alloc>::template rebind<Key>::other KeyAllocType;
		typedef RedBlackTree<key_type, value_type, Identity<value_type>, key_compare, KeyAllocType> RedBlackTreeType;
		typedef alloc_traits<KeyAllocType> AllocTraits;

		RedBlackTreeType tree;

	public:
		typedef typename AllocTraits::pointer pointer;
		typedef typename AllocTraits::const_pointer const_pointer;
		typedef typename AllocTraits::reference reference;
		typedef typename AllocTraits::const_reference const_reference;

		typedef typename RedBlackTreeType::const_iterator iterator;
		typedef typename RedBlackTreeType::const_iterator const_iterator;
		typedef typename RedBlackTreeType::const_reverse_iterator reverse_iterator;
		typedef typename RedBlackTreeType::const_reverse_iterator const_reverse_iterator;
		typedef typename RedBlackTreeType::size_type size_type;
		typedef typename RedBlackTreeType::difference_type difference_type;

		multiset() : tree() { }

		explicit multiset(const Compare &comp) : tree(comp) { }

		template<typename InputIterator>
		multiset(InputIterator first, InputIterator last) : tree() {
			tree._insert_range_equal(first, last);
		}

		template <typename InputIterator>
		multiset(InputIterator first, InputIterator last, const Compare &comp) : tree(comp) {
			tree._insert_range_equal(first, last);
		}

		multiset(const multiset &x) : tree(x.tree) { }

		multiset &operator=(const multiset &x) {
			tree = x.tree;
			return *this;
		}

		key_compare key_comp() const { return tree.key_comp(); }

		value_compare value_comp() const { return tree.key_comp(); }

		allocator_type get_allocator() const { return allocator_type(tree.get_allocator()); }

		iterator begin() const { return tree.begin(); }

		iterator end() const { return tree.end(); }

		reverse_iterator rbegin() const { return tree.rbegin(); }

		reverse_iterator rend() const { return tree.rend(); }

		bool empty() const { return tree.empty(); }

		size_type size() const { return tree.size(); }

		size_type max_size() const { return tree.max_size(); }

		void swap(multiset &x) { tree.swap(x.tree); }

		iterator insert(const value_type &x) { return tree._insert_equal(x); }
		iterator insert(const_iterator position, const value_type &x) {
			return tree._insert_equal(position, x);
		}

		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last) {
			tree._insert_range_equal(first, last);
		}

		void erase(iterator position) { tree.erase(position); }
		size_type erase(const key_type &x) { return tree.erase(x); }
		void erase(iterator first, iterator last) { tree.erase(first, last); }

		void clear() { tree.clear(); }
		size_type count(const key_type &x) const { return tree.count(x); }

		iterator find(const key_type &x) { return tree.find(x); }
		const_iterator find(const key_type &x) const { return tree.find(x); }

		iterator lower_bound(const key_type &x) { return tree.lower_bound(x); }
		const_iterator lower_bound(const key_type &x) const { return tree.lower_bound(x); }

		iterator upper_bound(const key_type &x) { return tree.upper_bound(x); }
		const_iterator upper_bound(const key_type &x) const { return tree.upper_bound(x); }

		ft::pair<iterator, iterator> equal_range(const key_type &x) { return tree.equal_range(x); }
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &x) const {
			return tree.equal_range(x);
		}

		template<typename K1, typename C1, typename A1>
		friend bool operator==(const multiset<K1, C1, A1> &, const multiset<K1, C1, A1> &);

		template<typename K1, typename C1, typename A1>
		friend bool operator<(const multiset<K1, C1, A1> &, const multiset<K1, C1, A1> &);
	};

	template<typename Key, typename Compare, typename Alloc>
	inline bool operator==(const multiset<Key, Compare, Alloc> &x, const multiset<Key, Compare, Alloc> &y) {
		return x.tree == y.tree;
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool operator<(const multiset<Key, Compare, Alloc> &x, const multiset<Key, Compare, Alloc> &y) {
		return x.tree < y.tree;
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool operator!=(const multiset<Key, Compare, Alloc> &x, const multiset<Key, Compare, Alloc> &y) {
		return !(x == y);
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool operator>(const multiset<Key, Compare, Alloc> &x, const multiset<Key, Compare, Alloc> &y) {
		return y < x;
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool operator<=(const multiset<Key, Compare, Alloc> &x, const multiset<Key, Compare, Alloc> &y) {
		return !(y < x);
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool operator>=(const multiset<Key, Compare, Alloc> &x, const multiset<Key, Compare, Alloc> &y) {
		return !(x < y);
	}

	template<typename Key, typename Compare, typename Alloc>
	inline void swap(multiset<Key, Compare, Alloc> &x, multiset<Key, Compare, Alloc> &y) {
		x.swap(y);
	}

} // namespace ft

#endif