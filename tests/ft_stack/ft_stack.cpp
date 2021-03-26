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

#include <ft_stack.hpp>
#include <stack>
#include <tester.h>

void test_construct() {
	ft::stack<int> one;
	ft::stack<int> stack;
	stack.push(42);
	stack.push(42);
	stack.push(42);
	stack.push(42);
	ft::stack<int> two(stack);
	ft::stack<int> three = two;

	ASSERT_THROW(one.size(), size_t(0));
	ASSERT_THROW(two.size(), size_t(4));
	ASSERT_THROW(three.size(), size_t(4));
}

void test_access() {
	ft::stack<int> ftStack;
	for (int i = 0; i < 5; i++) {
		ftStack.push(i);
	}

	ASSERT_EQUAL(ftStack.top() == 4);
}

void test_capacity() {
	{
		ft::stack<int> ftStack;
		std::stack<int> stdStack;

		ftStack.push(22);
		stdStack.push(22);

		ASSERT_THROW(ftStack.empty(), stdStack.empty());
		ASSERT_THROW(ftStack.size(), stdStack.size());

		ftStack.pop();
		stdStack.pop();

		ASSERT_THROW(ftStack.empty(), stdStack.empty());
		ASSERT_THROW(ftStack.size(), stdStack.size());
	}
}

void test_operators() {
	ft::stack<int> ftStack1;
	ft::stack<int> ftStack2;

	for (int i = 0; i < 5; i++) {
		ftStack1.push(55);
		ftStack2.push(55);
	}

	ASSERT_THROW((ftStack1 == ftStack2), true);
	ASSERT_THROW((ftStack1 != ftStack2), false);
	ASSERT_THROW((ftStack1 < ftStack2), false);
	ASSERT_THROW((ftStack1 <= ftStack2), true);
	ASSERT_THROW((ftStack1 > ftStack2), false);
	ASSERT_THROW((ftStack1 >= ftStack2), true);
}

int main() {
	test_construct();
	test_access();
	test_capacity();
	test_operators();
}
