/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:40 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/27 18:05:17 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <map>
#include <memory>
#include <vector>

#include "src/algorithm.hpp"
#include "src/type_traits.hpp"
#include "src/utility.hpp"
#include "src/vector.hpp"

template <typename B>
void my_function(B begin, B end, int)
{
	begin++;
	end++;
	// Bidirectional Iterator specific code is here
}

template <class T>
typename std::enable_if<false, T>::type foo1(T t)
{
	std::cout << "foo1: float\n";
	return t;
}

void put(int const s)
{
	std::cout << s << std::endl;
}

struct test
{
	int a;
	int b;
};

int main()
{
	// ft::vector<int> a(5, 2);
	std::allocator<int> alloc;
	std::vector<int> myints(5, 2);
	std::string s1 = "abcde";
	std::string s2 = "abcdef";
	ft::pair<int, int> a;
	ft::pair<int, int> b;
	std::vector<int> x(10);

	std::cout << "size: " << x.size() << std::endl;
	std::cout << "capL " << x.capacity() << std::endl;
	//	ft::vector<int>::iterator iter   = x.begin();
	//	std::vector<int>::iterator iter2 = myints.begin();
	//	ft::vector<int>::iterator *iterp;
	//	int i;
	struct test t1;
	t1.a = 1997;
	std::vector<struct test> t(1, t1);
	std::vector<struct test>::iterator t_iter = t.begin();
	// std::cout << t1.a << std::endl;

	while (t_iter != t.end())
	{
		std::cout << (*t_iter).a << std::endl;
		t_iter++;
	}
	return (0);
}
