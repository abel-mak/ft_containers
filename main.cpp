/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:40 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/05 18:54:25 by abel-mak         ###   ########.fr       */
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
	test(void)
	{
		a = 5;
		std::cout << "contructor called!" << std::endl;
	}
	test(const test &src)
	{
		a = 3;
		(void)src;
		std::cout << "copy contructor called!" << std::endl;
	}
	test(int z)
	{
		this->a = z;
	}
	~test(void)
	{
		std::cout << "destructor called" << std::endl;
	}
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
	struct test t1;
	struct test az[] = {t1, t1, t1};

	std::vector<struct test> azv1(std::begin(az), std::end(az));
	std::cout << "===============" << std::endl;
	azv1.reserve(4);
	std::cout << "size: " << azv1.size() << std::endl;
	std::cout << "capacity: " << azv1.capacity() << std::endl;
	std::cout << "===============" << std::endl;
	// azv1.reserve(0);
	// std::vector<struct test> azv11(azv1);

	// ft::vector<struct test> azv2(std::begin(az), std::end(az));
	// std::cout << "===============" << std::endl;
	// azv2.resize(4);
	// std::cout << "size: " << azv2.size() << std::endl;
	// std::cout << "capacity: " << azv2.capacity() << std::endl;
	// std::cout << "===============" << std::endl;

	// azv2.reserve(-1);
	// ft::vector<struct test> azv22(azv2);
	// ft::vector<struct test> azv2(std::begin(az), std::end(az));
	// std::cout << "size: " << x.size() << std::endl;
	// std::cout << "capL " << x.capacity() << std::endl;
	//	ft::vector<int>::iterator iter   = x.begin();
	//	std::vector<int>::iterator iter2 = myints.begin();
	//	ft::vector<int>::iterator *iterp;
	//	int i;
	// std::vector<struct test> v(10, t1);
	// ft::vector<struct test> v(10, t1);
	// std::cout << t1.a << std::endl;

	//	std::vector<struct test> t(1, t1);
	//	std::vector<struct test>::iterator t_iter = t.begin();
	//	while (t_iter != t.end())
	//	{
	//		std::cout << (*t_iter).a << std::endl;
	//		t_iter++;
	//	}
	return (0);
}
