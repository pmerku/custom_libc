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

#include "ft_multiset.hpp"
#include <set>
#include "tester.h"

void test_construct() {
	ft::multiset<int> one;
	ft::multiset<int> two;
	two.insert(2);
	two.insert(15);
	two.insert(26);
	two.insert(42);
	ft::multiset<int> three(two.begin(), two.end());
	ft::multiset<int> four(three);
	ft::multiset<int> five = four;

	ASSERT_THROW(one.size(), size_t(0));
	ASSERT_THROW(two.size(), size_t(4));
	ASSERT_THROW(three.size(), size_t(4));
	ASSERT_THROW(four.size(), size_t(4));
	ASSERT_THROW(five.size(), size_t(4));
}

void test_iterators() {
	ft::multiset<int> ftSet;
	std::multiset<int> stdSet;
	for (int i = 0; i < 10; i++) {
		ftSet.insert(i);
		stdSet.insert(i);
	}
	auto ftit = ftSet.begin(), ftite = ftSet.end();
	ft::multiset<int>::const_iterator ftcit(ftit), ftcite(ftite);
	auto ftrit = ftSet.rbegin(), ftrite = ftSet.rend();
	ft::multiset<int>::const_reverse_iterator ftcrit(ftrit), ftcrite(ftrite);

	auto stdit = stdSet.begin(), stdite = stdSet.end();
	std::multiset<int>::const_iterator stdcit(stdit), stdcite(stdite);
	auto stdrit = stdSet.rbegin(), stdrite = stdSet.rend();
	std::multiset<int>::const_reverse_iterator stdcrit(stdrit), stdcrite(stdrite);

	ASSERT_THROW((ftite == ftite), (stdite == stdite));
	ASSERT_THROW((ftite == ftcit), (stdite == stdcit));
	ASSERT_THROW((ftite == ftcite), (stdite == stdcite));
	ASSERT_THROW((ftcite == ftcit), (stdcite == stdcit));
	ASSERT_THROW((ftcite == ftite), (stdcite == stdite));

	ASSERT_THROW((ftite != ftite), (stdite != stdite));
	ASSERT_THROW((ftite != ftcit), (stdite != stdcit));
	ASSERT_THROW((ftite != ftcite), (stdite != stdcite));
	ASSERT_THROW((ftcite != ftcit), (stdcite != stdcit));
	ASSERT_THROW((ftcite != ftite), (stdcite != stdite));

	ASSERT_THROW((ftrit == ftrite), (stdrit == stdrite));
	ASSERT_THROW((ftrit == ftcrit), (stdrit == stdcrit));
	ASSERT_THROW((ftrit == ftcrite), (stdrit == stdcrite));
	ASSERT_THROW((ftcrite == ftcrit), (stdcrite == stdcrit));
	ASSERT_THROW((ftcrite == ftrite), (stdcrite == stdrite));

	ASSERT_THROW((ftrit != ftrite), (stdrit != stdrite));
	ASSERT_THROW((ftrit != ftcrit), (stdrit != stdcrit));
	ASSERT_THROW((ftrit != ftcrite), (stdrit != stdcrite));
	ASSERT_THROW((ftcrite != ftcrit), (stdcrite != stdcrit));
	ASSERT_THROW((ftcrite != ftrite), (stdcrite != stdrite));
}

void test_capacity() {
	ft::multiset<int> ftSet;
	std::multiset<int> stdSet;

	ASSERT_THROW(ftSet.empty(), stdSet.empty());
	ASSERT_THROW(ftSet.size(), stdSet.size());
	ASSERT_THROW(ftSet.max_size(), stdSet.max_size());

	ftSet.insert(10);
	ftSet.insert(12);
	stdSet.insert(10);
	stdSet.insert(12);

	ASSERT_THROW(ftSet.empty(), stdSet.empty());
	ASSERT_THROW(ftSet.size(), stdSet.size());
	ASSERT_THROW(ftSet.max_size(), stdSet.max_size());
}

void test_modifiers() {
	{
		ft::multiset<int> ftSet;
		ftSet.insert(100);
		ftSet.insert(200);
		ftSet.insert(300);

		ASSERT_THROW(ftSet.size(), size_t(3));
		ftSet.clear();
		ASSERT_THROW(ftSet.size(), size_t(0));
	}
	{
		ft::multiset<int> ftSet;
		for (int i = 0; i < 5; i++)
			ftSet.insert(5);

		ftSet.insert(ftSet.begin(), 42);
		auto it = ftSet.find(42);
		ASSERT_EQUAL(*it == 42);

		ftSet.erase(ftSet.begin());
		ASSERT_THROW(ftSet.size(), size_t(5));

		ftSet.erase(ftSet.begin(), ftSet.end());
		ASSERT_THROW(ftSet.size(), size_t(0));
	}
	{
		ft::multiset<int> ftSet1;
		ftSet1.insert(1);
		ft::multiset<int> ftSet2;
		ftSet2.insert(10);

		ftSet1.swap(ftSet2);
		ASSERT_EQUAL(*ftSet1.begin() == 10);
		ASSERT_EQUAL(*ftSet2.begin() == 1);
	}
}

void test_lookup() {
	ft::multiset<int> ftSet;
	for (int i = 0; i < 5; i++) {
		ftSet.insert(33 + i);
	}

	ASSERT_EQUAL(ftSet.count(35) == 1);
	ASSERT_EQUAL(*ftSet.find(35) == 35);

	ft::pair<ft::multiset<int>::iterator, ft::multiset<int>::iterator> ftPair = ftSet.equal_range(35);
	ASSERT_EQUAL(*ftPair.first == *ftSet.lower_bound(35));
	ASSERT_EQUAL(*ftPair.second == *ftSet.upper_bound(35));
}

void test_operators() {
	ft::multiset<int> ftSet1;
	ft::multiset<int> ftSet2;

	ASSERT_THROW((ftSet1 == ftSet2), true);
	ASSERT_THROW((ftSet1 != ftSet2), false);
	ASSERT_THROW((ftSet1 < ftSet2), false);
	ASSERT_THROW((ftSet1 <= ftSet2), true);
	ASSERT_THROW((ftSet1 > ftSet2), false);
	ASSERT_THROW((ftSet1 >= ftSet2), true);
}

int main() {
	test_construct();
	test_iterators();
	test_capacity();
	test_modifiers();
	test_lookup();
	test_operators();
}
