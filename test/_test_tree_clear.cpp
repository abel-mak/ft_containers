/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tree_clear.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:01:07 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/08 11:24:59 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../src/tree.hpp"

void test_clear(void)
{
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::b_node_ptr root;

		ft::pair<const int, int> a(2, 0);
		ft::pair<const int, int> b(3, 0);
		ft::pair<const int, int> c(5, 0);
		ft::pair<const int, int> d(6, 0);
		ft::pair<const int, int> e(9, 0);
		ft::pair<const int, int> f(8, 0);
		ft::pair<const int, int> g(7, 0);
		ft::pair<const int, int> h(4, 0);
		ft::pair<const int, int> ii(1, 0);

		t.insert(a);
		t.insert(b);
		t.insert(c);
		t.insert(d);
		t.insert(e);
		t.insert(f);
		t.insert(g);
		t.insert(h);
		t.insert(ii);

		t.clear();
		root = t.getRoot();
		assert(t.size() == 0);
		assert(root == nullptr);
	}
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::b_node_ptr root;

		t.clear();
		root = t.getRoot();
		assert(t.size() == 0);
		assert(root == nullptr);
	}
	std::cout << " test_clear [OK]" << std::endl;
}
