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

#include <ft_list.hpp>
#include <list>
#include <tester.h>

void test_construct() {
	ft::list<int> one;
	ft::list<int> two(4, 42);
	ft::list<int> three(two.begin(), two.end());
	ft::list<int> four(three);
	ft::list<int> five = four;

	ASSERT_THROW(one.size(), size_t(0));
	ASSERT_THROW(two.size(), size_t(4));
	ASSERT_THROW(three.size(), size_t(4));
	ASSERT_THROW(four.size(), size_t(4));
	ASSERT_THROW(five.size(), size_t(4));
	for (int & it : two)
		ASSERT_EQUAL(it == 42);
}

void test_access() {
	ft::list<int> list;
	list.push_back(10);
	list.push_back(12);
	list.push_back(15);

	ASSERT_EQUAL(list.front() == 10);
	ASSERT_EQUAL(list.back() == 15);
}

void test_iterators() {
	ft::list<int> ftList;
	std::list<int> stdList;
	for (int i = 0; i < 10; i++) {
		ftList.push_back(i);
		stdList.push_back(i);
	}
	auto ftit = ftList.begin(), ftite = ftList.end();
	ft::list<int>::const_iterator ftcit(ftit), ftcite(ftite);
	auto ftrit = ftList.rbegin(), ftrite = ftList.rend();
	ft::list<int>::const_reverse_iterator ftcrit(ftrit), ftcrite(ftrite);

	auto stdit = stdList.begin(), stdite = stdList.end();
	std::list<int>::const_iterator stdcit(stdit), stdcite(stdite);
	auto stdrit = stdList.rbegin(), stdrite = stdList.rend();
	std::list<int>::const_reverse_iterator stdcrit(stdrit), stdcrite(stdrite);

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
	ft::list<int> ftList;
	std::list<int> stdList;

	ASSERT_THROW(ftList.empty(), stdList.empty());
	ASSERT_THROW(ftList.size(), stdList.size());
	ASSERT_THROW(ftList.max_size(), stdList.max_size());

	ftList.push_back(10);
	ftList.push_back(12);
	stdList.push_back(10);
	stdList.push_back(12);

	ASSERT_THROW(ftList.empty(), stdList.empty());
	ASSERT_THROW(ftList.size(), stdList.size());
	ASSERT_THROW(ftList.max_size(), stdList.max_size());
}

void test_modifiers() {
	{
		ft::list<int> ftList;
		ftList.push_back(100);
		ftList.push_back(200);
		ftList.push_back(300);

		ASSERT_THROW(ftList.size(), size_t(3));
		ftList.clear();
		ASSERT_THROW(ftList.size(), size_t(0));
	}
	{
		ft::list<int> ftList;
		for (int i = 0; i < 5; i++)
			ftList.push_back(0);

		ftList.insert(ftList.begin(), 42);
		ASSERT_EQUAL(ftList.front() == 42);

		ftList.insert(ftList.end(), 1, 42);
		ASSERT_EQUAL(ftList.back() == 42);

		ft::list<int> insert(5, 0);
		ftList.clear();
		ftList.insert(ftList.begin(), insert.begin(), insert.end());
		for (int & it : ftList)
			ASSERT_EQUAL(it == 0);
		ASSERT_THROW(ftList.size(), size_t(5));

		ftList.erase(ftList.begin());
		ASSERT_THROW(ftList.size(), size_t(4));

		ftList.erase(ftList.begin(), ftList.end());
		ASSERT_THROW(ftList.size(), size_t(0));
	}
	{
		ft::list<std::string> ftList;
		ftList.push_back("hello");
		ASSERT_THROW(ftList.size(), size_t(1));
		ASSERT_EQUAL(ftList.back() == "hello");

		ftList.push_front("test");
		ASSERT_THROW(ftList.size(), size_t(2));
		ASSERT_EQUAL(ftList.front() == "test");

		ftList.push_back("hi");
		ftList.push_front("hi");
		ftList.pop_back();
		ASSERT_THROW(ftList.size(), size_t(3));
		ASSERT_EQUAL(ftList.back() == "hello");

		ftList.pop_front();
		ASSERT_THROW(ftList.size(), size_t(2));
		ASSERT_EQUAL(ftList.front() == "test");
	}
	{
		ft::list<int> ftList;
		ASSERT_THROW(ftList.size(), size_t(0));
		ftList.resize(10, 0);
		ASSERT_THROW(ftList.size(), size_t(10));
	}
	{
		ft::list<int> ftList1;
		ftList1.push_back(1);
		ft::list<int> ftList2;
		ftList2.push_back(10);
		ASSERT_EQUAL(ftList1.back() == 1);
		ASSERT_EQUAL(ftList2.back() == 10);

		ftList1.swap(ftList2);
		ASSERT_EQUAL(ftList1.back() == 10);
		ASSERT_EQUAL(ftList2.back() == 1);
	}
}

bool cmp(const int& a, const int&b) {
	return (a < b);
}

bool predicate(int x) {
	return (x % 2) == 0;
}

void test_operations() {
	{
		ft::list<int> ftList1(5, 5);
		ft::list<int> ftList2(5, 10);
		ft::list<int> ftList3(5, 42);

		ASSERT_THROW(ftList1.size(), size_t(5));
		ASSERT_EQUAL(ftList1.back() == 5);
		ftList1.merge(ftList2);
		ASSERT_THROW(ftList1.size(), size_t(10));
		ASSERT_EQUAL(ftList1.back() == 10);
		ftList1.merge(ftList3, cmp);
		ASSERT_THROW(ftList1.size(), size_t(15));
		ASSERT_EQUAL(ftList1.back() == 42);
	}
}

void test_operators() {
	ft::list<int> ftList1(5, 10);
	ft::list<int> ftList2(5, 10);

	ASSERT_THROW((ftList1 == ftList2), true);
	ASSERT_THROW((ftList1 != ftList2), false);
	ASSERT_THROW((ftList1 < ftList2), false);
	ASSERT_THROW((ftList1 <= ftList2), true);
	ASSERT_THROW((ftList1 > ftList2), false);
	ASSERT_THROW((ftList1 >= ftList2), true);
}

int main() {
	test_construct();
	test_access();
	test_iterators();
	test_capacity();
	test_modifiers();
	test_operations();
	test_operators();
}