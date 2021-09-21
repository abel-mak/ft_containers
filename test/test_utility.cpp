/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utility.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:36:53 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/21 17:20:51 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <utility>

#include "../src/utility.hpp"
#include "doctest.h"

template <typename T>
bool smaller(T a, T b)
{
	return (a < b);
}

template <typename T>
bool smallerOrEqu(T a, T b)
{
	return (a <= b);
}

template <typename T>
bool bigger(T a, T b)
{
	return (a > b);
}

template <typename T>
bool biggerOrEqu(T a, T b)
{
	return (a >= b);
}

template <typename T>
bool equal(T a, T b)
{
	return (a == b);
}

template <typename T>
bool different(T a, T b)
{
	return (a != b);
}

template <typename T1, typename T2>
void test_operator(bool func(T1, T1), bool funcStd(T2, T2))
{
	ft::pair<int, int> ftb(3, 7);
	ft::pair<int, int> fta(1, 3);
	ft::pair<int, int> ftc(4, 9);
	ft::pair<int, int> ftd(1, 9);
	ft::pair<int, int> fte(4, 3);
	ft::pair<int, int> ftf(4, 3);

	std::pair<int, int> stdb(3, 7);
	std::pair<int, int> stda(1, 3);
	std::pair<int, int> stdc(4, 9);
	std::pair<int, int> stdd(1, 9);
	std::pair<int, int> stde(4, 3);
	std::pair<int, int> stdf(4, 3);

	CHECK(func(ftb, fta) == funcStd(stdb, stda));
	CHECK(func(ftb, ftc) == funcStd(stdb, stdc));
	CHECK(func(ftb, ftd) == funcStd(stdb, stdd));
	CHECK(func(ftb, fte) == funcStd(stdb, stde));
	CHECK(func(ftb, ftf) == funcStd(stdb, stdf));

	CHECK(func(fta, ftb) == funcStd(stda, stdb));
	CHECK(func(fta, ftc) == funcStd(stda, stdc));
	CHECK(func(fta, ftd) == funcStd(stda, stdd));
	CHECK(func(fta, fte) == funcStd(stda, stde));
	CHECK(func(fta, ftf) == funcStd(stda, stdf));

	CHECK(func(ftc, ftb) == funcStd(stdc, stdb));
	CHECK(func(ftc, fta) == funcStd(stdc, stda));
	CHECK(func(ftc, ftd) == funcStd(stdc, stdd));
	CHECK(func(ftc, fte) == funcStd(stdc, stde));
	CHECK(func(ftc, ftf) == funcStd(stdc, stdf));

	CHECK(func(ftd, ftb) == funcStd(stdd, stdb));
	CHECK(func(ftd, fta) == funcStd(stdd, stda));
	CHECK(func(ftd, ftc) == funcStd(stdd, stdc));
	CHECK(func(ftd, fte) == funcStd(stdd, stde));
	CHECK(func(ftd, ftf) == funcStd(stdd, stdf));

	CHECK(func(ftd, ftb) == funcStd(stdd, stdb));
	CHECK(func(ftd, fta) == funcStd(stdd, stda));
	CHECK(func(ftd, ftc) == funcStd(stdd, stdc));
	CHECK(func(ftd, fte) == funcStd(stdd, stde));
	CHECK(func(ftd, ftf) == funcStd(stdd, stdf));
}

TEST_CASE("test ft::pair template")
{
	SUBCASE("test default constructor")
	{
		std::pair<int, int> a;
		ft::pair<int, int> b;
		CHECK((a.first == b.first && a.second == b.second));
	}
	SUBCASE("test initialization constructor")
	{
		ft::pair<int, int> b(3, 7);
		CHECK((b.first == 3 && b.second == 7));
	}
	SUBCASE("test copy constructor")
	{
		ft::pair<int, int> b(3, 7);
		ft::pair<int, int> a(b);

		CHECK((a.first == b.first && a.second == b.second));
	}
	SUBCASE("test opeators")
	{
		SUBCASE("test operator=")
		{
			ft::pair<int, int> b(3, 7);
			ft::pair<int, int> a;

			a = b;
			CHECK((a.first == b.first && a.second == b.second));
		}
		SUBCASE("test operator==")
		{
			ft::pair<int, int> b(3, 7);
			ft::pair<int, int> a(b);
			ft::pair<int, int> c;

			CHECK(a == b);
			CHECK(!(a == c));
		}
		SUBCASE("test operatot!=")
		{
			ft::pair<int, int> b(3, 7);
			ft::pair<int, int> a(b);
			ft::pair<int, int> c;

			CHECK(a != c);
			CHECK(!(a != b));
		}
		SUBCASE("test operatot<")
		{
			test_operator(smaller<ft::pair<int, int>>,
			              smaller<std::pair<int, int>>);
		}
		SUBCASE("test operatot<=")
		{
			test_operator(smallerOrEqu<ft::pair<int, int>>,
			              smallerOrEqu<std::pair<int, int>>);
		}
		SUBCASE("test operatot>")
		{
			test_operator(bigger<ft::pair<int, int>>,
			              bigger<std::pair<int, int>>);
		}
		SUBCASE("test operatot>=")
		{
			test_operator(biggerOrEqu<ft::pair<int, int>>,
			              biggerOrEqu<std::pair<int, int>>);
		}
	}
}

TEST_CASE("test make pair")
{
	ft::pair<int, float> a = ft::make_pair(13, .37f);

	CHECK((a.first == 13 && a.second == .37f));
}
