/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_balance_after_insert.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:14:37 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/02 10:33:06 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cassert>
#include <iostream>
#define RED      "\033[31m\e[m"
#define GREEN    "\033[32m\e[m"
#define ENDCOLOR "\e[m"

#include <map>
#include <memory>

#include "../src/tree.hpp"
#include "test_header.hpp"

int height(node *x)
{
	if (x == nullptr)
		return (-1);
	else
	{
		return (std::max(height(x->left), height(x->right)) + 1);
	}
}

void test_balance_after()
{
	// left-left
	{
		node a;
		node x;
		node c;
		node y;

		a.left   = &x;
		x.left   = &c;
		x.parent = &a;
		c.left   = &y;
		c.parent = &x;
		y.parent = &c;
		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		assert(isBalanced(&x) == true);
		// print2D(&a);
	}
	{
		node a;
		node x;
		node c;
		node d;
		node g;

		a.left   = &x;
		x.parent = &a;
		x.left   = &c;
		c.parent = &x;
		c.left   = &d;
		d.parent = &c;
		c.right  = &g;
		g.parent = &c;
		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		assert(isBalanced(&x) == true);
		// print2D(&a);
	}
	{
		node a;
		node x;
		node c;
		node d;
		node g;
		node e;

		a.left   = &x;
		x.parent = &a;
		x.left   = &c;
		c.parent = &x;
		c.left   = &d;
		d.parent = &c;
		c.right  = &g;
		g.parent = &c;

		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		g.left   = &e;
		e.parent = &g;
		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		assert(isBalanced(&x) == true);
		// print2D(&a);
	}
	/**************************************************************************/
	// right-right
	{
		node a;
		node x;
		node c;
		node y;

		a.left   = &x;
		x.right  = &c;
		x.parent = &a;
		c.right  = &y;
		c.parent = &x;
		y.parent = &c;
		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		assert(isBalanced(&x) == true);
		// print2D(&a);
	}
	{
		node a;
		node x;
		node c;
		node d;
		node g;

		a.left   = &x;
		x.parent = &a;
		x.right  = &c;
		c.parent = &x;
		c.right  = &d;
		d.parent = &c;
		c.left   = &g;
		g.parent = &c;
		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		assert(isBalanced(&x) == true);
		// print2D(&a);
	}
	{
		node a;
		node x;
		node c;
		node d;
		node g;
		node e;

		a.left   = &x;
		x.parent = &a;
		x.right  = &c;
		c.parent = &x;
		c.right  = &d;
		d.parent = &c;
		c.left   = &g;
		g.parent = &c;

		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		g.right  = &e;
		e.parent = &g;
		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		assert(isBalanced(&x) == true);
		// print2D(&a);
	}
	/**************************************************************************/
	// left-right
	{
		node a;
		node x;
		node c;
		node g;

		a.left   = &x;
		x.parent = &a;
		x.left   = &c;
		c.parent = &x;
		c.right  = &g;
		g.parent = &c;
		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		assert(isBalanced(&x) == true);
		// print2D(&a);
	}
	/**************************************************************************/
	// right-left
	{
		node a;
		node x;
		node c;
		node d;

		a.left   = &x;
		x.parent = &a;
		x.right  = &c;
		c.parent = &x;
		c.left   = &d;
		d.parent = &c;
		// print2D(&a);
		ft::balanceAfterInsert(&x, &a);
		assert(isBalanced(&x) == true);
		// print2D(&a);
	}
	std::cout << " balance_after_insert " << GREEN << " [OK]" << ENDCOLOR
	          << std::endl;
}
void test_insert()
{
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::pair<const int, int> a(2, 0);
		ft::pair<const int, int> b(3, 0);
		ft::pair<const int, int> c(5, 0);
		ft::pair<const int, int> d(6, 0);
		ft::pair<const int, int> e(9, 0);
		ft::pair<const int, int> f(8, 0);
		ft::pair<const int, int> g(7, 0);
		ft::pair<const int, int> h(4, 0);
		ft::pair<const int, int> ii(1, 0);
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::node_ptr i;

		t.insert(a);
		t.insert(b);
		t.insert(c);
		t.insert(d);
		t.insert(e);
		t.insert(f);
		t.insert(g);
		t.insert(h);
		t.insert(ii);
		i = t.getRoot();

		// print2D(i);
		assert(isBalanced(i));
	}
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::pair<const int, int> a(15, 0);
		ft::pair<const int, int> b(3, 0);
		ft::pair<const int, int> c(9, 0);
		ft::pair<const int, int> d(8, 0);
		ft::pair<const int, int> e(14, 0);
		ft::pair<const int, int> f(13, 0);
		ft::pair<const int, int> g(12, 0);
		ft::pair<const int, int> h(11, 0);
		ft::pair<const int, int> ii(10, 0);
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::node_ptr i;

		t.insert(a);
		t.insert(b);
		t.insert(c);
		t.insert(d);
		t.insert(e);
		t.insert(f);
		t.insert(g);
		t.insert(h);
		t.insert(ii);
		i = t.getRoot();

		// print2D(i);
		assert(isBalanced(i));
	}
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		ft::pair<const int, int> a(77, 0);
		ft::pair<const int, int> b(82, 0);
		ft::pair<const int, int> c(2, 0);
		ft::pair<const int, int> d(25, 0);
		ft::pair<const int, int> e(54, 0);
		ft::pair<const int, int> f(27, 0);
		ft::pair<const int, int> g(21, 0);
		ft::pair<const int, int> h(95, 0);
		ft::pair<const int, int> ii(65, 0);
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >::node_ptr i;

		t.insert(a);
		t.insert(b);
		t.insert(c);
		t.insert(d);
		t.insert(e);
		t.insert(f);
		t.insert(g);
		t.insert(h);
		t.insert(ii);
		i = t.getRoot();

		// print2D(i);
		assert(isBalanced(i));
	}
	{
		std::map<int, int> a;
		// std::cout << (*(a.begin())).second << std::endl;
		//    std::cout << a.size() << std::endl;
		//     while (it != a.end())
		//{
		//	it++;
		//}
	}
	std::cout << " insert " << GREEN << " [OK]" << ENDCOLOR << std::endl;
}
