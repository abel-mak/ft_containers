/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:53:12 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/12 19:13:02 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include "../src/vector.hpp"
#include "./doctest.h"
struct test
{
	int a;
	test(void)
	{
		a = 5;
	}
	test(const test &src)
	{
		a = 7;
	}
};

int compare_a(std::vector<struct test>::iterator first1,
              ft::vector<struct test>::iterator first2, size_t n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (first1->a != first2->a)
			return (0);
		i++;
	}
	return (1);
}
int compare_a(std::vector<int>::iterator first1,
              ft::vector<int>::iterator first2, size_t n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (*first1 != *first2)
			return (0);
		i++;
	}
	return (1);
}

TEST_CASE("ft::vector constructors")
{
	SUBCASE("default constructor")
	{
		std::vector<struct test> std_v;
		ft::vector<struct test> ft_v;
		std::vector<int> std_v1;
		ft::vector<int> ft_v1;

		CHECK(std_v.size() == ft_v.size());
		CHECK(std_v.capacity() == ft_v.capacity());
		CHECK(std_v1.size() == ft_v1.size());
		CHECK(std_v1.capacity() == ft_v1.capacity());
	}
	SUBCASE("fill constructor")
	{
		SUBCASE("without val argument")
		{
			std::vector<struct test> std_v(10);
			ft::vector<struct test> ft_v(10);
			std::vector<int> std_v1(10);
			ft::vector<int> ft_v1(10);

			std::vector<struct test>::iterator std_i = std_v.begin();
			ft::vector<struct test>::iterator ft_i   = ft_v.begin();
			std::vector<int>::iterator std_i1        = std_v1.begin();
			ft::vector<int>::iterator ft_i1          = ft_v1.begin();

			CHECK(std_v.size() == ft_v.size());
			CHECK(std_v.capacity() == ft_v.capacity());
			CHECK(compare_a(std_i, ft_i, std_v.size()));

			CHECK(std_v1.size() == ft_v1.size());
			CHECK(std_v1.capacity() == ft_v1.capacity());
			CHECK(compare_a(std_i1, ft_i1, std_v1.size()));
		}
		SUBCASE("with val argument")
		{
			struct test t1;
			int z = 25;
			std::vector<struct test> std_v(10, t1);
			ft::vector<struct test> ft_v(10, t1);
			std::vector<int> std_v1(10, z);
			ft::vector<int> ft_v1(10, z);

			std::vector<struct test>::iterator std_i = std_v.begin();
			ft::vector<struct test>::iterator ft_i   = ft_v.begin();
			std::vector<int>::iterator std_i1        = std_v1.begin();
			ft::vector<int>::iterator ft_i1          = ft_v1.begin();

			CHECK(std_v.size() == ft_v.size());
			CHECK(std_v.capacity() == ft_v.capacity());
			CHECK(compare_a(std_i, ft_i, std_v.size()));

			CHECK(std_v1.size() == ft_v1.size());
			CHECK(std_v1.capacity() == ft_v1.capacity());
			CHECK(compare_a(std_i1, ft_i1, std_v1.size()));
		}
	}
	SUBCASE("range constructor")
	{
		struct test t1;
		int z             = 25;
		struct test arr[] = {t1, t1, t1};
		int arr_int[]     = {z, z, z};

		std::vector<struct test> std_v(std::begin(arr), std::end(arr));
		ft::vector<struct test> ft_v(std::begin(arr), std::end(arr));
		std::vector<int> std_v1(std::begin(arr_int), std::end(arr_int));
		ft::vector<int> ft_v1(std::begin(arr_int), std::end(arr_int));

		std::vector<struct test>::iterator std_i = std_v.begin();
		ft::vector<struct test>::iterator ft_i   = ft_v.begin();
		std::vector<int>::iterator std_i1        = std_v1.begin();
		ft::vector<int>::iterator ft_i1          = ft_v1.begin();

		CHECK(std_v.size() == ft_v.size());
		CHECK(std_v.capacity() == ft_v.capacity());
		CHECK(compare_a(std_i, ft_i, std_v.size()));

		CHECK(std_v1.size() == ft_v1.size());
		CHECK(std_v1.capacity() == ft_v1.capacity());
		CHECK(compare_a(std_i1, ft_i1, std_v1.size()));
	}
	SUBCASE("begin and end")
	{
		struct test t1;
		struct test arr[] = {t1, t1, t1};

		std::vector<struct test> std_v(std::begin(arr), std::end(arr));
		ft::vector<struct test> ft_v(std::begin(arr), std::end(arr));

		CHECK((std_v.begin() - std_v.end()) == (ft_v.begin() - ft_v.end()));
	}
	SUBCASE("rbegin and rend")
	{
		struct test t1;
		struct test arr[] = {t1, t1, t1};

		std::vector<struct test> std_v(std::begin(arr), std::end(arr));
		ft::vector<struct test> ft_v(std::begin(arr), std::end(arr));

		CHECK((std_v.rbegin() - std_v.rend()) == (ft_v.rbegin() - ft_v.rend()));
		CHECK((std_v.begin().base() - std_v.rbegin().base().base()) ==
		      (ft_v.begin().base() - ft_v.rbegin().base().base()));
	}
}
