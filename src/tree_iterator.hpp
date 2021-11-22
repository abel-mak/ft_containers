/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:46:03 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/22 13:08:35 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <algorithm>
#include <iostream>

namespace ft
{
	// added template just avoid duplicate symbols
	template <typename T = void>
	struct tree_node_base
	{
		typedef tree_node_base *b_node_ptr;
		typedef const tree_node_base *const_b_node_ptr;

		b_node_ptr parent;
		b_node_ptr left;
		b_node_ptr right;

		tree_node_base(void);
		tree_node_base(const tree_node_base &src);
		tree_node_base &operator=(const tree_node_base &lhs);
	};
	template <typename T>
	tree_node_base<T>::tree_node_base(void)
	{
		this->parent = nullptr;
		this->left   = nullptr;
		this->right  = nullptr;
	}
	template <typename T>
	tree_node_base<T>::tree_node_base(const tree_node_base &src)
	{
		*this = src;
	}
	template <typename T>
	tree_node_base<T> &tree_node_base<T>::operator=(const tree_node_base &lhs)
	{
		this->parent = lhs.parent;
		this->left   = lhs.left;
		this->right  = lhs.right;
		return (*this);
	}
	/**************************************************************************/
	template <typename Y>
	struct tree_node : public tree_node_base<void>
	{
		typedef tree_node *node_ptr;
		typedef const tree_node *const_node_ptr;

		Y value;
		int height;
		tree_node(void);
		tree_node(const tree_node &src);
		tree_node(const Y &value);
		tree_node &operator=(tree_node const &lhs);
	};
	template <typename Y>
	tree_node<Y>::tree_node(void)
	{
	}
	template <typename Y>
	tree_node<Y>::tree_node(const Y &value) : value(value), height(0)
	{
	}
	template <typename Y>
	tree_node<Y>::tree_node(const tree_node &src) : value(src.value), height(0)
	{
	}
	template <typename Y>
	tree_node<Y> &tree_node<Y>::operator=(tree_node const &lhs)
	{
		tree_node_base::operator=(lhs);
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
		typedef tree_node_base<>::b_node_ptr b_node_ptr;
		typedef const tree_node_base<>::b_node_ptr const_b_node_ptr;

		tree_iterator(void);
		tree_iterator(b_node_ptr node);
		reference operator*() const;
		pointer operator->() const;
		tree_iterator &operator++();
		tree_iterator operator++(int);
		tree_iterator &operator--();
		tree_iterator operator--(int);
		bool operator==(tree_iterator const &x);
		bool operator!=(tree_iterator const &x);
		b_node_ptr getNodePtr(void) const;

	private:
		b_node_ptr _node;
	};
	template <typename Y>
	tree_iterator<Y>::tree_iterator(void) : _node(nullptr)
	{
	}
	template <typename Y>
	tree_iterator<Y>::tree_iterator(b_node_ptr node) : _node(node)
	{
	}
	template <typename Y>
	typename tree_iterator<Y>::reference tree_iterator<Y>::operator*(void) const
	{
		return ((static_cast<node_ptr>(_node))->value);
	}
	template <typename Y>
	typename tree_iterator<Y>::pointer tree_iterator<Y>::operator->(void) const
	{
		return (&((static_cast<node_ptr>(_node))->value));
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
		++(*this);
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

		--(*this);
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
	template <typename Y>
	typename tree_iterator<Y>::b_node_ptr tree_iterator<Y>::getNodePtr(void) const
	{
		return (_node);
	}
	/**************************************************************************/
	template <typename Y>
	struct tree_const_iterator
	{
		typedef const Y value_type;
		typedef const Y &reference;
		typedef const Y *pointer;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef const tree_node<Y> *const_node_ptr;
		typedef tree_node_base<>::b_node_ptr b_node_ptr;
		typedef tree_node_base<>::const_b_node_ptr const_b_node_ptr;
		typedef tree_iterator<Y> iterator;

		tree_const_iterator(void);
		tree_const_iterator(const_b_node_ptr node);
		tree_const_iterator(iterator it);
		reference operator*() const;
		pointer operator->() const;
		tree_const_iterator &operator++();
		tree_const_iterator operator++(int);
		tree_const_iterator &operator--();
		tree_const_iterator operator--(int);
		bool operator==(tree_const_iterator const &x);
		bool operator!=(tree_const_iterator const &x);
		const_b_node_ptr getNodePtr(void) const;

	private:
		const_b_node_ptr _node;
	};

	template <typename Y>
	tree_const_iterator<Y>::tree_const_iterator(void) : _node(nullptr)
	{
	}
	template <typename Y>
	tree_const_iterator<Y>::tree_const_iterator(const_b_node_ptr node)
	    : _node(static_cast<const_b_node_ptr>(node))
	{
	}
	template <typename Y>
	tree_const_iterator<Y>::tree_const_iterator(iterator it)
	    : _node(it.getNodePtr())
	{
	}
	template <typename Y>
	typename tree_const_iterator<Y>::reference
	tree_const_iterator<Y>::operator*(void) const
	{
		return ((static_cast<const_node_ptr>(_node))->value);
	}
	template <typename Y>
	typename tree_const_iterator<Y>::pointer tree_const_iterator<Y>::operator->(
	    void) const
	{
		return (&((static_cast<const_node_ptr>(_node))->value));
	}
	template <typename Y>
	tree_const_iterator<Y> &tree_const_iterator<Y>::operator++()
	{
		_node = nextNode(_node);
		return (*this);
	}
	template <typename Y>
	tree_const_iterator<Y> tree_const_iterator<Y>::operator++(int)
	{
		tree_const_iterator tmp(_node);
		++(*this);
		return (tmp);
	}
	template <typename Y>
	tree_const_iterator<Y> &tree_const_iterator<Y>::operator--()
	{
		_node = prevNode(_node);
		return (*this);
	}
	template <typename Y>
	tree_const_iterator<Y> tree_const_iterator<Y>::operator--(int)
	{
		tree_const_iterator tmp(_node);

		--(*this);
		return (tmp);
	}
	template <typename Y>
	bool tree_const_iterator<Y>::operator==(tree_const_iterator const &x)
	{
		return (_node == x._node);
	}
	template <typename Y>
	bool tree_const_iterator<Y>::operator!=(tree_const_iterator const &x)
	{
		return (!(*this == x));
	}
	template <typename Y>
	typename tree_const_iterator<Y>::const_b_node_ptr
	tree_const_iterator<Y>::getNodePtr(void) const
	{
		return (_node);
	}
	/**************************************************************************/
	template <typename b_node_ptr>
	b_node_ptr tree_min(b_node_ptr x)
	{
		while (x->left != nullptr)
		{
			x = x->left;
		}
		return (x);
	}
	template <typename b_node_ptr>
	b_node_ptr tree_max(b_node_ptr x)
	{
		while (x->right != nullptr)
		{
			x = x->right;
		}
		return (x);
	}
	template <typename b_node_ptr>
	bool isLeft(b_node_ptr node)
	{
		if (node != nullptr && node->parent != nullptr &&
		    node->parent->left == node)
			return (true);
		return (false);
	}
	template <typename b_node_ptr>
	bool isRight(b_node_ptr node)
	{
		if (node != nullptr && node->parent != nullptr &&
		    node->parent->right == node)
			return (true);
		return (false);
	}
	// inorder successor
	template <typename b_node_ptr>
	b_node_ptr nextNode(b_node_ptr node)
	{
		if (node->right != nullptr)
			return (tree_min(node->right));
		else
		{
			while (isRight(node) == true)
			{
				node = node->parent;
			}
			return (node->parent);
		}
	}
	template <typename b_node_ptr>
	b_node_ptr prevNode(b_node_ptr node)
	{
		if (node->left != nullptr)
			return (tree_max(node->left));
		else
		{
			while (isLeft(node) == true)
			{
				node = node->parent;
			}
			return (node->parent);
		}
	}
	template <typename b_node_ptr>
	int height(b_node_ptr x)
	{
		if (x == nullptr)
			return (-1);
		else
			return (std::max(height(x->left), height(x->right)) + 1);
	}
	/**************************************************************************/
	template <typename Y>
	bool operator==(const tree_iterator<Y> &x, const tree_const_iterator<Y> &y)
	{
		return (x.getNodePtr() == y.getNodePtr());
	}
	template <typename Y>
	bool operator!=(const tree_iterator<Y> &x, const tree_const_iterator<Y> &y)
	{
		return (!(x == y));
	}
	/**************************************************************************/

}  // namespace ft

#endif /* ifndef TREE_ITERATOR_HPP */
