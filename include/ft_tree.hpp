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

#ifndef FT_TREE_HPP
#define FT_TREE_HPP 1

#include "ft_stl/alloc_traits.hpp"
#include "ft_stl/iterator.hpp"
#include "ft_stl/iterator_base_types.hpp"
#include "ft_stl/iterator_base_funcs.hpp"
#include "ft_stl/algobase.hpp"
#include "ft_pair.hpp"
#include <memory>

namespace ft {
	enum RedBlackTreeColor { self_red = false, self_black = true };

	struct RedBlackTreeNodeBase {
		typedef RedBlackTreeNodeBase *base_ptr;
		typedef const RedBlackTreeNodeBase *const_base_ptr;

		RedBlackTreeColor _color;
		base_ptr _parent;
		base_ptr _left;
		base_ptr _right;

		static base_ptr self_minimum(base_ptr x) {
			while (x->_left != 0)
				x = x->_left;
			return x;
		}

		static const_base_ptr self_minimum(const_base_ptr x) {
			while (x->_left != 0)
				x = x->_left;
			return x;
		}

		static base_ptr self_maximum(base_ptr x) {
			while (x->_right != 0)
				x = x->_right;
			return x;
		}

		static const_base_ptr self_maximum(const_base_ptr x) {
			while (x->_right != 0)
				x = x->_right;
			return x;
		}
	};

	template<typename Key_compare>
	struct RedBlackTreeKeyCompare {
		Key_compare _key_compare;

		RedBlackTreeKeyCompare() : _key_compare() { }
		RedBlackTreeKeyCompare(const Key_compare &comp) : _key_compare(comp) { }
	};

	struct RedBlackTreeHeader {
		RedBlackTreeNodeBase _header;
		size_t _node_count;

		RedBlackTreeHeader() {
			_header._color = self_red;
			_reset();
		}

		void _move_data(RedBlackTreeHeader &from) {
			_header._color = from._header._color;
			_header._parent = from._header._parent;
			_header._left = from._header._left;
			_header._right = from._header._right;
			_header._parent->_parent = &_header;
			_node_count = from._node_count;

			from._reset();
		}

		void _reset() {
			_header._parent = 0;
			_header._left = &_header;
			_header._right = &_header;
			_node_count = 0;
		}
	};

	template<typename Value>
	struct RedBlackTreeNode : public RedBlackTreeNodeBase {
		typedef RedBlackTreeNode<Value> *LinkType;

		Value _value_field;

		Value *_valptr() { return &_value_field; }
		const Value *_valptr() const { return &_value_field; }
	};

	RedBlackTreeNodeBase *_red_black_tree_increment(RedBlackTreeNodeBase *x) throw();
	const RedBlackTreeNodeBase *_red_black_tree_increment(const RedBlackTreeNodeBase *x) throw();

	RedBlackTreeNodeBase *_red_black_tree_decrement(RedBlackTreeNodeBase *x) throw();
	const RedBlackTreeNodeBase *_red_black_tree_decrement(const RedBlackTreeNodeBase *x) throw();

	template<typename TemplateType>
	struct RedBlackTreeIterator {
		typedef TemplateType value_type;
		typedef TemplateType &reference;
		typedef TemplateType *pointer;

		typedef bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;

		typedef RedBlackTreeIterator<TemplateType> _Self;
		typedef RedBlackTreeNodeBase::base_ptr base_ptr;
		typedef RedBlackTreeNode<TemplateType> *LinkType;

		RedBlackTreeIterator() : _node() {}
		explicit RedBlackTreeIterator(base_ptr x) : _node(x) {}

		reference operator*() const { return *static_cast<LinkType>(_node)->_valptr(); }
		pointer operator->() const { return static_cast<LinkType>(_node)->_valptr(); }

		_Self &operator++() {
			_node = _red_black_tree_increment(_node);
			return *this;
		}

		_Self operator++(int) {
			_Self temp = *this;
			_node = _red_black_tree_increment(_node);
			return temp;
		}

		_Self &operator--() {
			_node = _red_black_tree_decrement(_node);
			return *this;
		}

		_Self operator--(int) {
			_Self temp = *this;
			_node = _red_black_tree_decrement(_node);
			return temp;
		}

		friend bool operator==(const _Self &x, const _Self &y) { return x._node == y._node; }
		friend bool operator!=(const _Self &x, const _Self &y) { return x._node != y._node; }

		base_ptr _node;
	};

	template<typename TemplateType>
	struct RedBlackTreeConstIterator {
		typedef TemplateType value_type;
		typedef const TemplateType &reference;
		typedef const TemplateType *pointer;

		typedef RedBlackTreeIterator<TemplateType> iterator;

		typedef bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;

		typedef RedBlackTreeConstIterator<TemplateType> _Self;
		typedef RedBlackTreeNodeBase::const_base_ptr base_ptr;
		typedef const RedBlackTreeNode<TemplateType> *LinkType;

		RedBlackTreeConstIterator() : _node() { }

		explicit RedBlackTreeConstIterator(base_ptr x) : _node(x) { }
		RedBlackTreeConstIterator(const iterator &x) : _node(x._node) { }

		iterator _const_cast() const { return iterator(const_cast<typename iterator::base_ptr>(_node)); }

		reference operator*() const { return *static_cast<LinkType>(_node)->_valptr(); }
		pointer operator->() const { return static_cast<LinkType>(_node)->_valptr(); }

		_Self &operator++() {
			_node = _red_black_tree_increment(_node);
			return *this;
		}

		_Self operator++(int) {
			_Self temp = *this;
			_node = _red_black_tree_increment(_node);
			return temp;
		}

		_Self &operator--() {
			_node = _red_black_tree_decrement(_node);
			return *this;
		}

		_Self operator--(int) {
			_Self temp = *this;
			_node = _red_black_tree_decrement(_node);
			return temp;
		}

		friend bool operator==(const _Self &x, const _Self &y) { return x._node == y._node; }
		friend bool operator!=(const _Self &x, const _Self &y) { return x._node != y._node; }

		base_ptr _node;
	};

	void _red_black_tree_insert_and_rebalance(const bool insert_left, RedBlackTreeNodeBase *x, RedBlackTreeNodeBase *ptr,
											  RedBlackTreeNodeBase &header) throw();

	RedBlackTreeNodeBase *_red_black_tree_rebalance_for_erase(RedBlackTreeNodeBase *const z,
															  RedBlackTreeNodeBase &header) throw();

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<Value> >
	class RedBlackTree {
		typedef typename alloc_traits<Alloc>::template rebind<RedBlackTreeNode<Value> >::other NodeAllocator;
		typedef alloc_traits<NodeAllocator> AllocatorTraits;

	protected:
		typedef RedBlackTreeNodeBase *base_ptr;
		typedef const RedBlackTreeNodeBase *const_base_ptr;
		typedef RedBlackTreeNode<Value> *LinkType;
		typedef const RedBlackTreeNode<Value> *ConstLinkType;

	private:
		struct ReuseOrAllocateNode {
			ReuseOrAllocateNode(RedBlackTree &the_other)
					: _root(the_other._root()), _nodes(the_other._rightmost()),
					  _tree(the_other) {
				if (_root) {
					_root->_parent = 0;

					if (_nodes->_left)
						_nodes = _nodes->_left;
				} else
					_nodes = 0;
			}

			~ReuseOrAllocateNode() { _tree._erase(static_cast<LinkType>(_root)); }

			template<typename Argument>
			LinkType operator()(const Argument &argument) {
				LinkType node = static_cast<LinkType>(_extract());
				if (node) {
					_tree._destroy_node(node);
					_tree._construct_node(node, argument);
					return node;
				}

				return _tree._create_node(argument);
			}

		private:
			base_ptr _extract() {
				if (!_nodes)
					return _nodes;

				base_ptr node = _nodes;
				_nodes = _nodes->_parent;
				if (_nodes) {
					if (_nodes->_right == node) {
						_nodes->_right = 0;

						if (_nodes->_left) {
							_nodes = _nodes->_left;

							while (_nodes->_right)
								_nodes = _nodes->_right;

							if (_nodes->_left)
								_nodes = _nodes->_left;
						}
					} else
						_nodes->_left = 0;
				} else
					_root = 0;

				return node;
			}

			base_ptr _root;
			base_ptr _nodes;
			RedBlackTree &_tree;
		};

		struct AllocateNode {
			AllocateNode(RedBlackTree &the_other) : _tree(the_other) {}

			template<typename Argument>
			LinkType operator()(const Argument &argument) const {
				return _tree._create_node(argument);
			}

		private:
			RedBlackTree &_tree;
		};

	public:
		typedef Key key_type;
		typedef Value value_type;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef std::allocator<Value> allocator_type;

		NodeAllocator &_get_node_allocator() { return this->_impl; }
		const NodeAllocator &_get_node_allocator() const { return this->_impl; }
		allocator_type get_allocator() const { return allocator_type(_get_node_allocator()); }

	protected:
		LinkType _get_node() { return AllocatorTraits::allocate(_get_node_allocator(), 1); }

		void _put_node(LinkType ptr) { AllocatorTraits::deallocate(_get_node_allocator(), ptr, 1); }

		void _construct_node(LinkType node, const value_type &x) {
			try {
				get_allocator().construct(node->_valptr(), x);
			} catch (...) {
				_put_node(node);
				throw;
			}
		}

		LinkType _create_node(const value_type &x) {
			LinkType temp = _get_node();
			_construct_node(temp, x);
			return temp;
		}

		void _destroy_node(LinkType ptr) { get_allocator().destroy(ptr->_valptr()); }

		void _drop_node(LinkType ptr) {
			_destroy_node(ptr);
			_put_node(ptr);
		}

		template<typename NodeGenerator>
		LinkType _clone_node(ConstLinkType x, NodeGenerator &node_gen) {
			LinkType temp = node_gen(*x->_valptr());
			temp->_color = x->_color;
			temp->_left = 0;
			temp->_right = 0;
			return temp;
		}

		template<typename Key_compare, bool = true>
		struct RedBlackTreeImplementation
		: public NodeAllocator, public RedBlackTreeKeyCompare<Key_compare>, public RedBlackTreeHeader {
			typedef RedBlackTreeKeyCompare<Key_compare> BaseKeyCompare;

			RedBlackTreeImplementation() : NodeAllocator() { }

			RedBlackTreeImplementation(const RedBlackTreeImplementation &x)
			: NodeAllocator(AllocatorTraits::self_select_on_copy(x)), BaseKeyCompare(x._key_compare), RedBlackTreeHeader() { }

			RedBlackTreeImplementation(const Key_compare &comp, const NodeAllocator &allocator)
			: NodeAllocator(allocator), BaseKeyCompare(comp) { }
		};

		RedBlackTreeImplementation<Compare> _impl;

		base_ptr &_root() { return this->_impl._header._parent; }
		const_base_ptr _root() const { return this->_impl._header._parent; }

		base_ptr &_leftmost() { return this->_impl._header._left; }
		const_base_ptr _leftmost() const { return this->_impl._header._left; }

		base_ptr &_rightmost() { return this->_impl._header._right; }
		const_base_ptr _rightmost() const { return this->_impl._header._right; }

		LinkType _begin() { return static_cast<LinkType>(this->_impl._header._parent); }
		ConstLinkType _begin() const {
			return static_cast<ConstLinkType>(this->_impl._header._parent);
		}

		base_ptr _end() { return &this->_impl._header; }
		const_base_ptr _end() const { return &this->_impl._header; }

		static const Key &self_key(ConstLinkType x) { return KeyOfValue()(*x->_valptr()); }

		static LinkType self_left(base_ptr x) { return static_cast<LinkType>(x->_left); }
		static ConstLinkType self_left(const_base_ptr x) { return static_cast<ConstLinkType>(x->_left); }

		static LinkType self_right(base_ptr x) { return static_cast<LinkType>(x->_right); }
		static ConstLinkType self_right(const_base_ptr x) { return static_cast<ConstLinkType>(x->_right); }

		static const Key &self_key(const_base_ptr x) { return self_key(static_cast<ConstLinkType>(x)); }

		static base_ptr self_minimum(base_ptr x) { return RedBlackTreeNodeBase::self_minimum(x); }
		static const_base_ptr self_minimum(const_base_ptr x) { return RedBlackTreeNodeBase::self_minimum(x); }

		static base_ptr self_maximum(base_ptr x) { return RedBlackTreeNodeBase::self_maximum(x); }
		static const_base_ptr self_maximum(const_base_ptr x) { return RedBlackTreeNodeBase::self_maximum(x); }

	public:
		typedef RedBlackTreeIterator<value_type> iterator;
		typedef RedBlackTreeConstIterator<value_type> const_iterator;

		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		pair<base_ptr, base_ptr> _get_insert_unique_pos(const key_type &key);

		pair<base_ptr, base_ptr> _get_insert_equal_pos(const key_type &key);

		pair<base_ptr, base_ptr> _get_insert_hint_unique_pos(const_iterator pos, const key_type &key);

		pair<base_ptr, base_ptr> _get_insert_hint_equal_pos(const_iterator pos, const key_type &key);

	private:
		template<typename NodeGenerator>
		iterator _insert(base_ptr x, base_ptr y, const value_type &value, NodeGenerator &);

		iterator _insert_lower(base_ptr y, const value_type &value);

		iterator _insert_equal_lower(const value_type &x);

		template<typename NodeGenerator>
		LinkType _copy(ConstLinkType x, base_ptr ptr, NodeGenerator &);
		template<typename NodeGenerator>
		LinkType _copy(const RedBlackTree &x, NodeGenerator &generator) {
			LinkType root = _copy(x._begin(), _end(), generator);
			_leftmost() = self_minimum(root);
			_rightmost() = self_maximum(root);
			_impl._node_count = x._impl._node_count;
			return root;
		}

		LinkType _copy(const RedBlackTree &x) {
			AllocateNode allocate_node(*this);
			return _copy(x, allocate_node);
		}

		void _erase(LinkType x);

		iterator _lower_bound(LinkType x, base_ptr y, const Key &key);
		const_iterator _lower_bound(ConstLinkType x, const_base_ptr y, const Key &key) const;

		iterator _upper_bound(LinkType x, base_ptr y, const Key &key);
		const_iterator _upper_bound(ConstLinkType x, const_base_ptr y, const Key &key) const;

	public:
		RedBlackTree() { }

		RedBlackTree(const Compare &comp, const allocator_type &allocator = allocator_type())
				: _impl(comp, NodeAllocator(allocator)) { }

		RedBlackTree(const RedBlackTree &x) : _impl(x._impl) {
			if (x._root() != 0)
				_root() = _copy(x);
		}

		~RedBlackTree() { _erase(_begin()); }

		RedBlackTree &operator=(const RedBlackTree &x);

		Compare key_comp() const { return _impl._key_compare; }

		iterator begin() { return iterator(this->_impl._header._left); }
		const_iterator begin() const { return const_iterator(this->_impl._header._left); }

		iterator end() { return iterator(&this->_impl._header); }
		const_iterator end() const { return const_iterator(&this->_impl._header); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		bool empty() const { return _impl._node_count == 0; }

		size_type size() const { return _impl._node_count; }
		size_type max_size() const { return AllocatorTraits::max_size(_get_node_allocator()); }

		void swap(RedBlackTree &the_other);

		pair<iterator, bool> _insert_unique(const value_type &x);

		iterator _insert_equal(const value_type &x);

		template<typename NodeGenerator>
		iterator _insert_unique(const_iterator pos, const value_type &x, NodeGenerator &);

		iterator _insert_unique(const_iterator pos, const value_type &x) {
			AllocateNode allocate_node(*this);
			return _insert_unique(pos, x, allocate_node);
		}

		template<typename NodeGenerator>
		iterator _insert_equal(const_iterator pos, const value_type &x, NodeGenerator &);
		iterator _insert_equal(const_iterator pos, const value_type &x) {
			AllocateNode allocate_node(*this);
			return _insert_equal(pos, x, allocate_node);
		}

		template<typename InputIterator>
		void _insert_range_unique(InputIterator first, InputIterator last) {
			AllocateNode allocate_node(*this);
			for (; first != last; ++first)
				_insert_unique(end(), *first, allocate_node);
		}

		template<typename InputIterator>
		void _insert_range_equal(InputIterator first, InputIterator last) {
			AllocateNode allocate_node(*this);
			for (; first != last; ++first)
				_insert_equal(end(), *first, allocate_node);
		}

	private:
		void _erase_aux(const_iterator position);
		void _erase_aux(const_iterator first, const_iterator last);

	public:
		void erase(iterator position) { _erase_aux(position); }

		void erase(const_iterator position) { _erase_aux(position); }

		size_type erase(const key_type &x);

		void erase(iterator first, iterator last) { _erase_aux(first, last); }
		void erase(const_iterator first, const_iterator last) { _erase_aux(first, last); }

		void clear() {
			_erase(_begin());
			_impl._reset();
		}

		iterator find(const key_type &key);
		const_iterator find(const key_type &key) const;

		size_type count(const key_type &key) const;

		iterator lower_bound(const key_type &key) { return _lower_bound(_begin(), _end(), key); }
		const_iterator lower_bound(const key_type &key) const {
			return _lower_bound(_begin(), _end(), key);
		}

		iterator upper_bound(const key_type &key) { return _upper_bound(_begin(), _end(), key); }
		const_iterator upper_bound(const key_type &key) const {
			return _upper_bound(_begin(), _end(), key);
		}

		pair<iterator, iterator> equal_range(const key_type &key);
		pair<const_iterator, const_iterator> equal_range(const key_type &key) const;

		friend bool operator==(const RedBlackTree &x, const RedBlackTree &y) {
			return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
		}

		friend bool operator<(const RedBlackTree &x, const RedBlackTree &y) {
			return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
		}
	};

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	inline void swap(RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc> &x, RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc> &y) {
		x.swap(y);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc> &
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::operator=(const RedBlackTree &x) {
		if (this != &x) {
			ReuseOrAllocateNode reuse_or_allocate(*this);
			_impl._reset();
			_impl._key_compare = x._impl._key_compare;
			if (x._root() != 0)
				_root() = _copy(x, reuse_or_allocate);
		}

		return *this;
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	template<typename NodeGenerator>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_insert(base_ptr x, base_ptr ptr, const Value &value,
		  NodeGenerator &node_gen) {
		bool insert_left = (x != 0 || ptr == _end() || _impl._key_compare(KeyOfValue()(value), self_key(ptr)));

		LinkType z = node_gen(value);

		_red_black_tree_insert_and_rebalance(insert_left, z, ptr, this->_impl._header);
		++_impl._node_count;
		return iterator(z);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_insert_lower(base_ptr ptr, const Value &value) {
		bool insert_left = (ptr == _end() || !_impl._key_compare(self_key(ptr), KeyOfValue()(value)));

		LinkType z = _create_node(value);

		_red_black_tree_insert_and_rebalance(insert_left, z, ptr, this->_impl._header);
		++_impl._node_count;
		return iterator(z);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_insert_equal_lower(const Value &value) {
		LinkType x = _begin();
		base_ptr y = _end();
		while (x != 0) {
			y = x;
			x = !_impl._key_compare(self_key(x), KeyOfValue()(value)) ? self_left(x) : self_right(x);
		}
		return _insert_lower(y, value);
	}

	template<typename Key, typename Value, typename _KoV, typename Compare, typename Alloc>
	template<typename NodeGenerator>
	typename RedBlackTree<Key, Value, _KoV, Compare, Alloc>::LinkType
	RedBlackTree<Key, Value, _KoV, Compare, Alloc>::_copy(ConstLinkType x, base_ptr ptr, NodeGenerator &node_gen) {
		LinkType top = _clone_node(x, node_gen);
		top->_parent = ptr;

		try {
			if (x->_right)
				top->_right = _copy(self_right(x), top, node_gen);
			ptr = top;
			x = self_left(x);

			while (x != 0) {
				LinkType y = _clone_node(x, node_gen);
				ptr->_left = y;
				y->_parent = ptr;
				if (x->_right)
					y->_right = _copy(self_right(x), y, node_gen);
				ptr = y;
				x = self_left(x);
			}
		} catch (...) {
			_erase(top);
			throw;
		}
		return top;
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	void RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_erase(LinkType x) {
		while (x != 0) {
			_erase(self_right(x));
			LinkType y = self_left(x);
			_drop_node(x);
			x = y;
		}
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_lower_bound(LinkType x, base_ptr y, const Key &key) {
		while (x != 0)
			if (!_impl._key_compare(self_key(x), key))
				y = x, x = self_left(x);
			else
				x = self_right(x);
		return iterator(y);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::const_iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_lower_bound(ConstLinkType x, const_base_ptr y, const Key &key) const {
		while (x != 0)
			if (!_impl._key_compare(self_key(x), key))
				y = x, x = self_left(x);
			else
				x = self_right(x);
		return const_iterator(y);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_upper_bound(LinkType x, base_ptr y, const Key &key) {
		while (x != 0)
			if (_impl._key_compare(key, self_key(x)))
				y = x, x = self_left(x);
			else
				x = self_right(x);
		return iterator(y);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::const_iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_upper_bound(ConstLinkType x, const_base_ptr y, const Key &key) const {
		while (x != 0)
			if (_impl._key_compare(key, self_key(x)))
				y = x, x = self_left(x);
			else
				x = self_right(x);
		return const_iterator(y);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	pair<typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator,
			typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator>
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::equal_range(const Key &key) {
		LinkType x = _begin();
		base_ptr y = _end();
		while (x != 0) {
			if (_impl._key_compare(self_key(x), key))
				x = self_right(x);
			else if (_impl._key_compare(key, self_key(x)))
				y = x, x = self_left(x);
			else {
				LinkType xu(x);
				base_ptr yu(y);
				y = x, x = self_left(x);
				xu = self_right(xu);
				return pair<iterator, iterator>(_lower_bound(x, y, key), _upper_bound(xu, yu, key));
			}
		}
		return pair<iterator, iterator>(iterator(y), iterator(y));
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	pair<typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::const_iterator,
			typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::const_iterator>
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::equal_range(const Key &key) const {
		ConstLinkType x = _begin();
		const_base_ptr y = _end();

		while (x != 0) {
			if (_impl._key_compare(self_key(x), key))
				x = self_right(x);
			else if (_impl._key_compare(key, self_key(x)))
				y = x, x = self_left(x);
			else {
				ConstLinkType xu(x);
				const_base_ptr yu(y);
				y = x, x = self_left(x);
				xu = self_right(xu);
				return pair<const_iterator, const_iterator>(_lower_bound(x, y, key),
															_upper_bound(xu, yu, key));
			}
		}

		return pair<const_iterator, const_iterator>(const_iterator(y), const_iterator(y));
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	void RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::swap(RedBlackTree &the_other) {
		if (_root() == 0) {
			if (the_other._root() != 0)
				_impl._move_data(the_other._impl);
		} else if (the_other._root() == 0)
			the_other._impl._move_data(_impl);
		else {
			ft::swap(_root(), the_other._root());
			ft::swap(_leftmost(), the_other._leftmost());
			ft::swap(_rightmost(), the_other._rightmost());

			_root()->_parent = _end();
			the_other._root()->_parent = the_other._end();
			ft::swap(this->_impl._node_count, the_other._impl._node_count);
		}

		ft::swap(this->_impl._key_compare, the_other._impl._key_compare);
		AllocatorTraits::self_on_swap(_get_node_allocator(), the_other._get_node_allocator());
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	pair<typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::base_ptr,
			typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::base_ptr>
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_get_insert_unique_pos(const key_type &key) {
		typedef pair<base_ptr, base_ptr> Result;
		LinkType x = _begin();
		base_ptr y = _end();
		bool comp = true;

		while (x != 0) {
			y = x;
			comp = _impl._key_compare(key, self_key(x));
			x = comp ? self_left(x) : self_right(x);
		}

		iterator iterator_copy = iterator(y);

		if (comp) {
			if (iterator_copy == begin())
				return Result(x, y);
			else
				--iterator_copy;
		}

		if (_impl._key_compare(self_key(iterator_copy._node), key))
			return Result(x, y);

		return Result(iterator_copy._node, 0);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	pair<typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::base_ptr,
			typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::base_ptr>
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_get_insert_equal_pos(const key_type &key) {
		typedef pair<base_ptr, base_ptr> Result;
		LinkType x = _begin();
		base_ptr y = _end();

		while (x != 0) {
			y = x;
			x = _impl._key_compare(key, self_key(x)) ? self_left(x) : self_right(x);
		}

		return Result(x, y);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	pair<typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator, bool>
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_insert_unique(const Value &value) {
		typedef pair<iterator, bool> Result;
		pair<base_ptr, base_ptr> result = _get_insert_unique_pos(KeyOfValue()(value));

		if (result.second) {
			AllocateNode allocate_node(*this);
			return Result(_insert(result.first, result.second, value, allocate_node), true);
		}

		return Result(iterator(result.first), false);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_insert_equal(const Value &value) {
		pair<base_ptr, base_ptr> result = _get_insert_equal_pos(KeyOfValue()(value));
		AllocateNode allocate_node(*this);
		return _insert(result.first, result.second, value, allocate_node);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	pair<typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::base_ptr,
			typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::base_ptr>
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_get_insert_hint_unique_pos(const_iterator position,
																					  const key_type &key) {
		iterator pos = position._const_cast();
		typedef pair<base_ptr, base_ptr> Result;

		if (pos._node == _end()) {
			if (size() > 0 && _impl._key_compare(self_key(_rightmost()), key))
				return Result(0, _rightmost());
			else
				return _get_insert_unique_pos(key);
		} else if (_impl._key_compare(key, self_key(pos._node))) {
			iterator before = pos;
			if (pos._node == _leftmost())
				return Result(_leftmost(), _leftmost());

			else if (_impl._key_compare(self_key((--before)._node), key)) {
				if (self_right(before._node) == 0)
					return Result(0, before._node);
				else
					return Result(pos._node, pos._node);
			} else
				return _get_insert_unique_pos(key);

		} else if (_impl._key_compare(self_key(pos._node), key)) {
			iterator after = pos;

			if (pos._node == _rightmost())
				return Result(0, _rightmost());
			else if (_impl._key_compare(key, self_key((++after)._node))) {
				if (self_right(pos._node) == 0)
					return Result(0, pos._node);
				else
					return Result(after._node, after._node);
			} else
				return _get_insert_unique_pos(key);
		} else
			return Result(pos._node, 0);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	template<typename NodeGenerator>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_insert_unique(const_iterator position, const Value &value, NodeGenerator &node_gen) {
		pair<base_ptr, base_ptr> result = _get_insert_hint_unique_pos(position, KeyOfValue()(value));

		if (result.second)
			return _insert(result.first, result.second, value, node_gen);
		return iterator(result.first);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	pair<typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::base_ptr,
		typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::base_ptr>
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_get_insert_hint_equal_pos(const_iterator position, const key_type &key) {
		iterator pos = position._const_cast();
		typedef pair<base_ptr, base_ptr> Result;

		if (pos._node == _end()) {
			if (size() > 0 && !_impl._key_compare(key, self_key(_rightmost())))
				return Result(0, _rightmost());
			else
				return _get_insert_equal_pos(key);
		} else if (!_impl._key_compare(self_key(pos._node), key)) {
			iterator before = pos;

			if (pos._node == _leftmost())
				return Result(_leftmost(), _leftmost());

			else if (!_impl._key_compare(key, self_key((--before)._node))) {
				if (self_right(before._node) == 0)
					return Result(0, before._node);
				else
					return Result(pos._node, pos._node);
			} else
				return _get_insert_equal_pos(key);
		} else {
			iterator after = pos;

			if (pos._node == _rightmost())
				return Result(0, _rightmost());

			else if (!_impl._key_compare(self_key((++after)._node), key)) {
				if (self_right(pos._node) == 0)
					return Result(0, pos._node);
				else
					return Result(after._node, after._node);
			} else
				return Result(0, 0);
		}
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	template<typename NodeGenerator>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_insert_equal(const_iterator position, const Value &value, NodeGenerator &node_gen) {
		pair<base_ptr, base_ptr> result = _get_insert_hint_equal_pos(position, KeyOfValue()(value));

		if (result.second)
			return _insert(result.first, result.second, value, node_gen);

		return _insert_equal_lower(value);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	void RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_erase_aux(const_iterator position) {
		LinkType y = static_cast<LinkType>(_red_black_tree_rebalance_for_erase(const_cast<base_ptr>(position._node), this->_impl._header));
		_drop_node(y);
		--_impl._node_count;
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	void RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::_erase_aux(const_iterator first, const_iterator last) {
		if (first == begin() && last == end())
			clear();
		else
			while (first != last)
				_erase_aux(first++);
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::size_type
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::erase(const Key &x) {
		pair<iterator, iterator> ptr = equal_range(x);
		const size_type __old_size = size();
		_erase_aux(ptr.first, ptr.second);
		return __old_size - size();
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::find(const Key &key) {
		iterator __j = _lower_bound(_begin(), _end(), key);
		return (__j == end() || _impl._key_compare(key, self_key(__j._node))) ? end() : __j;
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::const_iterator
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::find(const Key &key) const {
		const_iterator __j = _lower_bound(_begin(), _end(), key);
		return (__j == end() || _impl._key_compare(key, self_key(__j._node))) ? end() : __j;
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	typename RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::size_type
	RedBlackTree<Key, Value, KeyOfValue, Compare, Alloc>::count(const Key &key) const {
		pair<const_iterator, const_iterator> ptr = equal_range(key);
		const size_type __n = ft::distance(ptr.first, ptr.second);
		return __n;
	}

	unsigned int _red_black_tree_black_count(const RedBlackTreeNodeBase *node, const RedBlackTreeNodeBase *root) throw();

	static RedBlackTreeNodeBase *__red_black_tree_increment(RedBlackTreeNodeBase *x) throw() {
		if (x->_right != 0) {
			x = x->_right;
			while (x->_left != 0)
				x = x->_left;
		} else {
			RedBlackTreeNodeBase *y = x->_parent;
			while (x == y->_right) {
				x = y;
				y = y->_parent;
			}
			if (x->_right != y)
				x = y;
		}
		return x;
	}

	RedBlackTreeNodeBase *_red_black_tree_increment(RedBlackTreeNodeBase *x) throw() {
		return __red_black_tree_increment(x);
	}

	const RedBlackTreeNodeBase *_red_black_tree_increment(const RedBlackTreeNodeBase *x) throw() {
		return __red_black_tree_increment(const_cast<RedBlackTreeNodeBase *>(x));
	}

	static RedBlackTreeNodeBase *__red_black_tree_decrement(RedBlackTreeNodeBase *x) throw() {
		if (x->_color == self_red && x->_parent->_parent == x)
			x = x->_right;
		else if (x->_left != 0) {
			RedBlackTreeNodeBase *y = x->_left;
			while (y->_right != 0)
				y = y->_right;
			x = y;
		} else {
			RedBlackTreeNodeBase *y = x->_parent;
			while (x == y->_left) {
				x = y;
				y = y->_parent;
			}
			x = y;
		}
		return x;
	}

	RedBlackTreeNodeBase *_red_black_tree_decrement(RedBlackTreeNodeBase *x) throw() {
		return __red_black_tree_decrement(x);
	}

	const RedBlackTreeNodeBase *_red_black_tree_decrement(const RedBlackTreeNodeBase *x) throw() {
		return __red_black_tree_decrement(const_cast<RedBlackTreeNodeBase *>(x));
	}

	static void __red_black_tree_rotate_left(RedBlackTreeNodeBase *const x, RedBlackTreeNodeBase *&root) {
		RedBlackTreeNodeBase *const y = x->_right;

		x->_right = y->_left;
		if (y->_left != 0)
			y->_left->_parent = x;
		y->_parent = x->_parent;

		if (x == root)
			root = y;
		else if (x == x->_parent->_left)
			x->_parent->_left = y;
		else
			x->_parent->_right = y;
		y->_left = x;
		x->_parent = y;
	}

	void _red_black_tree_rotate_left(RedBlackTreeNodeBase *const x, RedBlackTreeNodeBase *&root) {
		__red_black_tree_rotate_left(x, root);
	}

	static void __red_black_tree_rotate_right(RedBlackTreeNodeBase *const x, RedBlackTreeNodeBase *&root) {
		RedBlackTreeNodeBase *const y = x->_left;

		x->_left = y->_right;
		if (y->_right != 0)
			y->_right->_parent = x;
		y->_parent = x->_parent;

		if (x == root)
			root = y;
		else if (x == x->_parent->_right)
			x->_parent->_right = y;
		else
			x->_parent->_left = y;
		y->_right = x;
		x->_parent = y;
	}

	void _red_black_tree_rotate_right(RedBlackTreeNodeBase *const x, RedBlackTreeNodeBase *&root) {
		__red_black_tree_rotate_right(x, root);
	}

	void _red_black_tree_insert_and_rebalance(const bool insert_left, RedBlackTreeNodeBase *x, RedBlackTreeNodeBase *ptr,
											  RedBlackTreeNodeBase &header) throw() {
		RedBlackTreeNodeBase *&root = header._parent;

		x->_parent = ptr;
		x->_left = 0;
		x->_right = 0;
		x->_color = self_red;

		if (insert_left) {
			ptr->_left = x;

			if (ptr == &header) {
				header._parent = x;
				header._right = x;
			} else if (ptr == header._left)
				header._left = x;
		} else {
			ptr->_right = x;

			if (ptr == header._right)
				header._right = x;
		}

		while (x != root && x->_parent->_color == self_red) {
			RedBlackTreeNodeBase *const xpp = x->_parent->_parent;

			if (x->_parent == xpp->_left) {
				RedBlackTreeNodeBase *const y = xpp->_right;
				if (y && y->_color == self_red) {
					x->_parent->_color = self_black;
					y->_color = self_black;
					xpp->_color = self_red;
					x = xpp;
				} else {
					if (x == x->_parent->_right) {
						x = x->_parent;
						__red_black_tree_rotate_left(x, root);
					}
					x->_parent->_color = self_black;
					xpp->_color = self_red;
					__red_black_tree_rotate_right(xpp, root);
				}
			} else {
				RedBlackTreeNodeBase *const y = xpp->_left;
				if (y && y->_color == self_red) {
					x->_parent->_color = self_black;
					y->_color = self_black;
					xpp->_color = self_red;
					x = xpp;
				} else {
					if (x == x->_parent->_left) {
						x = x->_parent;
						__red_black_tree_rotate_right(x, root);
					}
					x->_parent->_color = self_black;
					xpp->_color = self_red;
					__red_black_tree_rotate_left(xpp, root);
				}
			}
		}
		root->_color = self_black;
	}

	RedBlackTreeNodeBase *_red_black_tree_rebalance_for_erase(RedBlackTreeNodeBase *const z, RedBlackTreeNodeBase &header) throw() {
		RedBlackTreeNodeBase *&root = header._parent;
		RedBlackTreeNodeBase *&leftmost = header._left;
		RedBlackTreeNodeBase *&rightmost = header._right;
		RedBlackTreeNodeBase *y = z;
		RedBlackTreeNodeBase *x = 0;
		RedBlackTreeNodeBase *x_parent = 0;

		if (y->_left == 0)
			x = y->_right;
		else if (y->_right == 0)
			x = y->_left;
		else {
			y = y->_right;
			while (y->_left != 0)
				y = y->_left;
			x = y->_right;
		}
		if (y != z) {
			z->_left->_parent = y;
			y->_left = z->_left;
			if (y != z->_right) {
				x_parent = y->_parent;
				if (x)
					x->_parent = y->_parent;
				y->_parent->_left = x;
				y->_right = z->_right;
				z->_right->_parent = y;
			} else
				x_parent = y;
			if (root == z)
				root = y;
			else if (z->_parent->_left == z)
				z->_parent->_left = y;
			else
				z->_parent->_right = y;
			y->_parent = z->_parent;
			ft::swap(y->_color, z->_color);
			y = z;
		} else {
			x_parent = y->_parent;
			if (x)
				x->_parent = y->_parent;
			if (root == z)
				root = x;
			else if (z->_parent->_left == z)
				z->_parent->_left = x;
			else
				z->_parent->_right = x;
			if (leftmost == z) {
				if (z->_right == 0)
					leftmost = z->_parent;
				else
					leftmost = RedBlackTreeNodeBase::self_minimum(x);
			}
			if (rightmost == z) {
				if (z->_left == 0)
					rightmost = z->_parent;
				else
					rightmost = RedBlackTreeNodeBase::self_maximum(x);
			}
		}
		if (y->_color != self_red) {
			while (x != root && (x == 0 || x->_color == self_black))
				if (x == x_parent->_left) {
					RedBlackTreeNodeBase *w = x_parent->_right;
					if (w->_color == self_red) {
						w->_color = self_black;
						x_parent->_color = self_red;
						__red_black_tree_rotate_left(x_parent, root);
						w = x_parent->_right;
					}
					if ((w->_left == 0 || w->_left->_color == self_black) &&
						(w->_right == 0 || w->_right->_color == self_black)) {
						w->_color = self_red;
						x = x_parent;
						x_parent = x_parent->_parent;
					} else {
						if (w->_right == 0 || w->_right->_color == self_black) {
							w->_left->_color = self_black;
							w->_color = self_red;
							__red_black_tree_rotate_right(w, root);
							w = x_parent->_right;
						}
						w->_color = x_parent->_color;
						x_parent->_color = self_black;
						if (w->_right)
							w->_right->_color = self_black;
						__red_black_tree_rotate_left(x_parent, root);
						break;
					}
				} else {
					RedBlackTreeNodeBase *w = x_parent->_left;
					if (w->_color == self_red) {
						w->_color = self_black;
						x_parent->_color = self_red;
						__red_black_tree_rotate_right(x_parent, root);
						w = x_parent->_left;
					}
					if ((w->_right == 0 || w->_right->_color == self_black) &&
						(w->_left == 0 || w->_left->_color == self_black)) {
						w->_color = self_red;
						x = x_parent;
						x_parent = x_parent->_parent;
					} else {
						if (w->_left == 0 || w->_left->_color == self_black) {
							w->_right->_color = self_black;
							w->_color = self_red;
							__red_black_tree_rotate_left(w, root);
							w = x_parent->_left;
						}
						w->_color = x_parent->_color;
						x_parent->_color = self_black;
						if (w->_left)
							w->_left->_color = self_black;
						__red_black_tree_rotate_right(x_parent, root);
						break;
					}
				}
			if (x)
				x->_color = self_black;
		}
		return y;
	}

	unsigned int _red_black_tree_black_count(const RedBlackTreeNodeBase *node, const RedBlackTreeNodeBase *root) throw() {
		if (node == 0)
			return 0;

		unsigned int sum = 0;

		do {
			if (node->_color == self_black)
				++sum;
			if (node == root)
				break;
			node = node->_parent;
		} while (1);

		return sum;
	}

} // namespace ft

#endif