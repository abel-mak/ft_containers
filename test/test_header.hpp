/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_header.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:07:56 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/24 18:26:02 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEADER
#define TEST_HEADER

#include "../src/utility.hpp"

struct node
{
	ft::pair<int, int> value;
	int height;
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
void printUtils(node_ptr root, int space, int depth, int &size)
{
	if (root == 0)
		return;

	space += COUNT;

	printUtils(static_cast<node_ptr>(root->right), space, depth + 1, size);

	std::cout << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "height: " << root->height << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "node: " << root << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "right: " << root->right << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "left: " << root->left << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "parent: " << root->parent << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "depth: " << depth << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "key: " << root->value.first << std::endl;
	size++;
	printUtils(static_cast<node_ptr>(root->left), space, depth + 1, size);
}

template <typename node_ptr>
void print2D(node_ptr *root)
{
	int size;

	size = 0;
	printUtils(root, 0, 0, size);
	std::cout << "*********************************************** size: "
	          << size << std::endl;
}

#endif
