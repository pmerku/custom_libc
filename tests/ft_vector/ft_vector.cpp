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

#include <ft_vector.hpp>
#include <vector>
#include <tester.h>

void test_construct() {
	ft::vector<int> one;
	ft::vector<int> two(4, 42);
	ft::vector<int> three(two.begin(), two.end());
	ft::vector<int> four(three);
	ft::vector<int> five = four;
	ft::vector<int> six(4);

	ASSERT_THROW(one.size(), size_t(0));
	one.assign(4, 42);
	ASSERT_THROW(one.size(), size_t(4));
	ASSERT_THROW(two.size(), size_t(4));
	ASSERT_THROW(three.size(), size_t(4));
	ASSERT_THROW(four.size(), size_t(4));
	ASSERT_THROW(five.size(), size_t(4));
	ASSERT_THROW(six.size(), size_t(4));
	for (auto & it : two)
		ASSERT_EQUAL(it == 42);
}

void test_access() {
	ft::vector<int> Vector;
	Vector.push_back(10);
	Vector.push_back(12);
	Vector.push_back(15);

	ASSERT_EQUAL(Vector.front() == 10);
	ASSERT_EQUAL(Vector.back() == 15);
	ASSERT_EQUAL(Vector.at(0) == 10);
	ASSERT_EQUAL(Vector[0] == 10);
}

void test_iterators() {
	ft::vector<int> ftVector;
	std::vector<int> stdVector;
	for (int i = 0; i < 10; i++) {
		ftVector.push_back(i);
		stdVector.push_back(i);
	}
	auto ftit = ftVector.begin(), ftite = ftVector.end();
	ft::vector<int>::const_iterator ftcit(ftit), ftcite(ftite);
	auto ftrit = ftVector.rbegin(), ftrite = ftVector.rend();
	ft::vector<int>::const_reverse_iterator ftcrit(ftrit), ftcrite(ftrite);

	auto stdit = stdVector.begin(), stdite = stdVector.end();
	std::vector<int>::const_iterator stdcit(stdit), stdcite(stdite);
	auto stdrit = stdVector.rbegin(), stdrite = stdVector.rend();
	std::vector<int>::const_reverse_iterator stdcrit(stdrit), stdcrite(stdrite);

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
	{
		ft::vector<int> ftVector;
		std::vector<int> stdVector;

		ASSERT_THROW(ftVector.empty(), stdVector.empty());
		ASSERT_THROW(ftVector.size(), stdVector.size());
		ASSERT_THROW(ftVector.max_size(), stdVector.max_size());

		ftVector.push_back(10);
		ftVector.push_back(12);
		stdVector.push_back(10);
		stdVector.push_back(12);

		ASSERT_THROW(ftVector.empty(), stdVector.empty());
		ASSERT_THROW(ftVector.size(), stdVector.size());
		ASSERT_THROW(ftVector.max_size(), stdVector.max_size());
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stdVector;

		ASSERT_THROW(ftVector.capacity(), stdVector.capacity());
		ftVector.reserve(10);
		ftVector.push_back(1);
		stdVector.reserve(10);
		stdVector.push_back(1);
		ASSERT_THROW(ftVector.capacity(), stdVector.capacity());
	}
}

void test_modifiers() {
	{
		ft::vector<int> ftVector;
		ftVector.push_back(100);
		ftVector.push_back(200);
		ftVector.push_back(300);

		ASSERT_THROW(ftVector.size(), size_t(3));
		ftVector.clear();
		ASSERT_THROW(ftVector.size(), size_t(0));
	}
	{
		ft::vector<int> ftVector;
		for (int i = 0; i < 5; i++)
			ftVector.push_back(0);

		ftVector.insert(ftVector.begin(), 42);
		ASSERT_EQUAL(ftVector.front() == 42);

		ftVector.insert(ftVector.end(), 1, 42);
		ASSERT_EQUAL(ftVector.back() == 42);

		ft::vector<int> insert(5, 0);
		ftVector.clear();
		ftVector.insert(ftVector.begin(), insert.begin(), insert.end());
		for (int & it : ftVector)
			ASSERT_EQUAL(it == 0);
		ASSERT_THROW(ftVector.size(), size_t(5));

		ftVector.erase(ftVector.begin());
		ASSERT_THROW(ftVector.size(), size_t(4));

		ftVector.erase(ftVector.begin(), ftVector.end());
		ASSERT_THROW(ftVector.size(), size_t(0));
	}
	{
		ft::vector<std::string> ftVector;
		ftVector.push_back("hello");
		ASSERT_THROW(ftVector.size(), size_t(1));
		ASSERT_EQUAL(ftVector.back() == "hello");
	}
	{
		ft::vector<int> ftVector;
		ASSERT_THROW(ftVector.size(), size_t(0));
		ftVector.resize(10, 0);
		ASSERT_THROW(ftVector.size(), size_t(10));
	}
	{
		ft::vector<int> ftVector1;
		ftVector1.push_back(1);
		ft::vector<int> ftVector2;
		ftVector2.push_back(10);
		ASSERT_EQUAL(ftVector1.back() == 1);
		ASSERT_EQUAL(ftVector2.back() == 10);

		ftVector1.swap(ftVector2);
		ASSERT_EQUAL(ftVector1.back() == 10);
		ASSERT_EQUAL(ftVector2.back() == 1);
	}
}

void test_operators() {
	ft::vector<int> ftVector1(5, 10);
	ft::vector<int> ftVector2(5, 10);

	ASSERT_THROW((ftVector1 == ftVector2), true);
	ASSERT_THROW((ftVector1 != ftVector2), false);
	ASSERT_THROW((ftVector1 < ftVector2), false);
	ASSERT_THROW((ftVector1 <= ftVector2), true);
	ASSERT_THROW((ftVector1 > ftVector2), false);
	ASSERT_THROW((ftVector1 >= ftVector2), true);
}

int main() {
	test_construct();
	test_access();
	test_iterators();
	test_capacity();
	test_modifiers();
	test_operators();
}
