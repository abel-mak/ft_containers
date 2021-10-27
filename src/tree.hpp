/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:48:31 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/27 19:22:22 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <string>

#include "tree_iterator.hpp"
#include "utility.hpp"

/*
 * left-left imbalanced do right rotation
 * right-right imbalced do left rotation
 * left-right do left rotation and then do
 * right-left do right and then left
 */

namespace ft
{
	template <typename K, typename V, typename Comp, typename Alloc>
	class tree
	{
	public:
		typedef pair<const K, V> value_type;
		typedef Comp value_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef tree_node<value_type> *node_ptr;
		typedef tree_iterator<value_type> iterator;

	private:
		tree_node<value_type> _rootParentNode;
		node_ptr _startNode;

	public:
		tree(void);
		allocator_type alloc;
		pair<iterator, bool> insert(const value_type &v);
		node_ptr find(K &k);
		node_ptr constructNode(const value_type &x);
		void balanceAfterInsert(node_ptr x);
		std::string getRotation(node_ptr x);
		void leftRotate(node_ptr x);
		void rightRotate(node_ptr x);
	};
	template <typename K, typename V, typename Comp, typename Alloc>
	tree<K, V, Comp, Alloc>::tree(void)
	{
		_rootParentNode.parent = nullptr;
		_rootParentNode.left   = nullptr;
		_rootParentNode.right  = nullptr;
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::node_ptr
	tree<K, V, Comp, Alloc>::constructNode(const value_type &x)
	{
		node_ptr newN;

		newN = alloc.allocate(1);
		alloc.construct(&newN->value, x);
		return (newN);
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	std::string tree<K, V, Comp, Alloc>::getRotation(node_ptr x)
	{
		int bf;
		std::string res = "";
		int i;

		i = 0;
		while (i < 2 && ((bf = height(x->right) - height(x->left) < -1) ||
		                 (bf = height(x->right) - height(x->left) > 1)))
		{
			if (bf > 1 || bf < -1)
			{
				if (bf < 0)
				{
					x = x->left;
					res += "l";
					// left heavy
				}
				else
				{
					x = x->right;
					res += "r";
					// right heavy
				}
			}
			i++;
		}
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	void tree<K, V, Comp, Alloc>::balanceAfterInsert(node_ptr x)
	{
		node_ptr child;
		node_ptr grandChild;

		while (x != &_rootParentNode)
		{
			x = x->parent;
		}
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	pair<typename tree<K, V, Comp, Alloc>::iterator, bool>
	tree<K, V, Comp, Alloc>::insert(const value_type &x)
	{
		K key;
		node_ptr child;
		node_ptr newN;
		pair<iterator, bool> res;

		key   = x.first;
		child = this->find(key);
		if (key != child->value.first)
		{
			newN         = constructNode(x);
			newN->parent = child;
			res.second   = true;
			if (key < child->value.first || child == &_rootParentNode)
			{
				child->left = newN;
				// insert to left of the child
			}
			else if (key > child->value.first)
			{
				child->right = newN;
				// insert to right of the child
			}
		}
		else
		{
			newN       = child;
			res.second = false;
			// the keys are equal return child
		}
		res.first = iterator(child);
		if (res.second == true)
			this->balance_after_insert(child);
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::node_ptr tree<K, V, Comp, Alloc>::find(
	    K &key)
	{
		if (_rootParentNode.left == 0)
			return (&_rootParentNode);
		node_ptr tmpRoot;
		node_ptr tmp;

		tmpRoot = _rootParentNode.left;
		tmp     = tmpRoot;
		while (tmp != nullptr)
		{
			if (key > tmp->value.first)
			{
				tmp = tmpRoot->right;
				if (tmp != nullptr)
					tmpRoot = tmp;
			}
			else if (key < tmp->value->first)
			{
				tmp = tmpRoot->left;
				if (tmp != nullptr)
					tmpRoot = tmp;
			}
			else
			{
				tmp = nullptr;
			}
		}
		return (tmpRoot);
	}
}  // namespace ft

#endif /* ifndef TREE_HPP */
