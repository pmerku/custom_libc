/* ************************************************************************** */
/*                                                                            */
/*   Project: cpp                                         ::::::::            */
/*   Members: prmerku                                   :+:    :+:            */
/*   Copyright: 2020                                   +:+                    */
/*                                                    +#+                     */
/*                                                   +#+                      */
/*                                                  #+#    #+#                */
/*   while (!(succeed = try()));                   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {

public:
	MutantStack() {}
	~MutantStack() {}
	MutantStack(MutantStack<T, Container> const &obj) : std::stack<T, Container>(obj) {}
	MutantStack<T, Container> &operator=(MutantStack<T, Container> const &obj) {
		if (this == &obj) {
			return *this;
		}
		std::stack<T, Container>::operator=(obj);
		return *this;
	}

	// Definitions of iterators
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

	// Iterator implementation
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
	reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator rend() {
		return this->c.rend();
	}

	// Const Iterators implementation
	const_iterator begin() const {
		return this->c.begin();
	}
	const_iterator end() const {
		return this->c.end();
	}
	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}
	const_reverse_iterator rend() const {
		return this->c.rend();
	}

private:

};


#endif //MUTANTSTACK_HPP
