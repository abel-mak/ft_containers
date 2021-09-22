/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:40 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/22 18:10:36 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
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

int main()
{
	// ft::vector<int> a(5, 2);
	std::allocator<int> alloc;
	std::vector<int> myints(5, 2);
	std::string s1 = "abcde";
	std::string s2 = "abcdef";
	ft::pair<int, int> a;
	ft::pair<int, int> b;
	ft::vector<int> x;
	ft::vector<int>::iterator iter = x.begin();
	int i;

	i = 0;
	while (i < 4)
	{
		std::cout << *iter << std::endl;
		iter++;
		i++;
	}
	// std::equal(s1.begin(), s1.end(), s2.begin());
	//	std::cout << ft::is_integral<std::vector<int> >::value << std::endl;
	//	std::cout << std::is_integral<std::vector<int> >::value <<
	// std::endl;
	// assert(myints[0] == a[0]);
	// assert(myints.size() == a.size());
	// assert(myints.capacity() == a.capacity());
	// std::cout << "✅" << std::endl;
	// put(myints[0]);
	// put(myints.size());
	// put(myints.capacity());
	// put(a[0]);
	// put(a.size());
	// put(a.capacity());
	// myints.push_back(10);
	return (0);
}
