/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:53:12 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/24 18:23:59 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include "../src/vector.hpp"
struct test
{
	int a;
	test(void)
	{
		a = 5;
	}
	test(const test &src)
	{
		((void)src);
		a = 7;
	}
};

int compare_a(std::vector<struct test>::iterator first1,
              ft::vector<struct test>::iterator first2, size_t n)
{
	size_t i;

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
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*first1 != *first2)
			return (0);
		i++;
	}
	return (1);
}

void test_vector_constructor(void)
{
	//("default constructor")
	{
		std::vector<struct test> std_v;
		ft::vector<struct test> ft_v;
		std::vector<int> std_v1;
		ft::vector<int> ft_v1;

		assert(std_v.size() == ft_v.size());
		assert(std_v.capacity() == ft_v.capacity());
		assert(std_v1.size() == ft_v1.size());
		assert(std_v1.capacity() == ft_v1.capacity());
	}
	{  //("without val argument")
		{
			std::vector<struct test> std_v(10);
			ft::vector<struct test> ft_v(10);
			std::vector<int> std_v1(10);
			ft::vector<int> ft_v1(10);

			std::vector<struct test>::iterator std_i = std_v.begin();
			ft::vector<struct test>::iterator ft_i   = ft_v.begin();
			std::vector<int>::iterator std_i1        = std_v1.begin();
			ft::vector<int>::iterator ft_i1          = ft_v1.begin();

			assert(std_v.size() == ft_v.size());
			assert(std_v.capacity() == ft_v.capacity());
			assert(compare_a(std_i, ft_i, std_v.size()));

			assert(std_v1.size() == ft_v1.size());
			assert(std_v1.capacity() == ft_v1.capacity());
			assert(compare_a(std_i1, ft_i1, std_v1.size()));
			//("with val argument")
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

				assert(std_v.size() == ft_v.size());
				assert(std_v.capacity() == ft_v.capacity());
				assert(compare_a(std_i, ft_i, std_v.size()));

				assert(std_v1.size() == ft_v1.size());
				assert(std_v1.capacity() == ft_v1.capacity());
				assert(compare_a(std_i1, ft_i1, std_v1.size()));
			}
		}
		//("range constructor")
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

			assert(std_v.size() == ft_v.size());
			assert(std_v.capacity() == ft_v.capacity());
			assert(compare_a(std_i, ft_i, std_v.size()));

			assert(std_v1.size() == ft_v1.size());
			assert(std_v1.capacity() == ft_v1.capacity());
			assert(compare_a(std_i1, ft_i1, std_v1.size()));
		}
		//("begin and end")
		{
			struct test t1;
			struct test arr[] = {t1, t1, t1};

			std::vector<struct test> std_v(std::begin(arr), std::end(arr));
			ft::vector<struct test> ft_v(std::begin(arr), std::end(arr));

			assert((std_v.begin() - std_v.end()) ==
			       (ft_v.begin() - ft_v.end()));
		}
		//("rbegin and rend")
		{
			struct test t1;
			struct test arr[] = {t1, t1, t1};

			std::vector<struct test> std_v(std::begin(arr), std::end(arr));
			ft::vector<struct test> ft_v(std::begin(arr), std::end(arr));

			assert((std_v.rbegin() - std_v.rend()) ==
			       (ft_v.rbegin() - ft_v.rend()));
			assert((std_v.begin().base() - std_v.rbegin().base().base()) ==
			       (ft_v.begin().base() - ft_v.rbegin().base().base()));
		}
	}
	std::cout << " test_vector_container [OK] " << std::endl;
}
