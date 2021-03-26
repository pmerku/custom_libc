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

#ifndef FT_DEQUE_HPP
#define FT_DEQUE_HPP 1

#include "ft_stl/algobase.hpp"
#include "ft_stl/alloc_traits.hpp"
#include "ft_stl/construct.hpp"
#include "ft_stl/iterator.hpp"
#include "ft_stl/iterator_base_types.hpp"
#include "ft_stl/iterator_base_funcs.hpp"
#include "ft_stl/uninitialized.hpp"
#include <memory>

namespace ft {
#ifndef DEQUE_BUF_SIZE
#define DEQUE_BUF_SIZE 512
#endif

inline size_t __deque_buf_size(size_t size) {
	return (size < DEQUE_BUF_SIZE ? size_t(DEQUE_BUF_SIZE / size) : size_t(1));
}

template<typename Type, typename Reference, typename Pointer>
struct DequeIterator {
	typedef DequeIterator<Type, Type &, Type *> iterator;
	typedef DequeIterator<Type, const Type &, const Type *> const_iterator;
	typedef Type *ElementPointer;
	typedef Type **MapPointer;

	static size_t self_buffer_size() { return __deque_buf_size(sizeof(Type)); }

	typedef ft::random_access_iterator_tag iterator_category;
	typedef Type value_type;
	typedef Pointer pointer;
	typedef Reference reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef DequeIterator Self;

	ElementPointer _current;
	ElementPointer _first;
	ElementPointer _last;
	MapPointer _node;

	DequeIterator(ElementPointer x, MapPointer y)
		: _current(x), _first(*y), _last(*y + self_buffer_size()), _node(y) { }

	DequeIterator() : _current(), _first(), _last(), _node() { }

	DequeIterator(const iterator &x)
		: _current(x._current), _first(x._first), _last(x._last), _node(x._node) { }

	iterator _const_cast() const { return iterator(_current, _node); }

	reference operator*() const { return *_current; }
	pointer operator->() const { return _current; }

	Self &operator++() {
		++_current;
		if (_current == _last) {
			_set_node(_node + 1);
			_current = _first;
		}
		return *this;
	}

	Self operator++(int) {
		Self tmp = *this;
		++*this;
		return tmp;
	}

	Self &operator--() {
		if (_current == _first) {
			_set_node(_node - 1);
			_current = _last;
		}
		--_current;
		return *this;
	}

	Self operator--(int) {
		Self tmp = *this;
		--*this;
		return tmp;
	}

	Self &operator+=(difference_type num) {
		const difference_type offset = num + (_current - _first);
		if (offset >= 0 && offset < difference_type(self_buffer_size()))
			_current += num;
		else {
			const difference_type node_offset = offset > 0 ? offset / difference_type(self_buffer_size())
														   : -difference_type((-offset - 1) / self_buffer_size()) - 1;
			_set_node(_node + node_offset);
			_current = _first + (offset - node_offset * difference_type(self_buffer_size()));
		}
		return *this;
	}

	Self &operator-=(difference_type num) { return *this += -num; }

	reference operator[](difference_type num) const { return *(*this + num); }

	void _set_node(MapPointer new_node) {
		_node = new_node;
		_first = *new_node;
		_last = _first + difference_type(self_buffer_size());
	}

	friend bool operator==(const Self &x, const Self &y) { return x._current == y._current; }

	template<typename ReferenceR, typename PointerR>
	friend bool operator==(const Self &x, const DequeIterator<Type, ReferenceR, PointerR> &y) {
		return x._current == y._current;
	}

	friend bool operator!=(const Self &x, const Self &y) { return !(x == y); }

	template<typename ReferenceR, typename PointerR>
	friend bool operator!=(const Self &x, const DequeIterator<Type, ReferenceR, PointerR> &y) {
		return !(x == y);
	}

	friend bool operator<(const Self &x, const Self &y) {
		return (x._node == y._node) ? (x._current < y._current) : (x._node < y._node);
	}

	template<typename ReferenceR, typename PointerR>
	friend bool operator<(const Self &x, const DequeIterator<Type, ReferenceR, PointerR> &y) {
		return (x._node == y._node) ? (x._current < y._current) : (x._node < y._node);
	}

	friend bool operator>(const Self &x, const Self &y) { return y < x; }

	template<typename ReferenceR, typename PointerR>
	friend bool operator>(const Self &x, const DequeIterator<Type, ReferenceR, PointerR> &y) {
		return y < x;
	}

	friend bool operator<=(const Self &x, const Self &y) { return !(y < x); }

	template<typename ReferenceR, typename PointerR>
	friend bool operator<=(const Self &x, const DequeIterator<Type, ReferenceR, PointerR> &y) {
		return !(y < x);
	}

	friend bool operator>=(const Self &x, const Self &y) { return !(x < y); }

	template<typename ReferenceR, typename PointerR>
	friend bool operator>=(const Self &x, const DequeIterator<Type, ReferenceR, PointerR> &y) {
		return !(x < y);
	}

	friend difference_type operator-(const Self &x, const Self &y) {
		return difference_type(self_buffer_size()) * (x._node - y._node - 1) +
			   (x._current - x._first) + (y._last - y._current);
	}

	template<typename ReferenceR, typename PointerR>
	friend difference_type operator-(const Self &x, const DequeIterator<Type, ReferenceR, PointerR> &y) {
		return difference_type(self_buffer_size()) * (x._node - y._node - 1) + (x._current - x._first) + (y._last - y._current);
	}

	friend Self operator+(const Self &x, difference_type n) {
		Self tmp = x;
		tmp += n;
		return tmp;
	}

	friend Self operator-(const Self &x, difference_type n) {
		Self tmp = x;
		tmp -= n;
		return tmp;
	}

	friend Self operator+(difference_type n, const Self &x) { return x + n; }
};

template<typename Type, typename Alloc>
class DequeBase {
  protected:
	typedef typename alloc_traits<Alloc>::template rebind<Type>::other TemplateAllocType;
	typedef alloc_traits<TemplateAllocType> AllocTraits;

	typedef Type *Pointer;
	typedef const Type *ConstPointer;

	typedef typename AllocTraits::template rebind<Pointer>::other MapAllocType;
	typedef alloc_traits<MapAllocType> MapAllocTraits;

	typedef Alloc allocator_type;

	allocator_type get_allocator() const { return allocator_type(_get_type_allocator()); }

	typedef DequeIterator<Type, Type &, Pointer> iterator;
	typedef DequeIterator<Type, const Type &, ConstPointer> const_iterator;

	DequeBase() : _impl() { _initialize_map(0); }

	DequeBase(size_t number_of_elements) : _impl() { _initialize_map(number_of_elements); }
	DequeBase(const allocator_type &alloc, size_t number_of_elements) : _impl(alloc) {
		_initialize_map(number_of_elements);
	}
	DequeBase(const allocator_type &alloc) : _impl(alloc) { }

	~DequeBase();

	typedef typename iterator::MapPointer MapPointer;

	struct DequeImplData {
		MapPointer _map;
		size_t _map_size;
		iterator _start;
		iterator _finish;

		DequeImplData() : _map(), _map_size(), _start(), _finish() { }

		void _swap_data(DequeImplData &x) { ft::swap(*this, x); }
	};

	struct DequeImpl : public TemplateAllocType, public DequeImplData {
		DequeImpl() : TemplateAllocType() { }
		DequeImpl(const TemplateAllocType &alloc) : TemplateAllocType(alloc) { }
	};

	TemplateAllocType &_get_type_allocator() { return this->_impl; }
	const TemplateAllocType &_get_type_allocator() const { return this->_impl; }

	MapAllocType _get_map_allocator() const { return MapAllocType(_get_type_allocator()); }

	Pointer _allocate_node() {
		typedef alloc_traits<TemplateAllocType> Traits;
		return Traits::allocate(_impl, __deque_buf_size(sizeof(Type)));
	}

	void _deallocate_node(Pointer ptr) {
		typedef alloc_traits<TemplateAllocType> Traits;
		Traits::deallocate(_impl, ptr, __deque_buf_size(sizeof(Type)));
	}

	MapPointer _allocate_map(size_t n) {
		MapAllocType map_allocator = _get_map_allocator();
		return MapAllocTraits::allocate(map_allocator, n);
	}

	void _deallocate_map(MapPointer ptr, size_t n) {
		MapAllocType map_allocator = _get_map_allocator();
		MapAllocTraits::deallocate(map_allocator, ptr, n);
	}

	void _initialize_map(size_t);
	void _create_nodes(MapPointer nstart, MapPointer nfinish);
	void _destroy_nodes(MapPointer nstart, MapPointer nfinish);
	enum { self_initial_map_size = 8 };

	DequeImpl _impl;
};

template<typename Type, typename Alloc>
DequeBase<Type, Alloc>::~DequeBase() {
	if (this->_impl._map) {
		_destroy_nodes(this->_impl._start._node, this->_impl._finish._node + 1);
		_deallocate_map(this->_impl._map, this->_impl._map_size);
	}
}

template<typename Type, typename Alloc>
void DequeBase<Type, Alloc>::_initialize_map(size_t number_of_elements) {
	const size_t number_of_nodes = (number_of_elements / __deque_buf_size(sizeof(Type)) + 1);

	this->_impl._map_size = ft::max((size_t)self_initial_map_size, size_t(number_of_nodes + 2));
	this->_impl._map = _allocate_map(this->_impl._map_size);

	MapPointer nstart = (this->_impl._map + (this->_impl._map_size - number_of_nodes) / 2);
	MapPointer nfinish = nstart + number_of_nodes;

	try {
		_create_nodes(nstart, nfinish);
	} catch (...) {
		_deallocate_map(this->_impl._map, this->_impl._map_size);
		this->_impl._map = MapPointer();
		this->_impl._map_size = 0;
		throw;
	}

	this->_impl._start._set_node(nstart);
	this->_impl._finish._set_node(nfinish - 1);
	this->_impl._start._current = _impl._start._first;
	this->_impl._finish._current = (this->_impl._finish._first + number_of_elements % __deque_buf_size(sizeof(Type)));
}

template<typename Type, typename Alloc>
void DequeBase<Type, Alloc>::_create_nodes(MapPointer nstart, MapPointer nfinish) {
	MapPointer current;

	try {
		for (current = nstart; current < nfinish; ++current)
			*current = this->_allocate_node();
	} catch (...) {
		_destroy_nodes(nstart, current);
		throw;
	}
}

template<typename Type, typename Alloc>
void DequeBase<Type, Alloc>::_destroy_nodes(MapPointer nstart, MapPointer nfinish) {
	for (MapPointer num = nstart; num < nfinish; ++num)
		_deallocate_node(*num);
}

template<typename Type, typename Alloc = std::allocator<Type> >
class deque : protected DequeBase<Type, Alloc> {
	typedef DequeBase<Type, Alloc> Base;
	typedef typename Base::TemplateAllocType TemplateAllocType;
	typedef typename Base::AllocTraits AllocTraits;
	typedef typename Base::MapPointer MapPointer;

  public:
	typedef Type value_type;

	typedef typename AllocTraits::pointer pointer;
	typedef typename AllocTraits::const_pointer const_pointer;
	typedef typename AllocTraits::reference reference;
	typedef typename AllocTraits::const_reference const_reference;

	typedef typename Base::iterator iterator;
	typedef typename Base::const_iterator const_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef Alloc allocator_type;

  private:
	static size_t self_buffer_size() { return __deque_buf_size(sizeof(Type)); }

	using Base::_allocate_map;
	using Base::_allocate_node;
	using Base::_create_nodes;
	using Base::_deallocate_map;
	using Base::_deallocate_node;
	using Base::_destroy_nodes;
	using Base::_get_type_allocator;
	using Base::_impl;
	using Base::_initialize_map;

  public:
	deque() { }

	explicit deque(const allocator_type &alloc) : Base(alloc, 0) { }
	explicit deque(size_type size, const value_type &value = value_type(), const allocator_type &alloc = allocator_type())
		: Base(alloc, self_check_init_len(size, alloc)) {
		_fill_initialize(value);
	}

	deque(const deque &x) : Base(AllocTraits::self_select_on_copy(x._get_type_allocator()), x.size()) {
		ft::uninitialized_copy_a(x.begin(), x.end(), this->_impl._start, _get_type_allocator());
	}

	template<typename InputIterator>
	deque(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : Base(alloc) {
		typedef typename ft::is_integer<InputIterator>::type Integral;
		_initialize_dispatch(first, last, Integral());
	}

	~deque() { _destroy_data(begin(), end(), _get_type_allocator()); }

	deque &operator=(const deque &x);

	void assign(size_type size, const value_type &value) { _fill_assign(size, value); }

	template<typename InputIterator>
	void assign(InputIterator first, InputIterator last) {
		typedef typename ft::is_integer<InputIterator>::type Integral;
		_assign_dispatch(first, last, Integral());
	}

	allocator_type get_allocator() const { return Base::get_allocator(); }

	iterator begin() { return this->_impl._start; }
	const_iterator begin() const { return this->_impl._start; }

	iterator end() { return this->_impl._finish; }
	const_iterator end() const { return this->_impl._finish; }

	reverse_iterator rbegin() { return reverse_iterator(this->_impl._finish); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_impl._finish); }

	reverse_iterator rend() { return reverse_iterator(this->_impl._start); }
	const_reverse_iterator rend() const { return const_reverse_iterator(this->_impl._start); }

	size_type size() const { return this->_impl._finish - this->_impl._start; }
	size_type max_size() const { return self_max_size(_get_type_allocator()); }

	void resize(size_type new_size, value_type x = value_type()) {
		const size_type length = size();
		if (new_size > length)
			_fill_insert(this->_impl._finish, new_size - length, x);
		else if (new_size < length)
			_erase_at_end(this->_impl._start + difference_type(new_size));
	}

	bool empty() const { return this->_impl._finish == this->_impl._start; }

	reference operator[](size_type offset) { return this->_impl._start[difference_type(offset)]; }
	const_reference operator[](size_type offset) const {
		return this->_impl._start[difference_type(offset)];
	}

  protected:
	void _range_check(size_type offset) const {
		if (offset >= this->size())
			throw("deque::_range_check");
	}

  public:
	reference at(size_type offset) {
		_range_check(offset);
		return (*this)[offset];
	}

	const_reference at(size_type offset) const {
		_range_check(offset);
		return (*this)[offset];
	}

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

	void push_front(const value_type &x) {
		if (this->_impl._start._current != this->_impl._start._first) {
			AllocTraits::construct(this->_impl, this->_impl._start._current - 1, x);
			--this->_impl._start._current;
		} else
			_push_front_aux(x);
	}

	void push_back(const value_type &x) {
		if (this->_impl._finish._current != this->_impl._finish._last - 1) {
			AllocTraits::construct(this->_impl, this->_impl._finish._current, x);
			++this->_impl._finish._current;
		} else
			_push_back_aux(x);
	}

	void pop_front() {
		if (this->_impl._start._current != this->_impl._start._last - 1) {
			AllocTraits::destroy(_get_type_allocator(), this->_impl._start._current);
			++this->_impl._start._current;
		} else
			_pop_front_aux();
	}

	void pop_back() {
		if (this->_impl._finish._current != this->_impl._finish._first) {
			--this->_impl._finish._current;
			AllocTraits::destroy(_get_type_allocator(), this->_impl._finish._current);
		} else
			_pop_back_aux();
	}

	iterator insert(iterator ptr_position, const value_type &x);
	void insert(iterator ptr_position, size_type num, const value_type &x) {
		_fill_insert(ptr_position, num, x);
	}

	template <typename InputIterator> void insert(iterator ptr_position, InputIterator first, InputIterator last) {
		typedef typename ft::is_integer<InputIterator>::type Integral;
		_insert_dispatch(ptr_position, first, last, Integral());
	}

	iterator erase(iterator ptr_position) { return _erase(ptr_position._const_cast()); }
	iterator erase(iterator first, iterator last) {
		return _erase(first._const_cast(), last._const_cast());
	}

	void swap(deque &x) {
		_impl._swap_data(x._impl);
		AllocTraits::self_on_swap(_get_type_allocator(), x._get_type_allocator());
	}

	void clear() { _erase_at_end(begin()); }

  protected:
	template<typename Integer>
	void _initialize_dispatch(Integer num, Integer x, true_type) {
		_initialize_map(self_check_init_len(static_cast<size_type>(num), _get_type_allocator()));
		_fill_initialize(x);
	}

	template<typename InputIterator>
	void _initialize_dispatch(InputIterator first, InputIterator last, false_type) {
		_range_initialize(first, last, ft::get_iterator_category(first));
	}

	static size_t self_check_init_len(size_t num, const allocator_type &alloc) {
		if (num > self_max_size(alloc))
			throw("cannot create ft::deque larger than max_size()");
		return num;
	}

	static size_type self_max_size(const TemplateAllocType &alloc) { return AllocTraits::max_size(alloc); }

	template<typename InputIterator>
	void _range_initialize(InputIterator first, InputIterator last, ft::input_iterator_tag);

	template<typename ForwardIterator>
	void _range_initialize(ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag);

	void _fill_initialize(const value_type &value);

	template<typename Integer>
	void _assign_dispatch(Integer num, Integer val, true_type) {
		_fill_assign(num, val);
	}

	template<typename InputIterator>
	void _assign_dispatch(InputIterator first, InputIterator last, false_type) {
		_assign_aux(first, last, ft::get_iterator_category(first));
	}

	template<typename InputIterator>
	void _assign_aux(InputIterator first, InputIterator last, ft::input_iterator_tag);

	template<typename ForwardIterator>
	void _assign_aux(ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag) {
		const size_type length = ft::distance(first, last);

		if (length > size()) {
			ForwardIterator mid = first;

			ft::advance(mid, size());
			ft::copy(first, mid, begin());

			_range_insert_aux(end(), mid, last, ft::get_iterator_category(first));
		} else
			_erase_at_end(ft::copy(first, last, begin()));
	}

	void _fill_assign(size_type num, const value_type &value) {
		if (num > size()) {
			ft::fill(begin(), end(), value);
			_fill_insert(end(), num - size(), value);
		} else {
			_erase_at_end(begin() + difference_type(num));
			ft::fill(begin(), end(), value);
		}
	}

	void _push_back_aux(const value_type &);
	void _push_front_aux(const value_type &);
	void _pop_back_aux();
	void _pop_front_aux();

	template<typename Integer>
	void _insert_dispatch(iterator ptr_pos, Integer num, Integer x, true_type) {
		_fill_insert(ptr_pos, num, x);
	}

	template<typename InputIterator>
	void _insert_dispatch(iterator ptr_pos, InputIterator first, InputIterator last, false_type) {
		_range_insert_aux(ptr_pos, first, last, ft::get_iterator_category(first));
	}

	template<typename InputIterator>
	void _range_insert_aux(iterator pos, InputIterator first, InputIterator last, ft::input_iterator_tag);

	template<typename ForwardIterator>
	void _range_insert_aux(iterator pos, ForwardIterator first, ForwardIterator last,
						   ft::forward_iterator_tag);

	void _fill_insert(iterator ptros, size_type num, const value_type &x);

	iterator _insert_aux(iterator ptros, const value_type &x);
	void _insert_aux(iterator ptros, size_type num, const value_type &x);

	template<typename ForwardIterator>
	void _insert_aux(iterator ptros, ForwardIterator first, ForwardIterator last, size_type num);

	void _destroy_data_aux(iterator first, iterator last);

	template<typename Alloc1>
	void _destroy_data(iterator first, iterator last, const Alloc1 &) {
		_destroy_data_aux(first, last);
	}

	void _destroy_data(iterator first, iterator last, const std::allocator<Type> &) {
		if (!__has_trivial_destructor(value_type))
			_destroy_data_aux(first, last);
	}

	void erase_at_begin_internal(iterator ptros) {
		_destroy_data(begin(), ptros, _get_type_allocator());
		_destroy_nodes(this->_impl._start._node, ptros._node);
		this->_impl._start = ptros;
	}

	void _erase_at_end(iterator ptros) {
		_destroy_data(ptros, end(), _get_type_allocator());
		_destroy_nodes(ptros._node + 1, this->_impl._finish._node + 1);
		this->_impl._finish = ptros;
	}

	iterator _erase(iterator ptros);
	iterator _erase(iterator first, iterator last);

	iterator _reserve_elements_at_front(size_type num) {
		const size_type vacancies = this->_impl._start._current - this->_impl._start._first;
		if (num > vacancies)
			_new_elements_at_front(num - vacancies);
		return this->_impl._start - difference_type(num);
	}

	iterator _reserve_elements_at_back(size_type num) {
		const size_type vacancies = (this->_impl._finish._last - this->_impl._finish._current) - 1;
		if (num > vacancies)
			_new_elements_at_back(num - vacancies);
		return this->_impl._finish + difference_type(num);
	}

	void _new_elements_at_front(size_type new_elements);
	void _new_elements_at_back(size_type new_elements);

	void _reserve_map_at_back(size_type nodes_to_add = 1) {
		if (nodes_to_add + 1 > this->_impl._map_size - (this->_impl._finish._node - this->_impl._map))
			_reallocate_map(nodes_to_add, false);
	}

	void _reserve_map_at_front(size_type nodes_to_add = 1) {
		if (nodes_to_add > size_type(this->_impl._start._node - this->_impl._map))
			_reallocate_map(nodes_to_add, true);
	}

	void _reallocate_map(size_type nodes_to_add, bool add_at_front);
};

template<typename Type, typename Alloc>
inline bool operator==(const deque<Type, Alloc> &x, const deque<Type, Alloc> &y) {
	return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template<typename Type, typename Alloc>
inline bool operator<(const deque<Type, Alloc> &x, const deque<Type, Alloc> &y) {
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template<typename Type, typename Alloc>
inline bool operator!=(const deque<Type, Alloc> &x, const deque<Type, Alloc> &y) {
	return !(x == y);
}

template<typename Type, typename Alloc>
inline bool operator>(const deque<Type, Alloc> &x, const deque<Type, Alloc> &y) {
	return y < x;
}

template<typename Type, typename Alloc>
inline bool operator<=(const deque<Type, Alloc> &x, const deque<Type, Alloc> &y) {
	return !(y < x);
}

template<typename Type, typename Alloc>
inline bool operator>=(const deque<Type, Alloc> &x, const deque<Type, Alloc> &y) {
	return !(x < y);
}

template<typename Type, typename Alloc>
inline void swap(deque<Type, Alloc> &x, deque<Type, Alloc> &y) {
	x.swap(y);
}

template<typename Type, typename Alloc>
deque<Type, Alloc> &deque<Type, Alloc>::operator=(const deque &x) {
	if (&x != this) {
		const size_type length = size();

		if (length >= x.size())
			_erase_at_end(ft::copy(x.begin(), x.end(), this->_impl._start));
		else {
			const_iterator mid = x.begin() + difference_type(length);
			ft::copy(x.begin(), mid, this->_impl._start);
			_range_insert_aux(this->_impl._finish, mid, x.end(), ft::random_access_iterator_tag());
		}
	}

	return *this;
}

template<typename Type, typename Alloc>
typename deque<Type, Alloc>::iterator deque<Type, Alloc>::insert(iterator ptr_position, const value_type &x) {
	if (ptr_position._current == this->_impl._start._current) {
		push_front(x);
		return this->_impl._start;
	} else if (ptr_position._current == this->_impl._finish._current) {
		push_back(x);
		iterator tmp = this->_impl._finish;
		--tmp;
		return tmp;
	} else
		return _insert_aux(ptr_position._const_cast(), x);
}

template<typename Type, typename Alloc>
typename deque<Type, Alloc>::iterator deque<Type, Alloc>::_erase(iterator ptr_position) {
	iterator next = ptr_position;
	++next;
	const difference_type index = ptr_position - begin();

	if (static_cast<size_type>(index) < (size() >> 1)) {
		if (ptr_position != begin())
			ft::copy_backward(begin(), ptr_position, next);
		pop_front();
	} else {
		if (next != end())
			ft::copy(next, end(), ptr_position);
		pop_back();
	}

	return begin() + index;
}

template<typename Type, typename Alloc>
typename deque<Type, Alloc>::iterator deque<Type, Alloc>::_erase(iterator first, iterator last) {
	if (first == last)
		return first;

	else if (first == begin() && last == end()) {
		clear();
		return end();

	} else {
		const difference_type num = last - first;
		const difference_type elements_before = first - begin();

		if (static_cast<size_type>(elements_before) <= (size() - num) / 2) {
			if (first != begin())
				ft::copy_backward(begin(), first, last);
			erase_at_begin_internal(begin() + num);
		} else {
			if (last != end())
				ft::copy(last, end(), first);
			_erase_at_end(end() - num);
		}

		return begin() + elements_before;
	}
}

template<typename Type, class Alloc>
template<typename InputIterator>
void deque<Type, Alloc>::_assign_aux(InputIterator first, InputIterator last, ft::input_iterator_tag) {
	iterator current = begin();
	for (; first != last && current != end(); ++current, (void)++first)
		*current = *first;
	if (first == last)
		_erase_at_end(current);
	else
		_range_insert_aux(end(), first, last, ft::get_iterator_category(first));
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_fill_insert(iterator ptros, size_type num, const value_type &x) {
	if (ptros._current == this->_impl._start._current) {
		iterator new_start = _reserve_elements_at_front(num);
		try {
			ft::uninitialized_fill_a(new_start, this->_impl._start, x, _get_type_allocator());
			this->_impl._start = new_start;
		} catch (...) {
			_destroy_nodes(new_start._node, this->_impl._start._node);
			throw;
		}
	} else if (ptros._current == this->_impl._finish._current) {
		iterator new_finish = _reserve_elements_at_back(num);
		try {
			uninitialized_fill_a(this->_impl._finish, new_finish, x, _get_type_allocator());
			this->_impl._finish = new_finish;
		} catch (...) {
			_destroy_nodes(this->_impl._finish._node + 1, new_finish._node + 1);
			throw;
		}
	} else
		_insert_aux(ptros, num, x);
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_fill_initialize(const value_type &value) {
	MapPointer current;
	try {
		for (current = this->_impl._start._node;
			 current < this->_impl._finish._node; ++current)
			ft::uninitialized_fill_a(*current, *current + self_buffer_size(), value, _get_type_allocator());
		ft::uninitialized_fill_a(this->_impl._finish._first, this->_impl._finish._current, value, _get_type_allocator());
	} catch (...) {
		ft::destroy(this->_impl._start, iterator(*current, current), _get_type_allocator());
		throw;
	}
}

template<typename Type, typename Alloc>
template<typename InputIterator>
void deque<Type, Alloc>::_range_initialize(InputIterator first, InputIterator last, ft::input_iterator_tag) {
	this->_initialize_map(0);
	try {
		for (; first != last; ++first)
			push_back(*first);
	} catch (...) {
		clear();
		throw;
	}
}

template<typename Type, typename Alloc>
template<typename ForwardIterator>
void deque<Type, Alloc>::_range_initialize(ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag) {
	const size_type distance = ft::distance(first, last);
	this->_initialize_map(distance);

	MapPointer current_node;
	try {
		for (current_node = this->_impl._start._node;
			 current_node < this->_impl._finish._node; ++current_node) {
			ForwardIterator mid = first;
			ft::advance(mid, self_buffer_size());
			ft::uninitialized_copy_a(first, mid, *current_node, _get_type_allocator());
			first = mid;
		}
		ft::uninitialized_copy_a(first, last, this->_impl._finish._first, _get_type_allocator());
	} catch (...) {
		ft::destroy(this->_impl._start, iterator(*current_node, current_node), _get_type_allocator());
		throw;
	}
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_push_back_aux(const value_type &tpl) {
	_reserve_map_at_back();
	*(this->_impl._finish._node + 1) = this->_allocate_node();

	try {
		this->_impl.construct(this->_impl._finish._current, tpl);
		this->_impl._finish._set_node(this->_impl._finish._node + 1);
		this->_impl._finish._current = this->_impl._finish._first;
	} catch (...) {
		_deallocate_node(*(this->_impl._finish._node + 1));
		throw;
	}
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_push_front_aux(const value_type &tpl) {
	_reserve_map_at_front();
	*(this->_impl._start._node - 1) = this->_allocate_node();

	try {
		this->_impl._start._set_node(this->_impl._start._node - 1);
		this->_impl._start._current = this->_impl._start._last - 1;
		this->_impl.construct(this->_impl._start._current, tpl);
	} catch (...) {
		++this->_impl._start;
		_deallocate_node(*(this->_impl._start._node - 1));
		throw;
	}
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_pop_back_aux() {
	_deallocate_node(this->_impl._finish._first);
	this->_impl._finish._set_node(this->_impl._finish._node - 1);
	this->_impl._finish._current = this->_impl._finish._last - 1;
	AllocTraits::destroy(_get_type_allocator(), this->_impl._finish._current);
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_pop_front_aux() {
	AllocTraits::destroy(_get_type_allocator(), this->_impl._start._current);
	_deallocate_node(this->_impl._start._first);
	this->_impl._start._set_node(this->_impl._start._node + 1);
	this->_impl._start._current = this->_impl._start._first;
}

template<typename Type, typename Alloc>
template<typename InputIterator>
void deque<Type, Alloc>::_range_insert_aux(iterator pos, InputIterator first, InputIterator last, ft::input_iterator_tag) {
	ft::copy(first, last, ft::inserter(*this, pos));
}

template<typename Type, typename Alloc>
template<typename ForwardIterator>
void deque<Type, Alloc>::_range_insert_aux(iterator pos, ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag) {
	const size_type n = ft::distance(first, last);
	if (pos._current == this->_impl._start._current) {
		iterator new_start = _reserve_elements_at_front(n);
		try {
			ft::uninitialized_copy_a(first, last, new_start, _get_type_allocator());
			this->_impl._start = new_start;
		} catch (...) {
			_destroy_nodes(new_start._node, this->_impl._start._node);
			throw;
		}
	} else if (pos._current == this->_impl._finish._current) {
		iterator new_finish = _reserve_elements_at_back(n);
		try {
			ft::uninitialized_copy_a(first, last, this->_impl._finish, _get_type_allocator());
			this->_impl._finish = new_finish;
		} catch (...) {
			_destroy_nodes(this->_impl._finish._node + 1, new_finish._node + 1);
			throw;
		}
	} else
		_insert_aux(pos, first, last, n);
}

template<typename Type, typename Alloc>
typename deque<Type, Alloc>::iterator deque<Type, Alloc>::_insert_aux(iterator ptros, const value_type &x) {
	value_type x_copy = x;
	difference_type index = ptros - this->_impl._start;

	if (static_cast<size_type>(index) < size() / 2) {
		push_front(front());
		iterator front1 = this->_impl._start;
		++front1;
		iterator front2 = front1;
		++front2;
		ptros = this->_impl._start + index;
		iterator ptros1 = ptros;
		++ptros1;
		ft::copy(front2, ptros1, front1);

	} else {
		push_back(back());
		iterator back1 = this->_impl._finish;
		--back1;
		iterator back2 = back1;
		--back2;
		ptros = this->_impl._start + index;
		ft::copy_backward(ptros, back2, back1);
	}

	*ptros = x_copy;

	return ptros;
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_insert_aux(iterator ptros, size_type num, const value_type &x) {
	const difference_type elements_before = ptros - this->_impl._start;
	const size_type length = this->size();
	value_type x_copy = x;

	if (elements_before < difference_type(length / 2)) {
		iterator new_start = _reserve_elements_at_front(num);
		iterator old_start = this->_impl._start;
		ptros = this->_impl._start + elements_before;

		try {
			if (elements_before >= difference_type(num)) {
				iterator start_number = (this->_impl._start + difference_type(num));
				ft::uninitialized_copy_a(this->_impl._start, start_number, new_start, _get_type_allocator());
				this->_impl._start = new_start;
				ft::copy(start_number, ptros, old_start);
				ft::fill(ptros - difference_type(num), ptros, x_copy);

			} else {
				ft::uninitialized_fill_move(this->_impl._start, ptros, new_start, this->_impl._start, x_copy, _get_type_allocator());
				this->_impl._start = new_start;
				ft::fill(old_start, ptros, x_copy);
			}
		} catch (...) {
			_destroy_nodes(new_start._node, this->_impl._start._node);
			throw;
		}
	} else {
		iterator new_finish = _reserve_elements_at_back(num);
		iterator old_finish = this->_impl._finish;
		const difference_type elements_after = difference_type(length) - elements_before;
		ptros = this->_impl._finish - elements_after;

		try {
			if (elements_after > difference_type(num)) {
				iterator finish_number = (this->_impl._finish - difference_type(num));
				ft::uninitialized_copy_a(finish_number, this->_impl._finish, this->_impl._finish, _get_type_allocator());
				this->_impl._finish = new_finish;
				ft::copy_backward(ptros, finish_number, old_finish);
				ft::fill(ptros, ptros + difference_type(num), x_copy);

			} else {
				ft::uninitialized_fill_move(this->_impl._finish, ptros + difference_type(num), x_copy, ptros, this->_impl._finish, _get_type_allocator());
				this->_impl._finish = new_finish;
				ft::fill(ptros, old_finish, x_copy);
			}
		} catch (...) {
			_destroy_nodes(this->_impl._finish._node + 1, new_finish._node + 1);
			throw;
		}
	}
}

template<typename Type, typename Alloc>
template<typename ForwardIterator>
void deque<Type, Alloc>::_insert_aux(iterator ptros, ForwardIterator first, ForwardIterator last, size_type num) {
	const difference_type elements_before = ptros - this->_impl._start;
	const size_type length = size();

	if (static_cast<size_type>(elements_before) < length / 2) {
		iterator new_start = _reserve_elements_at_front(num);
		iterator old_start = this->_impl._start;

		ptros = this->_impl._start + elements_before;

		try {
			if (elements_before >= difference_type(num)) {
				iterator start_numer = (this->_impl._start + difference_type(num));
				ft::uninitialized_copy_a(this->_impl._start, start_numer, new_start, _get_type_allocator());
				this->_impl._start = new_start;
				ft::copy(start_numer, ptros, old_start);
				ft::copy(first, last, ptros - difference_type(num));
			} else {
				ForwardIterator mid = first;
				ft::advance(mid, difference_type(num) - elements_before);
				ft::uninitialized_copy_move(this->_impl._start, ptros, first, mid, new_start, _get_type_allocator());
				this->_impl._start = new_start;
				ft::copy(mid, last, old_start);
			}
		} catch (...) {
			_destroy_nodes(new_start._node, this->_impl._start._node);
			throw;
		}
	} else {
		iterator new_finish = _reserve_elements_at_back(num);
		iterator old_finish = this->_impl._finish;
		const difference_type elements_after = difference_type(length) - elements_before;
		ptros = this->_impl._finish - elements_after;

		try {
			if (elements_after > difference_type(num)) {
				iterator finish_number = (this->_impl._finish - difference_type(num));
				ft::uninitialized_copy_a(finish_number, this->_impl._finish, this->_impl._finish, _get_type_allocator());
				this->_impl._finish = new_finish;
				ft::copy_backward(ptros, finish_number, old_finish);
				ft::copy(first, last, ptros);
			} else {
				ForwardIterator mid = first;
				ft::advance(mid, elements_after);
				ft::uninitialized_copy_move(mid, last, ptros, this->_impl._finish, this->_impl._finish, _get_type_allocator());
				this->_impl._finish = new_finish;
				ft::copy(first, mid, ptros);
			}
		} catch (...) {
			_destroy_nodes(this->_impl._finish._node + 1, new_finish._node + 1);
			throw;
		}
	}
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_destroy_data_aux(iterator first, iterator last) {
	for (MapPointer node = first._node + 1; node < last._node; ++node)
		ft::destroy(*node, *node + self_buffer_size(), _get_type_allocator());

	if (first._node != last._node) {
		ft::destroy(first._current, first._last, _get_type_allocator());
		ft::destroy(last._first, last._current, _get_type_allocator());
	} else
		ft::destroy(first._current, last._current, _get_type_allocator());
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_new_elements_at_front(size_type new_elements) {
	if (this->max_size() - this->size() < new_elements)
		throw("deque::new_elements_at_front");

	const size_type new_nodes = ((new_elements + self_buffer_size() - 1) / self_buffer_size());
	_reserve_map_at_front(new_nodes);
	size_type i;

	try {
		for (i = 1; i <= new_nodes; ++i)
			*(this->_impl._start._node - i) = this->_allocate_node();
	} catch (...) {
		for (size_type j = 1; j < i; ++j)
			_deallocate_node(*(this->_impl._start._node - j));
		throw;
	}
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_new_elements_at_back(size_type new_elements) {
	if (this->max_size() - this->size() < new_elements)
		throw("deque::new_elements_at_back");

	const size_type new_nodes = ((new_elements + self_buffer_size() - 1) / self_buffer_size());
	_reserve_map_at_back(new_nodes);
	size_type i;

	try {
		for (i = 1; i <= new_nodes; ++i)
			*(this->_impl._finish._node + i) = this->_allocate_node();
	} catch (...) {
		for (size_type j = 1; j < i; ++j)
			_deallocate_node(*(this->_impl._finish._node + j));
		throw;
	}
}

template<typename Type, typename Alloc>
void deque<Type, Alloc>::_reallocate_map(size_type nodes_to_add, bool add_at_front) {
	const size_type old_number_of_nodes = this->_impl._finish._node - this->_impl._start._node + 1;
	const size_type new_number_of_nodes = old_number_of_nodes + nodes_to_add;

	MapPointer new_nstart;
	if (this->_impl._map_size > 2 * new_number_of_nodes) {
		new_nstart = this->_impl._map + (this->_impl._map_size - new_number_of_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
		if (new_nstart < this->_impl._start._node)
			ft::copy(this->_impl._start._node, this->_impl._finish._node + 1, new_nstart);
		else
			ft::copy_backward(this->_impl._start._node, this->_impl._finish._node + 1, new_nstart + old_number_of_nodes);
	} else {
		size_type new_map_size = this->_impl._map_size + ft::max(this->_impl._map_size, nodes_to_add) + 2;

		MapPointer new_map = this->_allocate_map(new_map_size);
		new_nstart = new_map + (new_map_size - new_number_of_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
		ft::copy(this->_impl._start._node, this->_impl._finish._node + 1, new_nstart);
		_deallocate_map(this->_impl._map, this->_impl._map_size);

		this->_impl._map = new_map;
		this->_impl._map_size = new_map_size;
	}

	this->_impl._start._set_node(new_nstart);
	this->_impl._finish._set_node(new_nstart + old_number_of_nodes - 1);
}

template<typename Type>
void fill(const DequeIterator<Type, Type &, Type *> &first, const DequeIterator<Type, Type &, Type *> &last, const Type &value) {
	typedef typename DequeIterator<Type, Type &, Type *>::_Self _Self;

	for (typename _Self::MapPointer node = first._node + 1; node < last._node; ++node)
		ft::fill(*node, *node + _Self::self_buffer_size(), value);

	if (first._node != last._node) {
		ft::fill(first._current, first._last, value);
		ft::fill(last._first, last._current, value);
	} else
		ft::fill(first._current, last._current, value);
}

template<typename Type>
DequeIterator<Type, Type &, Type *>
copy(DequeIterator<Type, const Type &, const Type *> first, DequeIterator<Type, const Type &, const Type *> last,
	 DequeIterator<Type, Type &, Type *> result) {
	typedef typename DequeIterator<Type, Type &, Type *>::_Self _Self;
	typedef typename _Self::difference_type difference_type;

	difference_type length = last - first;

	while (length > 0) {
		const difference_type c_length = ft::min(length, ft::min(first._last - first._current, result._last - result._current));
		ft::copy(first._current, first._current + c_length, result._current);
		first += c_length;
		result += c_length;
		length -= c_length;
	}

	return result;
}

template<typename Type>
DequeIterator<Type, Type &, Type *>
copy_backward(DequeIterator<Type, const Type &, const Type *> first, DequeIterator<Type, const Type &, const Type *> last,
			  DequeIterator<Type, Type &, Type *> result) {
	typedef typename DequeIterator<Type, Type &, Type *>::_Self _Self;
	typedef typename _Self::difference_type difference_type;

	difference_type length = last - first;
	while (length > 0) {
		difference_type l_length = last._current - last._first;
		Type *len = last._current;

		difference_type r_length = result._current - result._first;
		Type *r_end = result._current;

		if (!l_length) {
			l_length = _Self::self_buffer_size();
			len = *(last._node - 1) + l_length;
		}
		if (!r_length) {
			r_length = _Self::self_buffer_size();
			r_end = *(result._node - 1) + r_length;
		}

		const difference_type c_length = ft::min(length, ft::min(l_length, r_length));
		ft::copy_backward(len - c_length, len, r_end);
		last -= c_length;
		result -= c_length;
		length -= c_length;
	}
	return result;
}

#undef DEQUE_BUF_SIZE

} // namespace ft

#endif