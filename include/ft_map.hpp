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

#ifndef FT_MAP_HPP
#define FT_MAP_HPP 1

#include "ft_stl/alloc_traits.hpp"
#include "ft_stl/type_traits.hpp"
#include "ft_stl/function.hpp"
#include "ft_pair.hpp"
#include "ft_tree.hpp"
#include <memory>
#include <map>

namespace ft {
	template<typename Key, typename TemplateType, typename Compare, typename Alloc>
	class multimap;

	template<typename Key, typename TemplateType, typename Compare = ft::less<Key>,
			typename Alloc = std::allocator<ft::pair<const Key, TemplateType> > >
	class map {
	public:
		typedef Key key_type;
		typedef TemplateType mapped_type;
		typedef ft::pair<const Key, TemplateType> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;

	public:
		class value_compare : public ft::binary_function<value_type, value_type, bool> {

		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) { }

		public:
			bool operator()(const value_type &x, const value_type &y) const { return comp(x.first, y.first); }
		};

	private:
		typedef typename alloc_traits<Alloc>::template rebind<value_type>::other PairAllocType;
		typedef RedBlackTree<key_type, value_type, SelectFirst<value_type>, key_compare> RedBlackTreeType;
		typedef alloc_traits<PairAllocType> AllocTraits;

		RedBlackTreeType tree;

	public:
		typedef typename AllocTraits::pointer pointer;
		typedef typename AllocTraits::const_pointer const_pointer;
		typedef typename AllocTraits::reference &reference;
		typedef typename AllocTraits::const_reference &const_reference;

		typedef typename RedBlackTreeType::iterator iterator;
		typedef typename RedBlackTreeType::const_iterator const_iterator;
		typedef typename RedBlackTreeType::size_type size_type;
		typedef typename RedBlackTreeType::difference_type difference_type;
		typedef typename RedBlackTreeType::reverse_iterator reverse_iterator;
		typedef typename RedBlackTreeType::const_reverse_iterator const_reverse_iterator;

		map() : tree() { }
		explicit map(const Compare &comp) : tree(comp) { }
		map(const map &x) : tree(x.tree) { }

		template<typename InputIterator>
		map(InputIterator first, InputIterator last) : tree() { tree._insert_range_unique(first, last); }

		template<typename InputIterator>
		map(InputIterator first, InputIterator last, const Compare &comp) : tree(comp) { tree._insert_range_unique(first, last); }

		map &operator=(const map &x) {
			tree = x.tree;
			return *this;
		}

		allocator_type get_allocator() const { return allocator_type(tree.get_allocator()); }

		iterator begin() { return tree.begin(); }
		const_iterator begin() const { return tree.begin(); }

		iterator end() { return tree.end(); }
		const_iterator end() const { return tree.end(); }

		reverse_iterator rbegin() { return tree.rbegin(); }
		const_reverse_iterator rbegin() const { return tree.rbegin(); }

		reverse_iterator rend() { return tree.rend(); }
		const_reverse_iterator rend() const { return tree.rend(); }

		bool empty() const { return tree.empty(); }
		size_type size() const { return tree.size(); }
		size_type max_size() const { return tree.max_size(); }
		mapped_type &operator[](const key_type &k) {
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				i = insert(i, value_type(k, mapped_type()));
			return (*i).second;
		}

		mapped_type &at(const key_type &k) {
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw("map::at");
			return (*i).second;
		}

		const mapped_type &at(const key_type &k) const {
			const_iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw("map::at");
			return (*i).second;
		}

		ft::pair<iterator, bool> insert(const value_type &x) { return tree._insert_unique(x); }

		iterator insert(iterator position, const value_type &x) {
			return tree._insert_unique(position, x);
		}

		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last) {
			tree.insert_range_unique(first, last);
		}

		void erase(iterator position) { tree.erase(position); }
		size_type erase(const key_type &x) { return tree.erase(x); }
		void erase(iterator first, iterator last) { tree.erase(first, last); }

		void swap(map &x) { tree.swap(x.tree); }

		void clear() { tree.clear(); }

		key_compare key_comp() const { return tree.key_comp(); }

		value_compare value_comp() const { return value_compare(tree.key_comp()); }

		iterator find(const key_type &x) { return tree.find(x); }
		const_iterator find(const key_type &x) const { return tree.find(x); }

		size_type count(const key_type &x) const { return tree.find(x) == tree.end() ? 0 : 1; }

		iterator lower_bound(const key_type &x) { return tree.lower_bound(x); }
		const_iterator lower_bound(const key_type &x) const { return tree.lower_bound(x); }

		iterator upper_bound(const key_type &x) { return tree.upper_bound(x); }
		const_iterator upper_bound(const key_type &x) const { return tree.upper_bound(x); }

		ft::pair<iterator, iterator> equal_range(const key_type &x) { return tree.equal_range(x); }
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &x) const {
			return tree.equal_range(x);
		}

		template<typename K1, typename T1, typename C1, typename A1>
		friend bool operator==(const map<K1, T1, C1, A1> &, const map<K1, T1, C1, A1> &);

		template<typename K1, typename T1, typename C1, typename A1>
		friend bool operator<(const map<K1, T1, C1, A1> &, const map<K1, T1, C1, A1> &);
	};

	template<typename Key, typename TemplateType, typename Compare, typename Alloc>
	inline bool operator==(const map<Key, TemplateType, Compare, Alloc> &x, const map<Key, TemplateType, Compare, Alloc> &y) {
		return x.tree == y.tree;
	}

	template<typename Key, typename TemplateType, typename Compare, typename Alloc>
	inline bool operator<(const map<Key, TemplateType, Compare, Alloc> &x, const map<Key, TemplateType, Compare, Alloc> &y) {
		return x.tree < y.tree;
	}

	template<typename Key, typename TemplateType, typename Compare, typename Alloc>
	inline bool operator!=(const map<Key, TemplateType, Compare, Alloc> &x, const map<Key, TemplateType, Compare, Alloc> &y) {
		return !(x == y);
	}

	template<typename Key, typename TemplateType, typename Compare, typename Alloc>
	inline bool operator>(const map<Key, TemplateType, Compare, Alloc> &x, const map<Key, TemplateType, Compare, Alloc> &y) {
		return y < x;
	}

	template<typename Key, typename TemplateType, typename Compare, typename Alloc>
	inline bool operator<=(const map<Key, TemplateType, Compare, Alloc> &x, const map<Key, TemplateType, Compare, Alloc> &y) {
		return !(y < x);
	}

	template<typename Key, typename TemplateType, typename Compare, typename Alloc>
	inline bool operator>=(const map<Key, TemplateType, Compare, Alloc> &x, const map<Key, TemplateType, Compare, Alloc> &y) {
		return !(x < y);
	}

	template<typename Key, typename TemplateType, typename Compare, typename Alloc>
	inline void swap(map<Key, TemplateType, Compare, Alloc> &x, map<Key, TemplateType, Compare, Alloc> &y) {
		x.swap(y);
	}

} // namespace ft

#endif