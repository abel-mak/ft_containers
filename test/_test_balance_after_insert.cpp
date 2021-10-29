/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_balance_after_insert.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:14:37 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/29 18:49:57 by abel-mak         ###   ########.fr       */
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

void balanceFactor(node *x, bool &res)
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

bool isBalanced(node *root)
{
	bool res;
	if (root == nullptr)
		return (true);
	res = true;
	balanceFactor(root, res);
	return (res);
}

#define COUNT 10

void print2DUtil(node *root, int space, int depth)
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

	print2DUtil(root->left, space, depth + 1);
}

void print2D(node *root)
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
