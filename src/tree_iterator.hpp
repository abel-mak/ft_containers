/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:46:03 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/13 15:13:30 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <iterator>

namespace ft
{
	template <typename Y>
	struct tree_node
	{
		typedef tree_node *node_ptr;
		typedef const tree_node *const_node_ptr;

		node_ptr parent;
		node_ptr left;
		node_ptr right;
	};

	template <typename node_ptr>
	bool isLeft(node_ptr node)
	{
		if (node != nullptr && node->parent != nullptr &&
		    node->parent->left == node)
			return (true);
		return (false);
	}
	template <typename node_ptr>
	bool isRight(node_ptr node)
	{
		if (node != nullptr && node->parent != nullptr &&
		    node->parent->right == node)
			return (true);
		return (false);
	}

	// inorder successor
	template <typename node_ptr>
	node_ptr nextNode(node_ptr node)
	{
		if (node->right != nullptr)
			return (node->right);
		else
		{
			while (isRight(node) == true)
			{
				node = node->parent;
			}
			return (node->parent);
		}
	}
	template <typename node_ptr>
	node_ptr prevNode(node_ptr node)
	{
		if (node->left != nullptr)
			return (node->left);
		else
		{
			while (isLeft(node) == true)
			{
				node = node->parent;
			}
			return (node->parent);
		}
	}
	template <typename Y>
	struct tree_iterator
	{
		typedef Y value_type;
		typedef Y &reference;
		typedef Y *pointer;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef tree_node<Y> *node_ptr;

		node_ptr node;
		tree_iterator<Y> nextNode(void);
		tree_iterator<Y> prevNode(void);
	};

}  // namespace ft

#endif /* ifndef TREE_ITERATOR_HPP */
