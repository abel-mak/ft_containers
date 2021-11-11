/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_header.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:07:56 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/11 20:18:44 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEADER
#define TEST_HEADER

#include "../src/utility.hpp"

struct node
{
	ft::pair<int, int> value;
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

int height(node *x);

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

	print2DUtil(static_cast<node_ptr>(root->right), space, depth + 1);

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

	print2DUtil(static_cast<node_ptr>(root->left), space, depth + 1);
}

template <typename node_ptr>
void print2D(node_ptr *root)
{
	print2DUtil(root, 0, 0);
	std::cout << "***********************************************" << std::endl;
}

#endif
