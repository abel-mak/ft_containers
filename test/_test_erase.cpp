/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_erase.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:19:46 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/03 19:45:35 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/tree.hpp"
#include "test_header.hpp"

void test_erase()
{
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::iterator it;

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

		it = t.begin();
		print2D(t.getRoot());
		while (it != t.end())
		{
			if (it->first == 54)
				t.erase(it);
			it++;
		}
		// print2D(t.getRoot());
	}
}
