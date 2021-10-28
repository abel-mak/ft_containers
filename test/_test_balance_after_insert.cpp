/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_balance_after_insert.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:14:37 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/28 19:18:28 by abel-mak         ###   ########.fr       */
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

void test_balance_after()
{
	{
		node root;
		node x;
		node y;

		root.left = &x;
		x.left    = &y;
		x.parent  = &root;
		y.parent  = &x;

		ft::balanceAfterInsert(&x, &root);
		assert(isBalanced(&x) == true);
	}
	std::cout << " balance_after_insert " << GREEN << " [OK]" << ENDCOLOR
	          << std::endl;
}
