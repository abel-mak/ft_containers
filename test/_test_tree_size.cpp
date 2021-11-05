/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tree_size.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:43:15 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/05 19:32:59 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/tree.hpp"
#include "test_header.hpp"

void test_size()
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

		assert(t.size() == 0);

		t.insert(a);
		t.insert(b);
		t.insert(c);

		assert(t.size() == 3);

		t.insert(d);
		t.insert(e);
		t.insert(f);

		assert(t.size() == 6);

		it = t.begin();
		// print2D(t.getRoot());
		while (it != t.end())
		{
			if (it->first == 54)
			{
				t.erase(it);
				break;
			}
			it++;
		}
		assert(t.size() == 5);
	}
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::iterator it;

		ft::pair<const int, int> a(77, 0);
		ft::pair<const int, int> b(82, 0);
		ft::pair<const int, int> c(2, 0);

		t.insert(a);
		t.insert(b);
		t.insert(c);

		// print2D(t.getRoot());
		it = t.begin();
		while (it != t.end())
		{
			if (it->first == 77)
			{
				t.erase(it);
				break;
			}
			it++;
		}
		// print2D(t.getRoot());
		assert(t.size() == 2);

		it = t.begin();
		while (it != t.end())
		{
			if (it->first == 82)
			{
				t.erase(it);
				break;
			}
			it++;
		}
		assert(t.size() == 1);
		// print2D(t.getRoot());

		it = t.begin();
		while (it != t.end())
		{
			if (it->first == 2)
			{
				t.erase(it);
				break;
			}
			it++;
		}
		// print2D(t.getRoot());
		assert(t.size() == 0);

		it = t.begin();
		while (it != t.end())
		{
			if (it->first == 2)
			{
				t.erase(it);
				break;
			}
			it++;
		}
		assert(t.size() == 0);
	}
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    tmp;

		ft::pair<const int, int> a(77, 0);

		t.insert(a);

		// print2D(t.getRoot());
		// print2D(tmp.getRoot());

		t.swap(tmp);
		assert((tmp.getRoot())->value.first == 77);
		assert((t.getRoot()) == nullptr);
		// print2D(t.getRoot());
		// print2D(tmp.getRoot());
	}
}
