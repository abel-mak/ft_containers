/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:17:28 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/02 12:29:21 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>

#include "../src/iterator.hpp"
#include "doctest.h"

int sum(int a, int b)
{
	return (a + b);
}

TEST_CASE("test ft::normal_iterator")
{
	SUBCASE("test operators")
	{
		std::__wrap_iter<char *> std_i1;
		//	std_i1 -= reinterpret_cast<std::__wrap_iter<char
		//*>::difference_type>( 	    std_i1.base()); 	std_i1 +=
		//	    reinterpret_cast<std::__wrap_iter<char
		//*>::difference_type>(&t1);
		ft::normal_iterator<char *> ft_i1(std_i1.base());

		CHECK(ft_i1.base() == std_i1.base());
		CHECK((ft_i1++).base() == (std_i1++).base());
		CHECK((++ft_i1).base() == (++std_i1).base());
		CHECK((ft_i1--).base() == (std_i1--).base());
		CHECK((--ft_i1).base() == (--std_i1).base());
		CHECK((ft_i1 += 5).base() == (std_i1 += 5).base());
		CHECK((ft_i1 -= 5).base() == (std_i1 -= 5).base());
		CHECK((ft_i1 + 5).base() == (std_i1 + 5).base());
		CHECK((ft_i1 - 5).base() == (std_i1 - 5).base());
	}
	SUBCASE("test comparison")
	{
		std::__wrap_iter<char *> std_rev1;
		ft::normal_iterator<char *> ft_rev1(std_rev1.base());

		std::__wrap_iter<char *> std_rev2;
		ft::normal_iterator<char *> ft_rev2(std_rev2.base());
		bool b1, b2;

		std_rev1++;
		ft_rev1++;

		std::cout << static_cast<void *>(std_rev1.base()) << std::endl;
		std::cout << static_cast<void *>(ft_rev1.base()) << std::endl;
		b1 = (std_rev1 == std_rev2);
		b2 = (ft_rev1 == ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 > std_rev2);
		b2 = (ft_rev1 > ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 < std_rev2);
		b2 = (ft_rev1 < ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 >= std_rev2);
		b2 = (ft_rev1 >= ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 <= std_rev2);
		b2 = (ft_rev1 <= ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 != std_rev2);
		b2 = (ft_rev1 != ft_rev2);
		CHECK(b1 == b2);
	}
}

TEST_CASE("test ft::reverse_iterator")
{
	SUBCASE("test operators")
	{
		std::reverse_iterator<ft::normal_iterator<char *>> std_rev1;
		ft::reverse_iterator<ft::normal_iterator<char *>> ft_rev1(
		    std_rev1.base());

		CHECK((static_cast<void *>(std_rev1.base().base()) ==
		       static_cast<void *>(ft_rev1.base().base())));
		ft_rev1++;
		std_rev1++;
		CHECK((static_cast<void *>(std_rev1.base().base()) ==
		       static_cast<void *>(ft_rev1.base().base())));

		CHECK(ft_rev1.base() == std_rev1.base());
		CHECK((ft_rev1++).base() == (std_rev1++).base());
		CHECK((++ft_rev1).base() == (++std_rev1).base());
		CHECK((ft_rev1--).base() == (std_rev1--).base());
		CHECK((--ft_rev1).base() == (--std_rev1).base());
		CHECK((ft_rev1 += 5).base() == (std_rev1 += 5).base());
		CHECK((ft_rev1 -= 5).base() == (std_rev1 -= 5).base());
		CHECK((ft_rev1 + 5).base() == (std_rev1 + 5).base());
		CHECK((ft_rev1 - 5).base() == (std_rev1 - 5).base());
	}
	SUBCASE("test comparison operators")
	{
		std::reverse_iterator<char *> std_rev1;
		ft::reverse_iterator<char *> ft_rev1(std_rev1.base());

		std::reverse_iterator<char *> std_rev2;
		ft::reverse_iterator<char *> ft_rev2(std_rev2.base());
		bool b1, b2;

		std_rev1++;
		ft_rev1++;

		std::cout << static_cast<void *>(std_rev1.base()) << std::endl;
		std::cout << static_cast<void *>(ft_rev1.base()) << std::endl;
		b1 = (std_rev1 == std_rev2);
		b2 = (ft_rev1 == ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 > std_rev2);
		b2 = (ft_rev1 > ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 < std_rev2);
		b2 = (ft_rev1 < ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 >= std_rev2);
		b2 = (ft_rev1 >= ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 <= std_rev2);
		b2 = (ft_rev1 <= ft_rev2);
		CHECK(b1 == b2);
		b1 = (std_rev1 != std_rev2);
		b2 = (ft_rev1 != ft_rev2);
		CHECK(b1 == b2);
	}
}

