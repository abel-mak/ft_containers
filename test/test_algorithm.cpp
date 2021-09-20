/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algorithm.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:25:01 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/20 17:20:10 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/algorithm.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest/doctest.h"

template <typename T1, typename T2>
bool comp(T1 a, T2 b)
{
	if (a < b)
		return (true);
	return (false);
}

TEST_CASE("testing ft::lexicographical_compare")
{
	std::string s1, s2;
	bool a, b;

	s1 = "abcde";
	s2 = "abcdef";
	a  = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
                                     s2.end());
	b = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
	CHECK(a == b);

	s1 = "abcdef";
	s2 = "abcde";
	a  = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
                                     s2.end());
	b = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
	CHECK(a == b);

	s1 = "abcde";
	s2 = "abcde";
	a  = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
                                     s2.end());
	b = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
	CHECK(a == b);

	s1 = "";
	s2 = "";
	a  = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(),
                                     s2.end());
	b = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
	CHECK(a == b);
}

TEST_CASE("testing ft::equal")
{
	std::string s1, s2;
	bool a, b;

	s1 = "abcde";
	s2 = "abcde";
	a  = std::equal(s1.begin(), s1.end(), s2.begin());
	b  = ft::equal(s1.begin(), s1.end(), s2.begin());
	CHECK(a == b);

	s1 = "abcdef";
	s2 = "abcde";
	a  = std::equal(s1.begin(), s1.end(), s2.begin());
	b  = ft::equal(s1.begin(), s1.end(), s2.begin());
	CHECK(a == b);

	s1 = "abcde";
	s2 = "abcdef";
	a  = std::equal(s1.begin(), s1.end(), s2.begin());
	b  = ft::equal(s1.begin(), s1.end(), s2.begin());
	CHECK(a == b);

	s1 = "abcdei";
	s2 = "abcdef";
	a  = std::equal(s1.begin(), s1.end(), s2.begin());
	b  = ft::equal(s1.begin(), s1.end(), s2.begin());
	CHECK(a == b);

	s1 = "abcdef";
	s2 = "abcdei";
	a  = std::equal(s1.begin(), s1.end(), s2.begin());
	b  = ft::equal(s1.begin(), s1.end(), s2.begin());
	CHECK(a == b);

	s1 = "";
	s2 = "";
	a  = std::equal(s1.begin(), s1.end(), s2.begin());
	b  = ft::equal(s1.begin(), s1.end(), s2.begin());
	CHECK(a == b);
}

