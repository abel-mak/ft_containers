/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utility.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:36:53 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/24 18:23:20 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>

#include "../src/utility.hpp"

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

	assert(func(ftb, fta) == funcStd(stdb, stda));
	assert(func(ftb, ftc) == funcStd(stdb, stdc));
	assert(func(ftb, ftd) == funcStd(stdb, stdd));
	assert(func(ftb, fte) == funcStd(stdb, stde));
	assert(func(ftb, ftf) == funcStd(stdb, stdf));

	assert(func(fta, ftb) == funcStd(stda, stdb));
	assert(func(fta, ftc) == funcStd(stda, stdc));
	assert(func(fta, ftd) == funcStd(stda, stdd));
	assert(func(fta, fte) == funcStd(stda, stde));
	assert(func(fta, ftf) == funcStd(stda, stdf));

	assert(func(ftc, ftb) == funcStd(stdc, stdb));
	assert(func(ftc, fta) == funcStd(stdc, stda));
	assert(func(ftc, ftd) == funcStd(stdc, stdd));
	assert(func(ftc, fte) == funcStd(stdc, stde));
	assert(func(ftc, ftf) == funcStd(stdc, stdf));

	assert(func(ftd, ftb) == funcStd(stdd, stdb));
	assert(func(ftd, fta) == funcStd(stdd, stda));
	assert(func(ftd, ftc) == funcStd(stdd, stdc));
	assert(func(ftd, fte) == funcStd(stdd, stde));
	assert(func(ftd, ftf) == funcStd(stdd, stdf));

	assert(func(ftd, ftb) == funcStd(stdd, stdb));
	assert(func(ftd, fta) == funcStd(stdd, stda));
	assert(func(ftd, ftc) == funcStd(stdd, stdc));
	assert(func(ftd, fte) == funcStd(stdd, stde));
	assert(func(ftd, ftf) == funcStd(stdd, stdf));
}
void test_utility(void)
{
	//("test default constructor")
	{
		std::pair<int, int> a;
		ft::pair<int, int> b;
		assert((a.first == b.first && a.second == b.second));
	}
	//("test initialization constructor")
	{
		ft::pair<int, int> b(3, 7);
		assert((b.first == 3 && b.second == 7));
	}
	//("test copy constructor")
	{
		ft::pair<int, int> b(3, 7);
		ft::pair<int, int> a(b);

		assert((a.first == b.first && a.second == b.second));
	}
	//("test opeators")
	{  //("test operator=")
		{
			ft::pair<int, int> b(3, 7);
			ft::pair<int, int> a;

			a = b;
			assert((a.first == b.first && a.second == b.second));
			//("test operator==")
			{
				ft::pair<int, int> b(3, 7);
				ft::pair<int, int> a(b);
				ft::pair<int, int> c;

				assert(a == b);
				assert(!(a == c));
			}
			//("test operatot!=")
			{
				ft::pair<int, int> b(3, 7);
				ft::pair<int, int> a(b);
				ft::pair<int, int> c;

				assert(a != c);
				assert(!(a != b));
			}
			//("test operatot<")
			{
				test_operator(smaller<ft::pair<int, int> >,
				              smaller<std::pair<int, int> >);
			}
			//("test operatot<=")
			{
				test_operator(smallerOrEqu<ft::pair<int, int> >,
				              smallerOrEqu<std::pair<int, int> >);
			}
			//("test operatot>")
			{
				test_operator(bigger<ft::pair<int, int> >,
				              bigger<std::pair<int, int> >);
			}
			//("test operatot>=")
			{
				test_operator(biggerOrEqu<ft::pair<int, int> >,
				              biggerOrEqu<std::pair<int, int> >);
			}
		}
		{
			ft::pair<int, float> a = ft::make_pair(13, .37f);

			assert((a.first == 13 && a.second == .37f));
		}
	}
	std::cout << " utility [OK] " << std::endl;
}
