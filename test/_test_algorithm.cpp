/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algorithm.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:25:01 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/22 11:32:24 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "../src/algorithm.hpp"

template <typename T1, typename T2>
bool comp(T1 a, T2 b)
{
	if (a < b)
		return (true);
	return (false);
}

void test_algorithm()
{
	{
		std::string s1, s2;
		bool a, b;

		s1 = "abcde";
		s2 = "abcdef";
		a  = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
		                                  s2.end());
		b  = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
		                                 s2.end());
		assert(a == b);

		s1 = "abcdef";
		s2 = "abcde";
		a  = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
		                                  s2.end());
		b  = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
		                                 s2.end());
		assert(a == b);

		s1 = "abcde";
		s2 = "abcde";
		a  = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
		                                  s2.end());
		b  = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
		                                 s2.end());
		assert(a == b);

		s1 = "";
		s2 = "";
		a  = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
		                                  s2.end());
		b  = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
		                                 s2.end());
		assert(a == b);
	}

	{
		std::string s1, s2;
		bool a, b;

		s1 = "abcde";
		s2 = "abcde";
		a  = std::equal(s1.begin(), s1.end(), s2.begin());
		b  = ft::equal(s1.begin(), s1.end(), s2.begin());
		assert(a == b);

		s1 = "abcdef";
		s2 = "abcde";
		a  = std::equal(s1.begin(), s1.end(), s2.begin());
		b  = ft::equal(s1.begin(), s1.end(), s2.begin());
		assert(a == b);

		s1 = "abcde";
		s2 = "abcdef";
		a  = std::equal(s1.begin(), s1.end(), s2.begin());
		b  = ft::equal(s1.begin(), s1.end(), s2.begin());
		assert(a == b);

		s1 = "abcdei";
		s2 = "abcdef";
		a  = std::equal(s1.begin(), s1.end(), s2.begin());
		b  = ft::equal(s1.begin(), s1.end(), s2.begin());
		assert(a == b);

		s1 = "abcdef";
		s2 = "abcdei";
		a  = std::equal(s1.begin(), s1.end(), s2.begin());
		b  = ft::equal(s1.begin(), s1.end(), s2.begin());
		assert(a == b);

		s1 = "";
		s2 = "";
		a  = std::equal(s1.begin(), s1.end(), s2.begin());
		b  = ft::equal(s1.begin(), s1.end(), s2.begin());
		assert(a == b);
	}
	std::cout << " algorithm [OK]" << std::endl;
}
