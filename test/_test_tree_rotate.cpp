/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree_rotate.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:42:49 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/01 14:36:03 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define ENDCOLOR "\e[m"

#include "../src/tree.hpp"
#include "test_header.hpp"

void test()
{
	{
		node root;
		node x;
		node y;

		root.left = &x;
		x.left    = &y;
		x.parent  = &root;
		y.parent  = &x;
		ft::rightRotate(&x);
		assert(root.parent == 0);
		assert(root.left == &y);
		assert(root.right == 0);
		assert(y.parent == &root);
		assert(y.left == 0);
		assert(y.right == &x);
		assert(x.parent == &y);
		assert(x.left == 0);
		assert(x.right == 0);
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
		ft::rightRotate(&x);
		assert(a.left == &c);
		assert(x.left == &g);
		assert(x.right == 0);
		assert(x.parent == &c);
		assert(c.left == &d);
		assert(c.right == &x);
		assert(c.parent == &a);
		assert(d.parent == &c);
		assert(g.parent == &x);
	}
	{
		node root;
		node x;
		node y;
		node a;
		node b;
		node c;

		root.left = &x;
		x.left    = &y;
		x.right   = &c;
		x.parent  = &root;
		y.left    = &a;
		y.right   = &b;
		y.parent  = &x;
		a.parent  = &y;
		b.parent  = &y;
		c.parent  = &x;
		ft::rightRotate(&x);
		assert(root.parent == 0);
		assert(root.left == &y);
		assert(root.right == 0);
		assert(y.parent == &root);
		assert(y.left == &a);
		assert(y.right == &x);
		assert(x.parent == &y);
		assert(x.left == &b);
		assert(x.right == &c);
		assert(a.parent == &y);
		assert(a.left == 0);
		assert(a.right == 0);
		assert(b.parent == &x);
		assert(b.left == 0);
		assert(b.right == 0);
		assert(c.parent == &x);
		assert(c.left == 0);
		assert(c.right == 0);
	}
	/**************************************************************************/
	{
		node root;
		node x;
		node y;

		root.left = &x;
		x.right   = &y;
		x.parent  = &root;
		y.parent  = &x;
		ft::leftRotate(&x);
		assert(root.parent == 0);
		assert(root.left == &y);
		assert(root.right == 0);
		assert(y.parent == &root);
		assert(y.left == &x);
		assert(y.right == 0);
		assert(x.parent == &y);
		assert(x.left == 0);
		assert(x.right == 0);
	}
	{
		node a;
		node x;
		node c;
		node d;
		node g;

		a.right  = &x;
		x.parent = &a;
		x.right  = &c;
		c.parent = &x;
		c.right  = &d;
		d.parent = &c;
		c.left   = &g;
		g.parent = &c;
		ft::leftRotate(&x);
		assert(a.right == &c);
		assert(x.left == 0);
		assert(x.right == &g);
		assert(x.parent == &c);
		assert(c.left == &x);
		assert(c.right == &d);
		assert(c.parent == &a);
		assert(d.parent == &c);
		assert(g.parent == &x);
	}
	{
		node root;
		node x;
		node y;
		node a;
		node b;
		node c;

		root.left = &x;
		x.left    = &a;
		x.right   = &y;
		x.parent  = &root;
		y.left    = &b;
		y.right   = &c;
		y.parent  = &x;
		a.parent  = &x;
		b.parent  = &y;
		c.parent  = &y;
		ft::leftRotate(&x);
		assert(root.parent == 0);
		assert(root.left == &y);
		assert(root.right == 0);
		assert(y.parent == &root);
		assert(y.left == &x);
		assert(y.right == &c);
		assert(x.parent == &y);
		assert(x.left == &a);
		assert(x.right == &b);
		assert(a.parent == &x);
		assert(a.left == 0);
		assert(a.right == 0);
		assert(b.parent == &x);
		assert(b.left == 0);
		assert(b.right == 0);
		assert(c.parent == &y);
		assert(c.left == 0);
		assert(c.right == 0);
	}
	std::cout << " tree_rotate " << GREEN << " [OK]" << ENDCOLOR << std::endl;
}

void test_balance_after(void);
void test_insert(void);
void test_iterator(void);

int main(void)
{
	test();
	test_balance_after();
	test_insert();
	test_iterator();
}
