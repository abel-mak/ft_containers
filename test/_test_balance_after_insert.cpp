/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_balance_after_insert.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:14:37 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/31 18:19:47 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#define RED      "\033[31m\e[m"
#define GREEN    "\033[32m\e[m"
#define ENDCOLOR "\e[m"

#include "../src/tree.hpp"

struct node
{
	std::pair<int, int> value;
	node *left;
	node *right;
	node *parent;
	node()
	{
		left   = nullptr;
		right  = nullptr;
		parent = nullptr;
	}
};

int height(node *x)
{
	if (x == nullptr)
		return (-1);
	else
	{
		return (std::max(height(x->left), height(x->right)) + 1);
	}
}
template <typename node_ptr>
void balanceFactor(node_ptr x, bool &res)
{
	int dh;

	if (x->left != nullptr)
		balanceFactor(x->left, res);
	if (x->right != nullptr)
		balanceFactor(x->right, res);
	if (x != nullptr)
	{
		dh = abs(height(x->left) - height(x->right));
		if (res == true && dh > 1)
			res = false;
	}
}
template <typename node_ptr>
bool isBalanced(node_ptr root)
{
	bool res;
	if (root == nullptr)
		return (true);
	res = true;
	balanceFactor(root, res);
	return (res);
}

#define COUNT 10

template <typename node_ptr>
void print2DUtil(node_ptr root, int space, int depth)
{
	if (root == 0)
		return;

	space += COUNT;

	print2DUtil(root->right, space, depth + 1);

	std::cout << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "depth: " << depth << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "node: " << root << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "right: " << root->right << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "left: " << root->left << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "parent: " << root->parent << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "key: " << root->value.first << std::endl;

	print2DUtil(root->left, space, depth + 1);
}

template <typename node_ptr>
void print2D(node_ptr *root)
{
	print2DUtil(root, 0, 0);
	std::cout << "***********************************************" << std::endl;
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
	std::cout << " insert " << GREEN << " [OK]" << ENDCOLOR << std::endl;
}
