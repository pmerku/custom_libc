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

#include <MutantStack.hpp>
#include <tester.h>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>

void list_test() {
	try {
		MutantStack<int, std::list<int> > lstack;
		for (int i = 0; i < 11; ++i) {
			lstack.push(rand() % 100);
		}
		lstack.top();
		lstack.pop();
		lstack.size();
		auto it = lstack.rbegin();
		auto ite = lstack.rend();
		while (it != ite) {
			++it;
		}
		lstack.pop();
	}
	catch (...) {
		throw;
	}
}

void vector_test() {
	try {
		MutantStack<int, std::vector<int> > vstack;
		for (int i = 0; i < 11; ++i) {
			vstack.push(rand() % 100);
		}
		vstack.top();
		vstack.pop();
		vstack.size();
		auto it = vstack.begin();
		auto ite = vstack.end();
		while (it != ite) {
			++it;
		}
		vstack.pop();
	}
	catch (...) {
		throw;
	}
}

void deque_test() {
	try {
		MutantStack<std::string, std::deque<std::string> > dstack;
		for (int i = 0; i < 11; ++i) {
			if (i % 2) {
				dstack.push("hello");
			}
			else if (i % 3) {
				dstack.push("codam");
			}
			else {
				dstack.push("help");
			}
		}
		dstack.top();
		dstack.pop();
		dstack.size();
		auto it = dstack.begin();
		auto ite = dstack.end();
		while (it != ite) {
			++it;
		}
		dstack.pop();
	}
	catch (...) {
		throw;
	}
}

void	ft_test_mstack() {
	srand(time(NULL));
	size_t	i = 0;
	while (i++ < 100) {
		try {
			list_test();
			ft_assert(1);
		}
		catch (...) {
			ft_assert(0);
		}
		try {
			vector_test();
			ft_assert(1);
		}
		catch (...) {
			ft_assert(0);
		}
		try {
			deque_test();
			ft_assert(1);
		}
		catch (...) {
			ft_assert(0);
		}
	}
}
