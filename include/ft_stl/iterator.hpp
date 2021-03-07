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

#ifndef ITERATOR_HPP
#define ITERATOR_HPP 1

#include <cstddef>
#include "move.hpp"
#include "iterator_base_types.hpp"
#include "type_traits.hpp"

namespace ft {

	template<typename Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
		typename iterator_traits<Iterator>::value_type,
		typename iterator_traits<Iterator>::difference_type,
		typename iterator_traits<Iterator>::pointer,
		typename iterator_traits<Iterator>::reference> {

		template<typename Iter>
		friend class reverse_iterator;

	protected:
		Iterator current;
		typedef iterator_traits<Iterator> TraitsType;

	public:
		typedef Iterator iterator_type;
		typedef typename TraitsType::difference_type difference_type;
		typedef typename TraitsType::pointer pointer;
		typedef typename TraitsType::reference reference;

		reverse_iterator() : current() { }
		reverse_iterator(iterator_type x) : current(x) { }
		reverse_iterator(const reverse_iterator &x) : current(x.current) { }
		template<typename Iter>
		reverse_iterator(const reverse_iterator<Iter> &x) : current(x.current) { }

		iterator_type base() const { return current; }

		reference operator*() const {
			Iterator tmp = current;
			return *--tmp;
		}

		pointer operator->() const {
			Iterator tmp = current;
			--tmp;
			return self_to_pointer(tmp);
		}

		reverse_iterator &operator++() {
			--current;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			--current;
			return tmp;
		}

		reverse_iterator &operator--() {
			++current;
			return *this;
		}

		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++current;
			return tmp;
		}

		reverse_iterator operator+(difference_type diff) const { return reverse_iterator(current - diff); }

		reverse_iterator &operator+=(difference_type diff) {
			current -= diff;
			return *this;
		}

		reverse_iterator operator-(difference_type diff) const { return reverse_iterator(current + diff); }

		reverse_iterator &operator-=(difference_type diff) {
			current += diff;
			return *this;
		}

		reference operator[](difference_type diff) const { return *(*this + diff); }

	private:
		template<typename Type>
		static Type *self_to_pointer(Type *ptr) { return ptr; }
		template<typename Type>
		static pointer self_to_pointer(Type iter) { return iter.operator->(); }
	};

	template<typename Iterator>
	inline bool operator==(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.base() == y.base();
	}

	template<typename Iterator>
	inline bool operator<(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return y.base() < x.base();
	}

	template<typename Iterator>
	inline bool operator!=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return !(x == y);
	}

	template<typename Iterator>
	inline bool operator>(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return y < x;
	}

	template<typename Iterator>
	inline bool operator<=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return !(y < x);
	}

	template<typename Iterator>
	inline bool operator>=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return !(x < y);
	}

	template<typename IteratorL, typename IteratorR>
	inline bool operator==(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y) {
		return x.base() == y.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline bool operator<(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y) {
		return x.base() > y.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline bool operator!=(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y) {
		return x.base() != y.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline bool operator>(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y) {
		return x.base() < y.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline bool operator<=(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y) {
		return x.base() >= y.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline bool operator>=(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y) {
		return x.base() <= y.base();
	}

	template<typename Iterator>
	inline typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &x,
			const reverse_iterator<Iterator> &y) {
		return y.base() - x.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL> &x,
			const reverse_iterator<IteratorR> &y) {
		return y.base() - x.base();
	}

	template<typename Iterator>
	inline reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator> &x) {
		return reverse_iterator<Iterator>(x.base() - n);
	}

	template<typename Container>
	class insert_iterator : public iterator<output_iterator_tag, void, void, void, void> {
	protected:
		Container *container;
		typename Container::iterator iter;

	public:
		typedef Container container_type;

		insert_iterator(Container &x, typename Container::iterator i) : container(ft::addressof(x)), iter(i) { }
		insert_iterator &operator=(typename Container::const_reference value) {
			iter = container->insert(iter, value);
			++iter;
			return *this;
		}

		insert_iterator &operator*() { return *this; }
		insert_iterator &operator++() { return *this; }
		insert_iterator &operator++(int) { return *this; }
	};

	template<typename Container, typename Iterator>
	inline insert_iterator<Container> inserter(Container &x, Iterator i) {
		return insert_iterator<Container>(x, typename Container::iterator(i));
	}

} // namespace ft

namespace __ft_base {

	using ft::iterator;
	using ft::iterator_traits;

	template<typename Iterator, typename Container>
	class normal_iterator {
	protected:
		Iterator _current;
		typedef ft::iterator_traits<Iterator> TraitsType;

	public:
		typedef Iterator iterator_type;
		typedef typename TraitsType::iterator_category iterator_category;
		typedef typename TraitsType::value_type value_type;
		typedef typename TraitsType::difference_type difference_type;
		typedef typename TraitsType::reference reference;
		typedef typename TraitsType::pointer pointer;

		normal_iterator() : _current(Iterator()) { }
		explicit normal_iterator(const Iterator &iter) : _current(iter) { }

		template<typename Iter>
		normal_iterator(const normal_iterator<Iter, typename ft::enable_if<(ft::are_same<Iter, typename Container::pointer>::value),
		Container>::type> &iter) : _current(iter.base()) { }

		reference operator*() const { return *_current; }
		pointer operator->() const { return _current; }

		normal_iterator &operator++() {
			++_current;
			return *this;
		}
		normal_iterator operator++(int) { return normal_iterator(_current++); }

		normal_iterator &operator--() {
			--_current;
			return *this;
		}
		normal_iterator operator--(int) { return normal_iterator(_current--); }

		reference operator[](difference_type diff) const { return _current[diff]; }

		normal_iterator &operator+=(difference_type diff) {
			_current += diff;
			return *this;
		}

		normal_iterator operator+(difference_type diff) const { return normal_iterator(_current + diff); }

		normal_iterator &operator-=(difference_type diff) {
			_current -= diff;
			return *this;
		}

		normal_iterator operator-(difference_type diff) const { return normal_iterator(_current - diff); }

		const Iterator &base() const { return _current; }
	};

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool operator==(const normal_iterator<IteratorL, Container> &lhs, const normal_iterator<IteratorR, Container> &rhs) {
		return lhs.base() == rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool operator==(const normal_iterator<Iterator, Container> &lhs, const normal_iterator<Iterator, Container> &rhs) {
		return lhs.base() == rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool operator!=(const normal_iterator<IteratorL, Container> &lhs, const normal_iterator<IteratorR, Container> &rhs) {
		return lhs.base() != rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool operator!=(const normal_iterator<Iterator, Container> &lhs, const normal_iterator<Iterator, Container> &rhs) {
		return lhs.base() != rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool operator<(const normal_iterator<IteratorL, Container> &lhs, const normal_iterator<IteratorR, Container> &rhs) {
		return lhs.base() < rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool operator<(const normal_iterator<Iterator, Container> &lhs, const normal_iterator<Iterator, Container> &rhs) {
		return lhs.base() < rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool operator>(const normal_iterator<IteratorL, Container> &lhs, const normal_iterator<IteratorR, Container> &rhs) {
		return lhs.base() > rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool operator>(const normal_iterator<Iterator, Container> &lhs, const normal_iterator<Iterator, Container> &rhs) {
		return lhs.base() > rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool operator<=(const normal_iterator<IteratorL, Container> &lhs, const normal_iterator<IteratorR, Container> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool operator<=(const normal_iterator<Iterator, Container> &lhs, const normal_iterator<Iterator, Container> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool operator>=(const normal_iterator<IteratorL, Container> &lhs, const normal_iterator<IteratorR, Container> &rhs) {
		return lhs.base() >= rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool operator>=(const normal_iterator<Iterator, Container> &lhs, const normal_iterator<Iterator, Container> &rhs) {
		return lhs.base() >= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline typename normal_iterator<IteratorL, Container>::difference_type
	operator-(const normal_iterator<IteratorL, Container> &lhs, const normal_iterator<IteratorR, Container> &rhs) {
		return lhs.base() - rhs.base();
	}

	template<typename Iterator, typename Container>
	inline typename normal_iterator<Iterator, Container>::difference_type
	operator-(const normal_iterator<Iterator, Container> &lhs, const normal_iterator<Iterator, Container> &rhs) {
		return lhs.base() - rhs.base();
	}

	template<typename Iterator, typename Container>
	inline normal_iterator<Iterator, Container>
	operator+(typename normal_iterator<Iterator, Container>::difference_type n, const normal_iterator<Iterator, Container> &i) {
		return normal_iterator<Iterator, Container>(i.base() + n);
	}

} // namespace __ft_base

#endif