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

#include "ft_stl/algobase.hpp"
#include "ft_stl/alloc_traits.hpp"
#include "ft_stl/iterator.hpp"
#include "ft_stl/iterator_base_funcs.hpp"
#include "ft_stl/iterator_base_types.hpp"
#include "ft_stl/type_traits.hpp"
#include "ft_stl/construct.hpp"
#include "ft_stl/uninitialized.hpp"
#include <memory>

namespace ft {
	template<typename Type, typename Alloc>
	struct VectorBase {
		typedef typename alloc_traits<Alloc>::template rebind<Type>::other TemplateAllocType;
		typedef typename alloc_traits<TemplateAllocType>::pointer pointer;

		struct VectorImplData {
			pointer _start;
			pointer _finish;
			pointer _end_of_storage;

			VectorImplData() : _start(), _finish(), _end_of_storage() { }

			void _copy_data(VectorImplData const &x) {
				_start = x._start;
				_finish = x._finish;
				_end_of_storage = x._end_of_storage;
			}

			void _swap_data(VectorImplData &x) {
				VectorImplData tmp;
				tmp._copy_data(*this);
				_copy_data(x);
				x._copy_data(tmp);
			}
		};

		struct VectorImpl : public TemplateAllocType, public VectorImplData {
			VectorImpl() : TemplateAllocType() {}
			VectorImpl(TemplateAllocType const &allocator) : TemplateAllocType(allocator) {}
		};

	public:
		typedef Alloc allocator_type;

		TemplateAllocType &_get_type_allocator() { return this->_impl; }
		const TemplateAllocType &_get_type_allocator() const { return this->_impl; }

		VectorBase() { }
		VectorBase(const allocator_type &allocator) : _impl(allocator) { }

		VectorBase(size_t num) : _impl() { _create_storage(num); }
		VectorBase(size_t num, const allocator_type &allocator) : _impl(allocator) { _create_storage(num); }
		~VectorBase() {
			_deallocate(_impl._start, _impl._end_of_storage - _impl._start);
		}

	public:
		VectorImpl _impl;

		pointer _allocate(size_t num) {
			typedef alloc_traits<TemplateAllocType> Traits;
			return num != 0 ? Traits::allocate(_impl, num) : pointer();
		}

		void _deallocate(pointer ptr, size_t num) {
			typedef alloc_traits<TemplateAllocType> Traits;
			if (ptr)
				Traits::deallocate(_impl, ptr, num);
		}

	protected:
		void _create_storage(size_t num) {
			this->_impl._start = this->_allocate(num);
			this->_impl._finish = this->_impl._start;
			this->_impl._end_of_storage = this->_impl._start + num;
		}
	};

	template<typename Type, typename Alloc = std::allocator<Type> >
	class vector : protected VectorBase<Type, Alloc> {
		typedef VectorBase<Type, Alloc> Base;
		typedef typename Base::TemplateAllocType TemplateAllocType;
		typedef alloc_traits<TemplateAllocType> AllocTraits;

	public:
		typedef Type value_type;
		typedef typename Base::pointer pointer;
		typedef typename AllocTraits::const_pointer const_pointer;
		typedef typename AllocTraits::reference reference;
		typedef typename AllocTraits::const_reference const_reference;
		typedef __ft_base::normal_iterator<pointer, vector> iterator;
		typedef __ft_base::normal_iterator<const_pointer, vector> const_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Alloc allocator_type;

	protected:
		using Base::_allocate;
		using Base::_deallocate;
		using Base::_get_type_allocator;
		using Base::_impl;

	public:
		vector() { }
		explicit vector(const allocator_type &a) : Base(a) { }
		explicit vector(size_type n, const value_type &value = value_type(), const allocator_type &a = allocator_type())
				: Base(self_check_init_len(n, a), a) {
			_fill_initialize(n, value);
		}

		vector(const vector &x)
		: Base(x.size(), AllocTraits::self_select_on_copy(x._get_type_allocator())) {
			this->_impl._finish = ft::uninitialized_copy_a(x.begin(), x.end(), this->_impl._start, _get_type_allocator());
		}

		template<typename InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &a = allocator_type()) : Base(a) {
			typedef typename ft::is_integer<InputIterator>::type Integral;
			_initialize_dispatch(first, last, Integral());
		}

		~vector() {
			ft::destroy(this->_impl._start, this->_impl._finish, _get_type_allocator());
		}

		vector &operator=(const vector &x);

		void assign(size_type n, const value_type &value) { _fill_assign(n, value); }
		template<typename InputIterator>
		void assign(InputIterator first, InputIterator last) {
			typedef typename ft::is_integer<InputIterator>::type Integral;
			_assign_dispatch(first, last, Integral());
		}

		iterator begin() { return iterator(this->_impl._start); }
		const_iterator begin() const { return const_iterator(this->_impl._start); }

		iterator end() { return iterator(this->_impl._finish); }
		const_iterator end() const { return const_iterator(this->_impl._finish); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		size_type size() const {
			return size_type(this->_impl._finish - this->_impl._start);
		}
		size_type max_size() const { return self_max_size(_get_type_allocator()); }

		void resize(size_type new_size, value_type x = value_type()) {
			if (new_size > size())
				_fill_insert(end(), new_size - size(), x);
			else if (new_size < size())
				_erase_at_end(this->_impl._start + new_size);
		}

		size_type capacity() const {
			return size_type(this->_impl._end_of_storage - this->_impl._start);
		}

		bool empty() const { return begin() == end(); }

		void reserve(size_type num);
		reference operator[](size_type n) { return *(this->_impl._start + n); }
		const_reference operator[](size_type n) const { return *(this->_impl._start + n); }

	protected:
		void _range_check(size_type num) const {
			if (num >= this->size())
				throw("vector::_range_check");
		}

	public:
		reference at(size_type num) {
			_range_check(num);
			return (*this)[num];
		}

		const_reference at(size_type num) const {
			_range_check(num);
			return (*this)[num];
		}

		reference front() { return *begin(); }
		const_reference front() const { return *begin(); }

		reference back() { return *(end() - 1); }
		const_reference back() const { return *(end() - 1); }

		Type *data() { return _data_ptr(this->_impl._start); }
		const Type *data() const { return _data_ptr(this->_impl._start); }

		void push_back(const value_type &x) {
			if (this->_impl._finish != this->_impl._end_of_storage) {
				AllocTraits::construct(this->_impl, this->_impl._finish, x);
				++this->_impl._finish;
			} else
				_realloc_insert(end(), x);
		}

		void pop_back() {
			--this->_impl._finish;
			AllocTraits::destroy(this->_impl, this->_impl._finish);
		}

		iterator insert(iterator position, const value_type &x);
		void insert(iterator position, size_type num, const value_type &x) { _fill_insert(position, num, x); }

		template<typename InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {
			typedef typename ft::is_integer<InputIterator>::type Integral;
			_insert_dispatch(position, first, last, Integral());
		}

		iterator erase(iterator position) { return _erase(position); }
		iterator erase(iterator first, iterator last) { return _erase(first, last); }

		void swap(vector &x) {
			this->_impl._swap_data(x._impl);
			AllocTraits::self_on_swap(_get_type_allocator(), x._get_type_allocator());
		}

		void clear() { _erase_at_end(this->_impl._start); }

	protected:
		template<typename ForwardIterator>
		pointer _allocate_and_copy(size_type num, ForwardIterator first, ForwardIterator last) {
			pointer result = this->_allocate(num);
			try {
				ft::uninitialized_copy_a(first, last, result, _get_type_allocator());
				return result;
			} catch (...) {
				_deallocate(result, num);
				throw;
			}
		}

		template<typename Integer>
		void _initialize_dispatch(Integer num, Integer value, true_type) {
			this->_impl._start = _allocate(self_check_init_len(static_cast<size_type>(num), _get_type_allocator()));
			this->_impl._end_of_storage = this->_impl._start + static_cast<size_type>(num);
			_fill_initialize(static_cast<size_type>(num), value);
		}

		template<typename InputIterator>
		void _initialize_dispatch(InputIterator first, InputIterator last, false_type) {
			_range_initialize(first, last, ft::get_iterator_category(first));
		}

		template<typename InputIterator>
		void _range_initialize(InputIterator first, InputIterator last, ft::input_iterator_tag) {
			try {
				for (; first != last; ++first)
					push_back(*first);
			} catch (...) {
				clear();
				throw;
			}
		}

		template<typename ForwardIterator>
		void _range_initialize(ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag) {
			const size_type num = ft::distance(first, last);
			this->_impl._start = this->_allocate(self_check_init_len(num, _get_type_allocator()));
			this->_impl._end_of_storage = this->_impl._start + num;
			this->_impl._finish = ft::uninitialized_copy_a(first, last, this->_impl._start, _get_type_allocator());
		}

		void _fill_initialize(size_type num, const value_type &value) {
			this->_impl._finish = ft::uninitialized_fill_n_a(
					this->_impl._start, num, value, _get_type_allocator());
		}

		template<typename Integer>
		void _assign_dispatch(Integer num, Integer value, true_type) {
			_fill_assign(num, value);
		}

		template<typename InputIterator>
		void _assign_dispatch(InputIterator first, InputIterator last, false_type) {
			_assign_aux(first, last, ft::get_iterator_category(first));
		}

		template<typename InputIterator>
		void _assign_aux(InputIterator first, InputIterator last, ft::input_iterator_tag);

		template<typename ForwardIterator>
		void _assign_aux(ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag);

		void _fill_assign(size_type num, const value_type &value);

		template<typename Integer>
		void _insert_dispatch(iterator pos, Integer num, Integer value, true_type) {
			_fill_insert(pos, num, value);
		}

		template<typename InputIterator>
		void _insert_dispatch(iterator pos, InputIterator first, InputIterator last, false_type) {
			_range_insert(pos, first, last, ft::get_iterator_category(first));
		}

		template<typename InputIterator>
		void _range_insert(iterator pos, InputIterator first, InputIterator last, ft::input_iterator_tag);

		template<typename ForwardIterator>
		void _range_insert(iterator pos, ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag);

		void _fill_insert(iterator pos, size_type num, const value_type &x);

		void _insert_aux(iterator position, const value_type &x);
		void _realloc_insert(iterator position, const value_type &x);

		size_type _check_len(size_type num, const char *except) const {
			if (max_size() - size() < num)
				throw(except);

			const size_type length = size() + (ft::max)(size(), num);
			return (length < size() || length > max_size()) ? max_size() : length;
		}

		static size_type self_check_init_len(size_type num, const allocator_type &__a) {
			if (num > self_max_size(TemplateAllocType(__a)))
				throw("cannot create ft::vector larger than max_size()");
			return num;
		}

		static size_type self_max_size(const TemplateAllocType &max_size) {
			return AllocTraits::max_size(max_size);
		}

		void _erase_at_end(pointer pos) {
			if (this->_impl._finish - pos) {
				ft::destroy(pos, this->_impl._finish, _get_type_allocator());
				this->_impl._finish = pos;
			}
		}

		iterator _erase(iterator position);
		iterator _erase(iterator first, iterator last);

		template<typename UniversalPointer>
		UniversalPointer *_data_ptr(UniversalPointer *ptr) const { return ptr; }
		template<typename UniversalPointer>
		UniversalPointer *_data_ptr(UniversalPointer *ptr) { return ptr; }

		template<typename _Ptr>
		value_type *_data_ptr(_Ptr ptr) {
			return empty() ? (value_type *)0 : ptr.operator->();
		}

		template<typename _Ptr>
		const value_type *_data_ptr(_Ptr ptr) const {
			return empty() ? (const value_type *)0 : ptr.operator->();
		}
	};

	template<typename Type>
	inline bool operator==(const vector<Type> &x, const vector<Type> &y) {
		return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
	}

	template<typename Type>
	inline bool operator<(const vector<Type> &x, const vector<Type> &y) {
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template<typename Type>
	inline bool operator!=(const vector<Type> &x, const vector<Type> &y) {
		return !(x == y);
	}
	template<typename Type>
	inline bool operator>(const vector<Type> &x, const vector<Type> &y) {
		return y < x;
	}
	template<typename Type>
	inline bool operator<=(const vector<Type> &x, const vector<Type> &y) {
		return !(y < x);
	}
	template<typename Type>
	inline bool operator>=(const vector<Type> &x, const vector<Type> &y) {
		return !(x < y);
	}

	template<typename Type, typename Alloc>
	inline void swap(vector<Type, Alloc> &x, vector<Type, Alloc> &y) {
		x.swap(y);
	}

	template<typename Type, typename Alloc>
	void vector<Type, Alloc>::reserve(size_type num) {
		if (num > this->max_size())
			throw("vector::reserve");

		if (this->capacity() < num) {
			const size_type old_size = size();
			pointer tmp = _allocate_and_copy(num, this->_impl._start, this->_impl._finish);

			ft::destroy(this->_impl._start, this->_impl._finish, _get_type_allocator());

			_deallocate(this->_impl._start, this->_impl._end_of_storage - this->_impl._start);
			this->_impl._start = tmp;
			this->_impl._finish = tmp + old_size;
			this->_impl._end_of_storage = this->_impl._start + num;
		}
	}

	template<typename Type, typename Alloc>
	typename vector<Type, Alloc>::iterator vector<Type, Alloc>::insert(iterator position, const value_type &x) {
		const size_type num = position - begin();
		if (this->_impl._finish != this->_impl._end_of_storage)
			if (position == end()) {
				AllocTraits::construct(this->_impl, this->_impl._finish, x);
				++this->_impl._finish;
			} else {
				_insert_aux(position, x);
			}
		else
			_realloc_insert(position, x);

		return iterator(this->_impl._start + num);
	}

	template<typename Type, typename Alloc>
	typename vector<Type, Alloc>::iterator vector<Type, Alloc>::_erase(iterator position) {
		if (position + 1 != end())
			ft::copy(position + 1, end(), position);
		--this->_impl._finish;
		AllocTraits::destroy(this->_impl, this->_impl._finish);
		return position;
	}

	template<typename Type, typename Alloc>
	typename vector<Type, Alloc>::iterator vector<Type, Alloc>::_erase(iterator first, iterator last) {
		if (first != last) {
			if (last != end())
				ft::copy(last, end(), first);
			_erase_at_end(first.base() + (end() - last));
		}
		return first;
	}

	template<typename Type, typename Alloc>
	vector<Type, Alloc> &vector<Type, Alloc>::operator=(const vector<Type, Alloc> &x) {
		if (&x != this) {
			const size_type xlen = x.size();

			if (xlen > capacity()) {
				pointer tmp = _allocate_and_copy(xlen, x.begin(), x.end());
				ft::destroy(this->_impl._start, this->_impl._finish, _get_type_allocator());
				_deallocate(this->_impl._start, this->_impl._end_of_storage - this->_impl._start);
				this->_impl._start = tmp;
				this->_impl._end_of_storage = this->_impl._start + xlen;
			} else if (size() >= xlen) {
				ft::destroy(ft::copy(x.begin(), x.end(), begin()), end(), _get_type_allocator());
			} else {
				ft::copy(x._impl._start, x._impl._start + size(),
						 this->_impl._start);
				ft::uninitialized_copy_a(x._impl._start + size(), x._impl._finish, this->_impl._finish, _get_type_allocator());
			}

			this->_impl._finish = this->_impl._start + xlen;
		}
		return *this;
	}

	template<typename Type, typename Alloc>
	void vector<Type, Alloc>::_fill_assign(size_t num, const value_type &value) {
		if (num > capacity()) {
			vector tmp(num, value, _get_type_allocator());
			tmp._impl._swap_data(this->_impl);
		} else if (num > size()) {
			ft::fill(begin(), end(), value);
			const size_type add = num - size();
			this->_impl._finish = ft::uninitialized_fill_n_a(this->_impl._finish, add, value, _get_type_allocator());
		} else
			_erase_at_end(ft::fill_n(this->_impl._start, num, value));
	}

	template<typename Type, typename Alloc>
	template<typename InputIterator>
	void vector<Type, Alloc>::_assign_aux(InputIterator first, InputIterator last, ft::input_iterator_tag) {
		pointer __cur(this->_impl._start);
		for (; first != last && __cur != this->_impl._finish; ++__cur, (void)++first)
			*__cur = *first;
		if (first == last)
			_erase_at_end(__cur);
		else
			_range_insert(end(), first, last, ft::get_iterator_category(first));
	}

	template<typename Type, typename Alloc>
	template<typename ForwardIterator>
	void vector<Type, Alloc>::_assign_aux(ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag) {
		const size_type length = ft::distance(first, last);

		if (length > capacity()) {
			pointer tmp(_allocate_and_copy(length, first, last));
			ft::destroy(this->_impl._start, this->_impl._finish,
						_get_type_allocator());
			_deallocate(this->_impl._start, this->_impl._end_of_storage - this->_impl._start);
			this->_impl._start = tmp;
			this->_impl._finish = this->_impl._start + length;
			this->_impl._end_of_storage = this->_impl._finish;
		} else if (size() >= length)
			_erase_at_end(ft::copy(first, last, this->_impl._start));
		else {
			ForwardIterator mid = first;
			ft::advance(mid, size());
			ft::copy(first, mid, this->_impl._start);
			this->_impl._finish = ft::uninitialized_copy_a(mid, last, this->_impl._finish, _get_type_allocator());
		}
	}

	template<typename Type, typename Alloc>
	void vector<Type, Alloc>::_insert_aux(iterator position, const Type &x) {
		AllocTraits::construct(this->_impl, this->_impl._finish, *(this->_impl._finish - 1));
		++this->_impl._finish;
		Type x_copy = x;
		ft::copy_backward(position.base(), this->_impl._finish - 2, this->_impl._finish - 1);
		*position = x_copy;
	}

	template<typename Type, typename Alloc>
	void vector<Type, Alloc>::_realloc_insert(iterator position, const Type &x) {
		const size_type length = _check_len(size_type(1), "vector::_realloc_insert");
		pointer old_start = this->_impl._start;
		pointer old_finish = this->_impl._finish;

		const size_type elements_before = position - begin();
		pointer new_start(this->_allocate(length));
		pointer new_finish(new_start);

		try {
			AllocTraits::construct(this->_impl, new_start + elements_before, x);
			new_finish = pointer();
			new_finish = ft::uninitialized_copy_a(old_start, position.base(), new_start, _get_type_allocator());
			++new_finish;
			new_finish = ft::uninitialized_copy_a(position.base(), old_finish, new_finish, _get_type_allocator());
		} catch (...) {
			if (!new_finish)
				AllocTraits::destroy(this->_impl, new_start + elements_before);
			else
				ft::destroy(new_start, new_finish, _get_type_allocator());
			_deallocate(new_start, length);
			throw;
		}

		ft::destroy(old_start, old_finish, _get_type_allocator());

		_deallocate(old_start, this->_impl._end_of_storage - old_start);

		this->_impl._start = new_start;
		this->_impl._finish = new_finish;
		this->_impl._end_of_storage = new_start + length;
	}

	template<typename Type, typename Alloc>
	void vector<Type, Alloc>::_fill_insert(iterator position, size_type num, const value_type &x) {
		if (num != 0) {
			if (size_type(this->_impl._end_of_storage - this->_impl._finish) >= num) {
				value_type x_copy = x;
				const size_type elements_after = end() - position;
				pointer old_finish(this->_impl._finish);

				if (elements_after > num) {
					ft::uninitialized_copy_a(this->_impl._finish - num, this->_impl._finish, this->_impl._finish, _get_type_allocator());
					this->_impl._finish += num;
					ft::copy_backward(position.base(), old_finish - num, old_finish);
					ft::fill(position.base(), position.base() + num, x_copy);
				} else {
					this->_impl._finish = ft::uninitialized_fill_n_a(this->_impl._finish, num - elements_after, x_copy, _get_type_allocator());
					ft::uninitialized_copy_a(position.base(), old_finish, this->_impl._finish, _get_type_allocator());
					this->_impl._finish += elements_after;
					ft::fill(position.base(), old_finish, x_copy);
				}
			} else {
				const size_type length = _check_len(num, "vector::_fill_insert");
				const size_type elements_before = position - begin();
				pointer new_start(this->_allocate(length));
				pointer new_finish(new_start);
				try {
					ft::uninitialized_fill_n_a(new_start + elements_before, num, x, _get_type_allocator());
					new_finish = pointer();
					new_finish = ft::uninitialized_copy_a(this->_impl._start, position.base(), new_start, _get_type_allocator());
					new_finish += num;
					new_finish = ft::uninitialized_copy_a(position.base(), this->_impl._finish, new_finish, _get_type_allocator());
				} catch (...) {
					if (!new_finish)
						ft::destroy(new_start + elements_before, new_start + elements_before + num, _get_type_allocator());
					else
						ft::destroy(new_start, new_finish, _get_type_allocator());
					_deallocate(new_start, length);
					throw;
				}

				ft::destroy(this->_impl._start, this->_impl._finish, _get_type_allocator());
				_deallocate(this->_impl._start, this->_impl._end_of_storage - this->_impl._start);
				this->_impl._start = new_start;
				this->_impl._finish = new_finish;
				this->_impl._end_of_storage = new_start + length;
			}
		}
	}

	template<typename Type, typename Alloc>
	template<typename InputIterator>
	void vector<Type, Alloc>::_range_insert(iterator pos, InputIterator first, InputIterator last, ft::input_iterator_tag) {
		if (pos == end()) {
			for (; first != last; ++first)
				insert(end(), *first);
		} else if (first != last) {
			vector tmp(first, last, _get_type_allocator());
			insert(pos, tmp.begin(), tmp.end());
		}
	}

	template<typename Type, typename Alloc>
	template<typename ForwardIterator>
	void vector<Type, Alloc>::_range_insert(iterator position, ForwardIterator first, ForwardIterator last, ft::forward_iterator_tag) {
		if (first != last) {
			const size_type dist = ft::distance(first, last);
			if (size_type(this->_impl._end_of_storage - this->_impl._finish) >= dist) {
				const size_type elements_after = end() - position;
				pointer old_finish(this->_impl._finish);

				if (elements_after > dist) {
					ft::uninitialized_copy_a(this->_impl._finish - dist, this->_impl._finish, this->_impl._finish, _get_type_allocator());
					this->_impl._finish += dist;
					ft::copy_backward(position.base(), old_finish - dist, old_finish);
					ft::copy(first, last, position);
				} else {
					ForwardIterator mid = first;
					ft::advance(mid, elements_after);
					ft::uninitialized_copy_a(mid, last, this->_impl._finish, _get_type_allocator());
					this->_impl._finish += dist - elements_after;
					ft::uninitialized_copy_a(position.base(), old_finish, this->_impl._finish, _get_type_allocator());
					this->_impl._finish += elements_after;
					ft::copy(first, mid, position);
				}
			} else {
				const size_type length = _check_len(dist, "vector::_range_insert");
				pointer new_start(this->_allocate(length));
				pointer new_finish(new_start);

				try {
					new_finish = ft::uninitialized_copy_a(this->_impl._start, position.base(), new_start, _get_type_allocator());
					new_finish = ft::uninitialized_copy_a(first, last, new_finish, _get_type_allocator());
					new_finish = ft::uninitialized_copy_a(position.base(), this->_impl._finish, new_finish, _get_type_allocator());
				} catch (...) {
					ft::destroy(new_start, new_finish, _get_type_allocator());
					_deallocate(new_start, length);
					throw;
				}

				ft::destroy(this->_impl._start, this->_impl._finish, _get_type_allocator());
				_deallocate(this->_impl._start, this->_impl._end_of_storage - this->_impl._start);
				this->_impl._start = new_start;
				this->_impl._finish = new_finish;
				this->_impl._end_of_storage = new_start + length;
			}
		}
	}

} // namespace ft

#endif //FT_VECTOR_HPP
