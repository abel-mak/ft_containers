/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_iterator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:10:11 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/02 10:36:22 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>

#include "../src/tree.hpp"
void test_iterator(void)
{
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::iterator it;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::iterator prev;

		ft::pair<const int, int> a(77, 0);
		ft::pair<const int, int> b(82, 0);
		ft::pair<const int, int> c(2, 0);
		ft::pair<const int, int> d(25, 0);
		ft::pair<const int, int> e(54, 0);
		ft::pair<const int, int> f(27, 0);
		ft::pair<const int, int> g(21, 0);
		ft::pair<const int, int> h(95, 0);
		ft::pair<const int, int> ii(65, 0);

		t.insert(a);
		t.insert(b);
		t.insert(c);
		t.insert(d);
		t.insert(e);
		t.insert(f);
		t.insert(g);
		t.insert(h);
		t.insert(ii);

		it   = t.begin();
		prev = t.begin();
		while (it != t.end())
		{
			if ((*it).first < (*prev).first)
				assert(1 == 0);
			// std::cout << (*it).first << std::endl;
			prev = it;
			++it;
		}
	}
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::iterator it;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::iterator prev;

		ft::pair<const int, int> a(77, 0);
		ft::pair<const int, int> b(82, 0);
		ft::pair<const int, int> c(2, 0);
		ft::pair<const int, int> d(25, 0);
		ft::pair<const int, int> e(54, 0);
		ft::pair<const int, int> f(27, 0);
		ft::pair<const int, int> g(21, 0);
		ft::pair<const int, int> h(95, 0);
		ft::pair<const int, int> ii(65, 0);

		t.insert(a);
		t.insert(b);
		t.insert(c);
		t.insert(d);
		t.insert(e);
		t.insert(f);
		t.insert(g);
		t.insert(h);
		t.insert(ii);

		it   = t.end();
		prev = t.end();
		--it;
		--prev;
		while (1)
		{
			if (it->first > prev->first)
				assert(1 == 0);
			// std::cout << (*it).first << std::endl;
			if (it == t.begin())
				break;
			prev = it;
			it--;
		}
	}
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::iterator it;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::iterator prev;
		assert(it == prev);
	}
	// std::cout << "tree_iterator operator== and operator!= [OK]" << std::endl;
	// std::cout << "tree_iterator operator-> [OK]" << std::endl;
	// std::cout << "tree_iterator both operator++ [OK]" << std::endl;
	// std::cout << "tree_iterator both operator-- [OK]" << std::endl;
	// std::cout << "tree_iterator operator* [OK]" << std::endl;
	std::cout << " tree_iterator [OK]" << std::endl;
}
