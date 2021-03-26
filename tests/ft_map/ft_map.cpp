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

#include <ft_map.hpp>
#include <map>
#include <tester.h>

void test_construct() {
	ft::map<std::string, int> one;
	ft::map<std::string, int> two;
	two["test"] = 42;
	two["hello"] = 42;
	two["codam"] = 42;
	two["hi"] = 42;
	ft::map<std::string, int> three(two.begin(), two.end());
	ft::map<std::string, int> four(three);
	ft::map<std::string, int> five = four;

	ASSERT_THROW(one.size(), size_t(0));
	ASSERT_THROW(two.size(), size_t(4));
	ASSERT_THROW(three.size(), size_t(4));
	ASSERT_THROW(four.size(), size_t(4));
	ASSERT_THROW(five.size(), size_t(4));
	for (auto & it : two)
		ASSERT_EQUAL(it.second == 42);
}

void test_access() {
	ft::map<int, int> Map;
	for (int i = 0; i < 5; i++) {
		Map[i] = 5;
	}
	Map.at(3) = 99;

	ASSERT_EQUAL(Map.at(0) == 5);
	ASSERT_EQUAL(Map.at(3) == 99);
}

void test_iterators() {
	ft::map<int, int> ftMap;
	std::map<int, int> stdMap;
	for (int i = 0; i < 10; i++) {
		ftMap[i] = i + 90;
		stdMap[i] = i + 90;
	}
	auto ftit = ftMap.begin(), ftite = ftMap.end();
	ft::map<int, int>::const_iterator ftcit(ftit), ftcite(ftite);
	auto ftrit = ftMap.rbegin(), ftrite = ftMap.rend();
	ft::map<int, int>::const_reverse_iterator ftcrit(ftrit), ftcrite(ftrite);

	auto stdit = stdMap.begin(), stdite = stdMap.end();
	std::map<int, int>::const_iterator stdcit(stdit), stdcite(stdite);
	auto stdrit = stdMap.rbegin(), stdrite = stdMap.rend();
	std::map<int, int>::const_reverse_iterator stdcrit(stdrit), stdcrite(stdrite);

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
		ft::map<int, std::string> ftMap;
		std::map<int, std::string> stdMap;

		ASSERT_THROW(ftMap.empty(), stdMap.empty());
		ASSERT_THROW(ftMap.size(), stdMap.size());
		ASSERT_THROW(ftMap.max_size(), stdMap.max_size());

		ftMap[0] = "Hello";
		ftMap[1] = "Codam";
		stdMap[0] = "Hello";
		stdMap[1] = "Codam";

		ASSERT_THROW(ftMap.empty(), stdMap.empty());
		ASSERT_THROW(ftMap.size(), stdMap.size());
		ASSERT_THROW(ftMap.max_size(), stdMap.max_size());
	}
}

void test_modifiers() {
	{
		ft::map<int, int> ftMap;
		ftMap[0] = 100;
		ftMap[1] = 200;
		ftMap[2] = 300;

		ASSERT_THROW(ftMap.size(), size_t(3));
		ftMap.clear();
		ASSERT_THROW(ftMap.size(), size_t(0));
	}
	{
		ft::map<int, int> ftMap;
		ftMap[0] = 22;
		ftMap[1] = 11;

		ftMap.insert(ft::make_pair(5, 99));
		ASSERT_THROW(ftMap.size(), size_t(3));
		ASSERT_EQUAL(ftMap[5] == 99);

		ftMap.erase(ftMap.begin());
		ASSERT_THROW(ftMap.size(), size_t(2));

		ftMap.erase(ftMap.begin(), ftMap.end());
		ASSERT_THROW(ftMap.size(), size_t(0));
	}
	{
		ft::map<int, int> ftMap1;
		ft::map<int, int> ftMap2;
		ftMap1[0] = 12;
		ftMap2[0] = 5;

		ftMap1.swap(ftMap2);
		ASSERT_EQUAL(ftMap1[0] = 5);
		ASSERT_EQUAL(ftMap2[0] = 12);
	}
}

void test_lookup() {
	ft::map<int, int> ftMap;
	for (int i = 0; i < 5; i++) {
		ftMap[i] = 33 + i;
	}

	ASSERT_EQUAL(ftMap.count(2) == 1);
	ASSERT_EQUAL(ftMap.find(2)->second == 35);

	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ftPair = ftMap.equal_range(2);
	ASSERT_EQUAL(ftPair.first->first == ftMap.lower_bound(2)->first);
	ASSERT_EQUAL(ftPair.second->first == ftMap.upper_bound(2)->first);
}

void test_operators() {
	ft::map<int, int> ftMap1;
	ft::map<int, int> ftMap2;

	for (int i = 0; i < 5; i++) {
		ftMap1[i] = 55;
		ftMap2[i] = 55;
	}

	ASSERT_THROW((ftMap1 == ftMap2), true);
	ASSERT_THROW((ftMap1 != ftMap2), false);
	ASSERT_THROW((ftMap1 < ftMap2), false);
	ASSERT_THROW((ftMap1 <= ftMap2), true);
	ASSERT_THROW((ftMap1 > ftMap2), false);
	ASSERT_THROW((ftMap1 >= ftMap2), true);
}

int main() {
	test_construct();
	test_access();
	test_iterators();
	test_capacity();
	test_modifiers();
	test_lookup();
	test_operators();
}
