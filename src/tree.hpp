/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:48:31 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/04 18:46:52 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

//#include <iostream>
#include <string>

#include "tree_iterator.hpp"
#include "utility.hpp"

/*
 * left-left imbalanced do right rotation
 * right-right imbalced do left rotation
 * left-right do left rotation to child and then do right
 * right-left do right roation to child and then left
 */

/*
 * the _rootParentNode is end node, i got this idea from libc++ tree class
 * after i saw that my idea sucks the idea is to make parent node for root and
 * make the parent->left point to root, so this make it easy for insertion
 * deletion, and also when traversing the tree with iterator
 */

namespace ft
{
	template <typename K, typename V, typename Comp, typename Alloc>
	class tree
	{
	public:
		typedef pair<const K, V> value_type;
		typedef const pair<const K, V> const_value_type;
		typedef Comp value_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef tree_node<value_type> *node_ptr;
		typedef tree_node_base<void>::b_node_ptr b_node_ptr;
		typedef tree_node_base<void>::const_b_node_ptr const_b_node_ptr;
		typedef const node_ptr const_node_ptr;
		typedef tree_iterator<value_type> iterator;
		typedef tree_iterator<const_value_type> const_iterator;
		typedef std::allocator<tree_node<value_type> > node_allocator;

	private:
		tree_node<value_type> _rootParentNode;
		node_ptr _startNode;
		node_ptr constructNode(const value_type &x);
		std::string getRotation(node_ptr x);
		void removeNode(b_node_ptr x);
		void SetChildBeforeEraseAndRemove(b_node_ptr x, b_node_ptr child);
		void replaceNode(b_node_ptr x, b_node_ptr y);
		node_ptr cloneNode(node_ptr x);
		size_type _size;
		void updateSize(void);

	public:
		tree(void);
		allocator_type _alloc;
		node_allocator _nodeAlloc;
		pair<iterator, bool> insert(const value_type &v);
		node_ptr find(K &k);
		node_ptr getRoot(void);
		void erase(iterator position);
		iterator begin(void);
		const_iterator begin(void) const;
		iterator end(void);
		const_iterator end(void) const;
	};
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::node_ptr tree<K, V, Comp, Alloc>::getRoot(
	    void)
	{
		if (_rootParentNode.left == static_cast<b_node_ptr>(&_rootParentNode))
			return (nullptr);
		return (static_cast<node_ptr>(_rootParentNode.left));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	tree<K, V, Comp, Alloc>::tree(void) : _size(0)
	{
		_rootParentNode.parent = nullptr;
		_rootParentNode.left   = &_rootParentNode;
		_rootParentNode.right  = &_rootParentNode;
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::iterator tree<K, V, Comp, Alloc>::begin(
	    void)
	{
		return (iterator(tree_min(static_cast<b_node_ptr>(&_rootParentNode))));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::const_iterator
	tree<K, V, Comp, Alloc>::begin() const
	{
		return (iterator(tree_min(static_cast<b_node_ptr>(&_rootParentNode))));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::iterator tree<K, V, Comp, Alloc>::end(
	    void)
	{
		return (iterator(&_rootParentNode));
	}

	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::const_iterator
	tree<K, V, Comp, Alloc>::end(void) const
	{
		return (const_iterator(&_rootParentNode));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	void tree<K, V, Comp, Alloc>::updateSize(void)
	{
		size_type tmp;
		iterator first;

		first = this->begin();
		tmp   = 0;
		while (first != this->end())
		{
			first++;
			tmp++;
		}
		_size = tmp;
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::node_ptr
	tree<K, V, Comp, Alloc>::constructNode(const value_type &x)
	{
		node_ptr newN;

		newN = _nodeAlloc.allocate(1);
		// std::cout << "newN: " << newN << std::endl;
		_nodeAlloc.construct(newN, x);
		return (newN);
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	void tree<K, V, Comp, Alloc>::removeNode(b_node_ptr x)
	{
		_nodeAlloc.destroy(static_cast<node_ptr>(x));
		_nodeAlloc.deallocate(static_cast<node_ptr>(x), 1);
	}
	template <typename b_node_ptr>
	void rightRotate(b_node_ptr x)
	{
		b_node_ptr child;

		if (x->left == nullptr)
			return;
		child         = x->left;
		child->parent = x->parent;
		if (isRight(x) == true)
			x->parent->right = child;
		else
			x->parent->left = child;
		x->parent = child;
		x->left   = child->right;
		if (x->left != nullptr)
			x->left->parent = x;
		child->right = x;
	}
	template <typename b_node_ptr>
	void leftRotate(b_node_ptr x)
	{
		b_node_ptr child;

		if (x->right == nullptr)
			return;
		child         = x->right;
		child->parent = x->parent;
		if (isLeft(x) == true)
			x->parent->left = child;
		else
			x->parent->right = child;
		x->parent = child;
		x->right  = child->left;
		if (x->right != nullptr)
			x->right->parent = x;
		child->left = x;
	}
	template <typename node_ptr>
	std::string getRotation(node_ptr x)
	{
		int bf;
		std::string res = "";
		int i;

		i = 0;
		// the first iteration is to check for imbalacance
		// the second one is to see which side of the node is heavy
		while (i < 2 && ((bf = height(x->right) - height(x->left)) < -1 ||
		                 (bf > 1) || i == 1))
		{
			if (bf < 0)
			{
				x = x->left;
				res += "l";
			}
			else if (bf > 0)
			{
				x = x->right;
				res += "r";
			}
			else if (bf == 0 && res != "")
			{
				// this is just for second iteration
				res += res[0];
			}
			i++;
		}
		return (res);
	}
	template <typename b_node_ptr>
	void applyRotation(b_node_ptr x, std::string rot)
	{
		if (rot == "ll")
		{
			rightRotate(x);
		}
		else if (rot == "rr")
		{
			leftRotate(x);
		}
		else if (rot == "lr")
		{
			leftRotate(x->left);
			rightRotate(x);
		}
		else if (rot == "rl")
		{
			rightRotate(x->right);
			leftRotate(x);
		}
	}
	template <typename b_node_ptr>
	void balanceAfterInsert(b_node_ptr x, b_node_ptr _rootParentNodeAddress)
	{
		std::string rot;

		while (x != _rootParentNodeAddress)
		{
			rot = getRotation(x);
			if (rot != "")
				applyRotation(x, rot);
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
		if (child != &_rootParentNode && key != child->value.first)
		{
			newN         = constructNode(x);
			newN->parent = child;
			res.second   = true;
			if (key < child->value.first)
				child->left = newN;
			else if (key > child->value.first)
				child->right = newN;
		}
		else if (child == &_rootParentNode)
		{
			newN         = constructNode(x);
			newN->parent = child;
			child->left  = newN;
			res.second   = true;
		}
		else
		{
			newN       = child;
			res.second = false;
			// the keys are equal return child
		}
		res.first = iterator(newN);
		if (res.second == true)
		{
			balanceAfterInsert(static_cast<b_node_ptr>(child),
			                   static_cast<b_node_ptr>(&_rootParentNode));
		}
		return (res);
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::node_ptr tree<K, V, Comp, Alloc>::find(
	    K &key)
	{
		if (_rootParentNode.left == static_cast<b_node_ptr>(&_rootParentNode))
			return (&_rootParentNode);
		b_node_ptr tmpRoot;
		b_node_ptr tmp;

		tmpRoot = _rootParentNode.left;
		tmp     = tmpRoot;
		while (tmp != nullptr)
		{
			if (value_compare()(
			        key, (static_cast<node_ptr>(tmp))->value.first) == false)
			{
				tmp = tmpRoot->right;
				if (tmp != nullptr)
					tmpRoot = tmp;
			}
			else if (value_compare()(
			             key, (static_cast<node_ptr>(tmp))->value.first) ==
			         true)
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
		this->updateSize();
		return (static_cast<node_ptr>(tmpRoot));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	void tree<K, V, Comp, Alloc>::SetChildBeforeEraseAndRemove(b_node_ptr x,
	                                                           b_node_ptr child)
	{
		if (isRight(x) == true)
			x->parent->right = child;
		else
			x->parent->left = child;
		if (child != nullptr)
			child->parent = x->parent;
		this->removeNode(x);
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::node_ptr
	tree<K, V, Comp, Alloc>::cloneNode(node_ptr x)
	{
		node_ptr newN;

		newN = constructNode(x->value);
		return (newN);
	}
	/*
	 * precondition x->left != nullptr && x->right != nullptr
	 */
	template <typename K, typename V, typename Comp, typename Alloc>
	void tree<K, V, Comp, Alloc>::replaceNode(b_node_ptr x, b_node_ptr y)
	{
		b_node_ptr newN;

		newN             = this->cloneNode(static_cast<node_ptr>(y));
		newN->left       = x->left;
		newN->right      = x->right;
		newN->parent     = x->parent;
		x->left->parent  = newN;
		x->right->parent = newN;
		if (isLeft(x) == true)
			x->parent->left = newN;
		else
			x->parent->right = newN;
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	void tree<K, V, Comp, Alloc>::erase(iterator position)
	{
		b_node_ptr x;
		b_node_ptr tmp;

		x = position._node;
		if (x == nullptr)
			return;
		if (x->left != nullptr && x->right != nullptr)
		{
			tmp = nextNode(x);
			this->replaceNode(x, tmp);
			erase(iterator(tmp));
			this->removeNode(x);
			return;
			// create clone to tmp and replace it with with x
			// delete x and delete tmp
		}
		else if (x->left != nullptr && x->right == nullptr)
			SetChildBeforeEraseAndRemove(x, x->left);
		else if (x->right != nullptr && x->left == nullptr)
			SetChildBeforeEraseAndRemove(x, x->right);
		else
			SetChildBeforeEraseAndRemove(x, nullptr);
		balanceAfterInsert((this->begin())._node,
		                   static_cast<b_node_ptr>(&_rootParentNode));
		this->updateSize();
	}
}  // namespace ft

#endif /* ifndef TREE_HPP */
