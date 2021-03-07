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

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP 1

#include "ft_stl/alloc_traits.hpp"
#include "ft_stl/algobase.hpp"
#include "ft_stl/iterator_base_types.hpp"
#include "ft_stl/iterator_base_funcs.hpp"
#include "ft_stl/iterator.hpp"
#include "ft_stl/move.hpp"
#include "ft_stl/type_traits.hpp"
#include <cstddef>
#include <memory>

namespace ft {

	namespace __base {

		struct ListNodeBase {
			ListNodeBase *next;
			ListNodeBase *prev;

			static void swap(ListNodeBase &x, ListNodeBase &y) {
				if (x.next != &x) {
					if (y.next != &y) {
						ft::swap(x.next, y.next);
						ft::swap(x.prev, y.prev);
						x.next->prev = x.prev->next = &x;
						y.next->prev = y.prev->next = &y;
					} else {
						y.next = x.next;
						y.prev = x.prev;
						y.next->prev = y.prev->next = &y;
						x.next = x.prev = &x;
					}
				} else if (y.next != &y) {
					x.next = y.next;
					x.prev = y.prev;
					x.next->prev = x.prev->next = &x;
					y.next = y.prev = &y;
				}
			}

			void _transfer(ListNodeBase *const first, ListNodeBase *const last) {
				if (this != last) {
					last->prev->next = this;
					first->prev->next = last;
					this->prev->next = first;

					ListNodeBase *const tmp = this->prev;
					this->prev = last->prev;
					last->prev = first->prev;
					first->prev = tmp;
				}
			}

			void _reverse() {
				ListNodeBase *tmp = this;

				do {
					ft::swap(tmp->next, tmp->prev);
					tmp = tmp->prev;
				} while (tmp != this);
			}

			void _hook(ListNodeBase *const position) {
				this->next = position;
				this->prev = position->prev;
				position->prev->next = this;
				position->prev = this;
			}

			void _unhook() {
				ListNodeBase *const next_node = this->next;
				ListNodeBase *const prev_node = this->prev;
				prev_node->next = next_node;
				next_node->prev = prev_node;
			}
		};

		struct ListNodeHeader : public ListNodeBase {
			ListNodeHeader() { _init(); }
			void _init() { this->next = this->prev = this; }

		private:
			ListNodeBase *_base() { return this; }
		};

	} // namespace __base

	template<typename Type>
	struct ListNode : public __base::ListNodeBase {
		Type data;
		Type *_valptr() { return ft::addressof(data); }
		Type const *_valptr() const { return ft::addressof(data); }
	};

	template<typename Type>
	struct ListIterator {
		typedef ListIterator<Type> _Self;
		typedef ListNode<Type> Node;

		typedef ptrdiff_t difference_type;
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef Type value_type;
		typedef Type *pointer;
		typedef Type &reference;

		ListIterator() : _node() { }
		explicit ListIterator(__base::ListNodeBase *x) : _node(x) { }

		_Self _const_cast() const { return *this; }

		reference operator*() const { return *static_cast<Node *>(_node)->_valptr(); }
		pointer operator->() const { return static_cast<Node *>(_node)->_valptr(); }

		_Self &operator++() {
			_node = _node->next;
			return *this;
		}

		_Self operator++(int) {
			_Self tmp = *this;
			_node = _node->next;
			return tmp;
		}

		_Self &operator--() {
			_node = _node->prev;
			return *this;
		}

		_Self operator--(int) {
			_Self tmp = *this;
			_node = _node->prev;
			return tmp;
		}

		bool operator==(const _Self &x) const { return _node == x._node; }
		bool operator!=(const _Self &x) const { return _node != x._node; }

		__base::ListNodeBase *_node;
	};

	template<typename Type>
	struct ListConstIterator {
		typedef ListConstIterator<Type> _Self;
		typedef const ListNode<Type> Node;
		typedef ListIterator<Type> iterator;

		typedef ptrdiff_t difference_type;
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef Type value_type;
		typedef const Type *pointer;
		typedef const Type &reference;

		ListConstIterator() : _node() { }

		explicit ListConstIterator(const __base::ListNodeBase *x) : _node(x) { }
		ListConstIterator(const iterator &x) : _node(x._node) { }
		iterator _const_cast() const { return iterator(const_cast<__base::ListNodeBase *>(_node)); }

		reference operator*() const { return *static_cast<Node *>(_node)->_valptr(); }
		pointer operator->() const { return static_cast<Node *>(_node)->_valptr(); }

		_Self &operator++() {
			_node = _node->next;
			return *this;
		}

		_Self operator++(int) {
			_Self tmp = *this;
			_node = _node->next;
			return tmp;
		}

		_Self &operator--() {
			_node = _node->prev;
			return *this;
		}

		_Self operator--(int) {
			_Self tmp = *this;
			_node = _node->prev;
			return tmp;
		}

		bool operator==(const _Self &x) const { return _node == x._node; }
		bool operator!=(const _Self &x) const { return _node != x._node; }

		const __base::ListNodeBase *_node;
	};

	template<typename _Val>
	inline bool operator==(const ListIterator<_Val> &x, const ListConstIterator<_Val> &y) {
		return x._node == y._node;
	}

	template<typename _Val>
	inline bool operator!=(const ListIterator<_Val> &x, const ListConstIterator<_Val> &y) {
		return x._node != y._node;
	}

	template<typename Type, typename Alloc>
	class ListBase {
	protected:
		typedef typename alloc_traits<Alloc>::template rebind<Type>::other AllocType;
		typedef alloc_traits<AllocType> AllocTypeTraits;

		typedef typename AllocTypeTraits::template rebind<ListNode<Type> >::other NodeAllocType;
		typedef alloc_traits<NodeAllocType> NodeAllocTraits;

		static size_t self_distance(const __base::ListNodeBase *first, const __base::ListNodeBase *last) {
			size_t num = 0;

			while (first != last) {
				first = first->next;
				++num;
			}

			return num;
		}

		struct ListImpl : public NodeAllocType {
			__base::ListNodeHeader _node;
			ListImpl() : NodeAllocType() { }
			ListImpl(const NodeAllocType &__a) : NodeAllocType(__a) {}
		};

		ListImpl impl;

		size_t _get_size() const { return 0; }
		void _set_size(size_t) { }
		void _inc_size(size_t) { }
		void _dec_size(size_t) { }

		typename NodeAllocTraits::pointer _get_node() { return NodeAllocTraits::allocate(impl, 1); }
		void _put_node(typename NodeAllocTraits::pointer ptr) { NodeAllocTraits::deallocate(impl, ptr, 1); }

	public:
		typedef Alloc allocator_type;

		NodeAllocType &_get_node_allocator() { return impl; }
		const NodeAllocType &_get_node_allocator() const { return impl; }

		ListBase() {}
		ListBase(const NodeAllocType &alloc) : impl(alloc) { }
		~ListBase() { _clear(); }

		void _clear();
		void _init() { this->impl._node._init(); }
	};

	template<typename Type, typename Alloc = std::allocator<Type> >
	class list : protected ListBase<Type, Alloc> {
		typedef ListBase<Type, Alloc> Base;
		typedef typename Base::AllocType AllocType;
		typedef typename Base::AllocTypeTraits AllocTypeTraits;
		typedef typename Base::NodeAllocType NodeAllocType;
		typedef typename Base::NodeAllocTraits NodeAllocTraits;

	public:
		typedef Type value_type;
		typedef typename AllocTypeTraits::pointer pointer;
		typedef typename AllocTypeTraits::const_pointer const_pointer;
		typedef typename AllocTypeTraits::reference reference;
		typedef typename AllocTypeTraits::const_reference const_reference;

		typedef ListIterator<Type> iterator;
		typedef ListConstIterator<Type> const_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Alloc allocator_type;

	protected:
		typedef ListNode<Type> Node;

		using Base::_get_node;
		using Base::_get_node_allocator;
		using Base::impl;
		using Base::_put_node;

		Node *_create_node(const value_type &x) {
			Node *ptr = this->_get_node();

			try {
				AllocType alloc(_get_node_allocator());
				alloc.construct(ptr->_valptr(), x);
			} catch (...) {
				_put_node(ptr);
				throw;
			}

			return ptr;
		}

		static size_t self_distance(const_iterator, const_iterator) { return 0; }
		size_t _node_count() const { return ft::distance(begin(), end()); }

	public:
		list() { }

		explicit list(const allocator_type &__a) : Base(NodeAllocType(__a)) { }
		explicit list(size_type num, const value_type &value = value_type(), const allocator_type &alloc = allocator_type())
				: Base(NodeAllocType(alloc)) {
			_fill_initialize(num, value);
		}

		list(const list &x) : Base(NodeAllocTraits::self_select_on_copy(x._get_node_allocator())) {
			_initialize_dispatch(x.begin(), x.end(), false_type());
		}

		template<typename InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
				: Base(NodeAllocType(alloc)) {
			typedef typename ft::is_integer<InputIterator>::type Integral;
			_initialize_dispatch(first, last, Integral());
		}

		list &operator=(const list &x);
		void assign(size_type num, const value_type &value) { _fill_assign(num, value); }

		template<typename InputIterator>
		void assign(InputIterator first, InputIterator last) {
			typedef typename ft::is_integer<InputIterator>::type Integral;
			_assign_dispatch(first, last, Integral());
		}

		allocator_type get_allocator() const { return allocator_type(Base::_get_node_allocator()); }

		iterator begin() { return iterator(this->impl._node.next); }
		const_iterator begin() const { return const_iterator(this->impl._node.next); }

		iterator end() { return iterator(&this->impl._node); }
		const_iterator end() const { return const_iterator(&this->impl._node); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		bool empty() const { return this->impl._node.next == &this->impl._node; }

		size_type size() const { return _node_count(); }
		size_type max_size() const { return NodeAllocTraits::max_size(_get_node_allocator()); }

		void resize(size_type new_size, value_type x = value_type());

		reference front() { return *begin(); }
		const_reference front() const { return *begin(); }

		reference back() {
			iterator tmp = end();
			--tmp;
			return *tmp;
		}

		const_reference back() const {
			const_iterator tmp = end();
			--tmp;
			return *tmp;
		}

		void push_front(const value_type &x) { this->_insert(begin(), x); }

		void pop_front() { this->_erase(begin()); }

		void push_back(const value_type &x) { this->_insert(end(), x); }

		void pop_back() { this->_erase(iterator(this->impl._node.prev)); }

		iterator insert(iterator position, const value_type &x);
		void insert(iterator position, size_type num, const value_type &x) {
			list tmp(num, x, get_allocator());
			splice(position, tmp);
		}

		template<typename InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {
			list tmp(first, last, get_allocator());
			splice(position, tmp);
		}

		iterator erase(iterator position);
		iterator erase(iterator first, iterator last) {
			while (first != last)
				first = erase(first);
			return last._const_cast();
		}

		void swap(list &x) {
			__base::ListNodeBase::swap(this->impl._node, x.impl._node);
			size_t xsize = x._get_size();
			x._set_size(this->_get_size());
			this->_set_size(xsize);
			NodeAllocTraits::self_on_swap(this->_get_node_allocator(), x._get_node_allocator());
		}

		void clear() {
			Base::_clear();
			Base::_init();
		}

		void splice(iterator position, list &x) {
			if (!x.empty()) {
				this->_transfer(position._const_cast(), x.begin(), x.end());
				this->_inc_size(x._get_size());
				x._set_size(0);
			}
		}

		void splice(iterator position, list &x, iterator i) {
			iterator cpy = i._const_cast();
			++cpy;

			if (position == i || position == cpy)
				return;

			this->_transfer(position._const_cast(), i._const_cast(), cpy);
			this->_inc_size(1);
			x._dec_size(1);
		}

		void splice(iterator position, list &x, iterator first, iterator last) {
			if (first != last) {
				size_t num = self_distance(first, last);
				this->_inc_size(num);
				x._dec_size(num);

				this->_transfer(position._const_cast(), first._const_cast(), last._const_cast());
			}
		}

	private:
		typedef void remove_return_type;

	public:
		remove_return_type remove(const Type &value);
		template <typename Predicate> remove_return_type remove_if(Predicate);

		remove_return_type unique();
		template <typename BinaryPredicate> remove_return_type unique(BinaryPredicate);

		remove_return_type merge(list &x);
		template<typename StrictWeakOrdering>
		remove_return_type merge(list &x, StrictWeakOrdering comp);

		remove_return_type reverse() { this->impl._node._reverse(); }

		remove_return_type sort();
		template<typename StrictWeakOrdering>
		remove_return_type sort(StrictWeakOrdering);

	protected:
		template<typename Integer>
		void _initialize_dispatch(Integer num, Integer x, true_type) {
			_fill_initialize(static_cast<size_type>(num), x);
		}

		template<typename InputIterator>
		void _initialize_dispatch(InputIterator first, InputIterator last, false_type) {
			for (; first != last; ++first)
				push_back(*first);
		}

		void _fill_initialize(size_type num, const value_type &x) {
			for (; num; --num)
				push_back(x);
		}

		template<typename Integer>
		void _assign_dispatch(Integer num, Integer value, true_type) {
			_fill_assign(num, value);
		}

		template <typename InputIterator>
		void _assign_dispatch(InputIterator first, InputIterator last, false_type);

		void _fill_assign(size_type num, const value_type &value);

		void _transfer(iterator position, iterator first, iterator last) {
			position._node->_transfer(first._node, last._node);
		}

		void _insert(iterator position, const value_type &x) {
			Node *tmp = _create_node(x);
			tmp->_hook(position._node);
			this->_inc_size(1);
		}

		void _erase(iterator position) {
			this->_dec_size(1);
			position._node->_unhook();
			Node *node = static_cast<Node *>(position._node);
			AllocType(_get_node_allocator()).destroy(node->_valptr());
			_put_node(node);
		}

		const_iterator _resize_pos(size_type &new_size) const;
	};

	template<typename Type, typename Alloc>
	inline bool operator==(const list<Type, Alloc> &x, const list<Type, Alloc> &y) {
		typedef typename list<Type, Alloc>::const_iterator const_iterator;
		const_iterator end1 = x.end();
		const_iterator end2 = y.end();

		const_iterator iter1 = x.begin();
		const_iterator iter2 = y.begin();

		while (iter1 != end1 && iter2 != end2 && *iter1 == *iter2) {
			++iter1;
			++iter2;
		}

		return iter1 == end1 && iter2 == end2;
	}

	template<typename Type, typename Alloc>
	inline bool operator<(const list<Type, Alloc> &x, const list<Type, Alloc> &y) {
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template<typename Type, typename Alloc>
	inline bool operator!=(const list<Type, Alloc> &x, const list<Type, Alloc> &y) {
		return !(x == y);
	}

	template<typename Type, typename Alloc>
	inline bool operator>(const list<Type, Alloc> &x, const list<Type, Alloc> &y) {
		return y < x;
	}

	template<typename Type, typename Alloc>
	inline bool operator<=(const list<Type, Alloc> &x, const list<Type, Alloc> &y) {
		return !(y < x);
	}

	template<typename Type, typename Alloc>
	inline bool operator>=(const list<Type, Alloc> &x, const list<Type, Alloc> &y) {
		return !(x < y);
	}

	template<typename Type, typename Alloc>
	inline void swap(list<Type, Alloc> &x, list<Type, Alloc> &y) { x.swap(y); }

	template<typename Type, typename Alloc>
	void ListBase<Type, Alloc>::_clear() {
		typedef ListNode<Type> Node;
		__base::ListNodeBase *current = impl._node.next;
		while (current != &impl._node) {
			Node *tmp = static_cast<Node *>(current);
			current = tmp->next;
			Type *value = tmp->_valptr();
			AllocType(_get_node_allocator()).destroy(value);
			_put_node(tmp);
		}
	}

	template<typename Type, typename Alloc>
	typename list<Type, Alloc>::iterator list<Type, Alloc>::insert(iterator position, const value_type &x) {
		Node *tmp = _create_node(x);
		tmp->_hook(position._const_cast()._node);
		this->_inc_size(1);
		return iterator(tmp);
	}

	template<typename Type, typename Alloc>
	typename list<Type, Alloc>::iterator list<Type, Alloc>::erase(iterator position) {
		iterator ret = iterator(position._node->next);
		_erase(position._const_cast());
		return ret;
	}

	template<typename Type, typename Alloc>
	typename list<Type, Alloc>::const_iterator list<Type, Alloc>::_resize_pos(size_type &new_size) const {
		const_iterator i;
		size_type len = 0;

		for (i = begin(); i != end() && len < new_size; ++i, ++len)
			;

		new_size -= len;
		return i;
	}

	template<typename Type, typename Alloc>
	void list<Type, Alloc>::resize(size_type new_size, value_type x) {
		const_iterator i = _resize_pos(new_size);

		if (new_size)
			insert(end(), new_size, x);
		else
			erase(i._const_cast(), end());
	}

	template<typename Type, typename Alloc>
	list<Type, Alloc> &list<Type, Alloc>::operator=(const list &x) {
		if (this != &x) {
			_assign_dispatch(x.begin(), x.end(), false_type());
		}

		return *this;
	}

	template<typename Type, typename Alloc>
	void list<Type, Alloc>::_fill_assign(size_type num, const value_type &value) {
		iterator i = begin();

		for (; i != end() && num > 0; ++i, --num)
			*i = value;

		if (num > 0)
			insert(end(), num, value);
		else
			erase(i, end());
	}

	template<typename Type, typename Alloc>
	template<typename InputIterator>
	void list<Type, Alloc>::_assign_dispatch(InputIterator first2, InputIterator last2, false_type) {
		iterator first1 = begin();
		iterator last1 = end();

		for (; first1 != last1 && first2 != last2; ++first1, (void)++first2)
			*first1 = *first2;

		if (first2 == last2)
			erase(first1, last1);
		else
			insert(last1, first2, last2);
	}

	template<typename Type, typename Alloc>
	typename list<Type, Alloc>::remove_return_type list<Type, Alloc>::remove(const value_type &value) {
		iterator first = begin();
		iterator last = end();
		iterator extra = last;

		while (first != last) {
			iterator next = first;
			++next;
			if (*first == value) {
				if (&*first != &value) {
					_erase(first);
				} else
					extra = first;
			}
			first = next;
		}

		if (extra != last) {
			_erase(extra);
		}
	}

	template<typename Type, typename Alloc>
	typename list<Type, Alloc>::remove_return_type list<Type, Alloc>::unique() {
		iterator first = begin();
		iterator last = end();

		if (first == last)
			return;

		iterator next = first;

		while (++next != last) {
			if (*first == *next) {
				_erase(next);
			} else
				first = next;
			next = first;
		}
	}

	template<typename Type, typename Alloc>
	void list<Type, Alloc>::merge(list &x) {
		if (this != &x) {
			iterator first1 = begin();
			iterator last1 = end();
			iterator first2 = x.begin();
			iterator last2 = x.end();
			const size_t __orig_size = x.size();

			try {
				while (first1 != last1 && first2 != last2)
					if (*first2 < *first1) {
						iterator next = first2;
						_transfer(first1, first2, ++next);
						first2 = next;
					} else
						++first1;

				if (first2 != last2)
					_transfer(last1, first2, last2);

				this->_inc_size(x._get_size());
				x._set_size(0);

			} catch(...) {
				const size_t dist = ft::distance(first2, last2);
				this->_inc_size(__orig_size - dist);
				x._set_size(dist);
				throw;
			}
		}
	}

	template<typename Type, typename Alloc>
	template<typename StrictWeakOrdering>
	void list<Type, Alloc>::merge(list &x, StrictWeakOrdering comp) {
		if (this != &x) {
			iterator first1 = begin();
			iterator last1 = end();
			iterator first2 = x.begin();
			iterator last2 = x.end();
			const size_t __orig_size = x.size();

			try {
				while (first1 != last1 && first2 != last2)
					if (comp(*first2, *first1)) {
						iterator next = first2;
						_transfer(first1, first2, ++next);
						first2 = next;
					} else
						++first1;

				if (first2 != last2)
					_transfer(last1, first2, last2);

				this->_inc_size(x._get_size());
				x._set_size(0);

			} catch (...) {
				const size_t dist = ft::distance(first2, last2);
				this->_inc_size(__orig_size - dist);
				x._set_size(dist);
				throw;
			}
		}
	}

	template<typename Type, typename Alloc>
	void list<Type, Alloc>::sort() {
		if (this->impl._node.next != &this->impl._node && this->impl._node.next->next != &this->impl._node) {
			list carry;
			list tmp[64];
			list *fill = tmp;
			list *counter;

			try {
				do {
					carry.splice(carry.begin(), *this, begin());

					for (counter = tmp; counter != fill && !counter->empty(); ++counter) {
						counter->merge(carry);
						carry.swap(*counter);
					}
					carry.swap(*counter);
					if (counter == fill)
						++fill;
				} while (!empty());

				for (counter = tmp + 1; counter != fill; ++counter)
					counter->merge(*(counter - 1));
				swap(*(fill - 1));
			} catch (...) {
				this->splice(this->end(), carry);
				for (int i = 0; i < sizeof(tmp) / sizeof(tmp[0]); ++i)
					this->splice(this->end(), tmp[i]);
				throw;
			}
		}
	}

	template<typename Type, typename Alloc>
	template<typename Predicate>
	typename list<Type, Alloc>::remove_return_type list<Type, Alloc>::remove_if(Predicate predicate) {
		iterator first = begin();
		iterator last = end();

		while (first != last) {
			iterator next = first;
			++next;

			if (predicate(*first)) {
				_erase(first);
			}

			first = next;
		}
	}

	template<typename Type, typename Alloc>
	template<typename BinaryPredicate>
	typename list<Type, Alloc>::remove_return_type list<Type, Alloc>::unique(BinaryPredicate binary_predicate) {
		iterator first = begin();
		iterator last = end();

		if (first == last)
			return;

		iterator next = first;

		while (++next != last) {
			if (binary_predicate(*first, *next)) {
				_erase(next);
			} else
				first = next;
			next = first;
		}
	}

	template<typename Type, typename Alloc>
	template<typename StrictWeakOrdering>
	void list<Type, Alloc>::sort(StrictWeakOrdering comp) {
		if (this->impl._node.next != &this->impl._node && this->impl._node.next->next != &this->impl._node) {
			list carry;
			list tmp[64];
			list *fill = tmp;
			list *counter;

			try {
				do {
					carry.splice(carry.begin(), *this, begin());

					for (counter = tmp; counter != fill && !counter->empty(); ++counter) {
						counter->merge(carry, comp);
						carry.swap(*counter);
					}
					carry.swap(*counter);
					if (counter == fill)
						++fill;
				} while (!empty());

				for (counter = tmp + 1; counter != fill; ++counter)
					counter->merge(*(counter - 1), comp);
				swap(*(fill - 1));
			} catch (...) {
				this->splice(this->end(), carry);
				for (int i = 0; i < sizeof(tmp) / sizeof(tmp[0]); ++i)
					this->splice(this->end(), tmp[i]);
				throw;
			}
		}
	}

} // namespace ft

#endif //FT_VECTOR_HPP
