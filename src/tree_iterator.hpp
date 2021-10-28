/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:46:03 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/28 13:39:02 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <algorithm>
#include <iterator>

namespace ft
{

	template <typename Y>
	struct tree_node
	{
		typedef tree_node *node_ptr;
		typedef const tree_node *const_node_ptr;

		Y value;
		node_ptr parent;
		node_ptr left;
		node_ptr right;

		tree_node(const tree_node &src);
		tree_node &operator=(const tree_node &lhs);
		tree_node(void);
	};
	template <typename Y>
	tree_node<Y>::tree_node(void)
	{
		this->parent = nullptr;
		this->left   = nullptr;
		this->right  = nullptr;
	}
	template <typename Y>
	tree_node<Y>::tree_node(const tree_node &src)
	{
		*this = src;
	}
	template <typename Y>
	tree_node<Y> &tree_node<Y>::operator=(const tree_node &lhs)
	{
		this->value  = lhs.value;
		this->parent = lhs.value;
		this->left   = lhs.left;
		this->right  = lhs.right;
		return (*this);
	}
	/**************************************************************************/
	/*
	 * [x] operator*()
	 * [x] operator->()
	 * [x] operator++()
	 * [x] operator++(int)
	 * [x] operator--()
	 * [x] operator--()
	 * [x] operator==()
	 * [x] operator!=()
	 */
	template <typename Y>
	struct tree_iterator
	{
		typedef Y value_type;
		typedef Y &reference;
		typedef Y *pointer;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef tree_node<Y> *node_ptr;

		node_ptr _node;

		tree_iterator(void);
		tree_iterator(const node_ptr node);
		reference operator*() const;
		pointer operator->() const;
		tree_iterator &operator++();
		tree_iterator operator++(int);
		tree_iterator &operator--();
		tree_iterator operator--(int);
		bool operator==(tree_iterator const &x);
		bool operator!=(tree_iterator const &x);
	};
	template <typename Y>
	tree_iterator<Y>::tree_iterator(void) : _node(nullptr)
	{
	}
	template <typename Y>
	tree_iterator<Y>::tree_iterator(const node_ptr node) : _node(node)
	{
	}
	template <typename Y>
	typename tree_iterator<Y>::reference tree_iterator<Y>::operator*(void) const
	{
		return (this->_node->value);
	}
	template <typename Y>
	typename tree_iterator<Y>::pointer tree_iterator<Y>::operator->(void) const
	{
		return (_node);
	}
	template <typename Y>
	tree_iterator<Y> &tree_iterator<Y>::operator++()
	{
		_node = nextNode(_node);
		return (*this);
	}
	template <typename Y>
	tree_iterator<Y> tree_iterator<Y>::operator++(int)
	{
		tree_iterator tmp(_node);
		++this;
		return (tmp);
	}
	template <typename Y>
	tree_iterator<Y> &tree_iterator<Y>::operator--()
	{
		_node = prevNode(_node);
		return (*this);
	}
	template <typename Y>
	tree_iterator<Y> tree_iterator<Y>::operator--(int)
	{
		tree_iterator tmp(_node);

		--this;
		return (tmp);
	}
	template <typename Y>
	bool tree_iterator<Y>::operator==(tree_iterator const &x)
	{
		return (_node == x._node);
	}
	template <typename Y>
	bool tree_iterator<Y>::operator!=(tree_iterator const &x)
	{
		return (!(*this == x));
	}
	/**************************************************************************/
	template <typename node_ptr>
	node_ptr tree_min(node_ptr x)
	{
		while (x->left != nullptr)
		{
			x = x->left;
		}
		return (x);
	}
	template <typename node_ptr>
	node_ptr tree_max(node_ptr x)
	{
		while (x->right != nullptr)
		{
			x = x->right;
		}
		return (x);
	}
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
	size_t height(typename tree_node<Y>::node_ptr x)
	{
		if (x == nullptr)
			return (-1);
		else
			return (std::max(height(x->left), height(x->right)) + 1);
	}
}  // namespace ft

#endif /* ifndef TREE_ITERATOR_HPP */
