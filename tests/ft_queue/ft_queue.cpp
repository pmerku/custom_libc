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

#include <ft_queue.hpp>
#include <queue>
#include <tester.h>

void test_construct() {
	ft::queue<int> one;
	ft::queue<int> Queue;
	Queue.push(42);
	Queue.push(42);
	Queue.push(42);
	Queue.push(42);
	ft::queue<int> two(Queue);
	ft::queue<int> three = two;

	ASSERT_THROW(one.size(), size_t(0));
	ASSERT_THROW(two.size(), size_t(4));
	ASSERT_THROW(three.size(), size_t(4));
}

void test_access() {
	ft::queue<int> ftQueue;
	for (int i = 0; i < 5; i++) {
		ftQueue.push(i);
	}

	ASSERT_EQUAL(ftQueue.front() == 0);
	ASSERT_EQUAL(ftQueue.back() == 4);

	ftQueue.pop();
	ASSERT_EQUAL(ftQueue.front() == 1);
}

void test_capacity() {
	{
		ft::queue<int> ftQueue;
		std::queue<int> stdQueue;

		ftQueue.push(22);
		stdQueue.push(22);

		ASSERT_THROW(ftQueue.empty(), stdQueue.empty());
		ASSERT_THROW(ftQueue.size(), stdQueue.size());

		ftQueue.pop();
		stdQueue.pop();

		ASSERT_THROW(ftQueue.empty(), stdQueue.empty());
		ASSERT_THROW(ftQueue.size(), stdQueue.size());
	}
}

void test_operators() {
	ft::queue<int> ftQueue1;
	ft::queue<int> ftQueue2;

	for (int i = 0; i < 5; i++) {
		ftQueue1.push(55);
		ftQueue2.push(55);
	}

	ASSERT_THROW((ftQueue1 == ftQueue2), true);
	ASSERT_THROW((ftQueue1 != ftQueue2), false);
	ASSERT_THROW((ftQueue1 < ftQueue2), false);
	ASSERT_THROW((ftQueue1 <= ftQueue2), true);
	ASSERT_THROW((ftQueue1 > ftQueue2), false);
	ASSERT_THROW((ftQueue1 >= ftQueue2), true);
}

int main() {
	test_construct();
	test_access();
	test_capacity();
	test_operators();
}
