/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:48:31 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/12 19:40:17 by abel-mak         ###   ########.fr       */
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
	template <typename K, typename V, typename Vcomp, typename Alloc>
	class tree
	{
	public:
		typedef pair<const K, V> value_type;
		typedef const pair<const K, V> const_value_type;
		typedef Vcomp value_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef tree_node<value_type> *node_ptr;
		typedef tree_node_base<void>::b_node_ptr b_node_ptr;
		typedef tree_node_base<void>::const_b_node_ptr const_b_node_ptr;
		typedef const tree_node<value_type> *const_node_ptr;
		typedef tree_iterator<value_type> iterator;
		typedef tree_const_iterator<value_type> const_iterator;
		typedef std::allocator<tree_node<value_type> > node_allocator;

	private:
		value_compare _vcomp;
		allocator_type _alloc;
		node_allocator _nodeAlloc;
		tree_node<value_type> _rootParentNode;
		b_node_ptr _startNode;
		size_type _size;
		node_ptr constructNode(const value_type &x);
		std::string getRotation(node_ptr x);
		void removeNode(b_node_ptr x);
		void SetChildBeforeEraseAndRemove(b_node_ptr x, b_node_ptr child);
		void replaceNode(b_node_ptr x, b_node_ptr y);
		node_ptr cloneNode(node_ptr x);
		void updateStartNode(void);
		void destroyTree(b_node_ptr root);

	public:
		tree(void);
		tree(tree const &src);
		tree(const value_type &vcomp,
		     const allocator_type &alloc = allocator_type());
		template <typename II>
		tree(II first, II last, const value_compare &vcomp = value_compare(),
		     const allocator_type &alloc = allocator_type());
		pair<iterator, bool> insert(const value_type &v);

		template <typename II>
		void insert(II first, II last);
		node_ptr getRoot(void);
		void erase(iterator position);
		iterator begin(void);
		const_iterator begin(void) const;
		iterator end(void);
		const_iterator end(void) const;
		size_type size(void) const;
		void swap(tree &x);
		void clear(void);
		node_ptr findOrParent(const K &k);
		const_node_ptr findOrParent(const K &k) const;
		// iterator find(const K &k);
	};
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::node_ptr
	tree<K, V, Vcomp, Alloc>::getRoot(void)
	{
		if (_rootParentNode.left == static_cast<b_node_ptr>(&_rootParentNode))
			return (nullptr);
		return (static_cast<node_ptr>(_rootParentNode.left));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	tree<K, V, Vcomp, Alloc>::tree(void)
	    : _startNode(static_cast<b_node_ptr>(&_rootParentNode)), _size(0)
	{
		_rootParentNode.parent = nullptr;
		_rootParentNode.left   = &_rootParentNode;
		_rootParentNode.right  = &_rootParentNode;
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	tree<K, V, Vcomp, Alloc>::tree(const value_type &vcomp,
	                               const allocator_type &alloc)
	    : _vcomp(vcomp),
	      _alloc(alloc),
	      _startNode(static_cast<b_node_ptr>(&_rootParentNode)),
	      _size(0)
	{
		_rootParentNode.parent = nullptr;
		_rootParentNode.left   = &_rootParentNode;
		_rootParentNode.right  = &_rootParentNode;
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	template <typename II>
	tree<K, V, Vcomp, Alloc>::tree(II first, II last,
	                               const value_compare &vcomp,
	                               const allocator_type &alloc)
	    : _vcomp(vcomp),
	      _alloc(alloc),
	      _startNode(static_cast<b_node_ptr>(&_rootParentNode)),
	      _size(0)
	{
		_rootParentNode.parent = nullptr;
		_rootParentNode.left   = &_rootParentNode;
		_rootParentNode.right  = &_rootParentNode;
		this->insert(first, last);
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	tree<K, V, Vcomp, Alloc>::tree(tree const &src)
	    : _startNode(static_cast<b_node_ptr>(&_rootParentNode)), _size(0)
	{
		_rootParentNode.parent = nullptr;
		_rootParentNode.left   = &_rootParentNode;
		_rootParentNode.right  = &_rootParentNode;
		this->insert(src.begin(), src.end());
		this->updateStartNode();
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::iterator tree<K, V, Vcomp, Alloc>::begin(
	    void)
	{
		return (iterator(_startNode));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::const_iterator
	tree<K, V, Vcomp, Alloc>::begin() const
	{
		return (const_iterator(_startNode));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::iterator tree<K, V, Vcomp, Alloc>::end(
	    void)
	{
		return (iterator(&_rootParentNode));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::const_iterator
	tree<K, V, Vcomp, Alloc>::end(void) const
	{
		return (const_iterator(&_rootParentNode));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::size_type tree<K, V, Vcomp, Alloc>::size(
	    void) const
	{
		return (_size);
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::swap(tree &x)
	{
		if (_rootParentNode.left == &_rootParentNode &&
		    (x._rootParentNode.left != &(x._rootParentNode)))
		{
			_rootParentNode.left   = x._rootParentNode.left;
			_startNode             = x._startNode;
			x._rootParentNode.left = &(x._rootParentNode);
			x._startNode           = &(x._rootParentNode);
		}
		else if ((x._rootParentNode.left == &(x._rootParentNode)) &&
		         _rootParentNode.left != &_rootParentNode)
		{
			x._rootParentNode.left = _rootParentNode.left;
			x._startNode           = _startNode;
			_rootParentNode.left   = &_rootParentNode;
			_startNode             = &_rootParentNode;
		}
		else
		{
			std::swap(_rootParentNode.left, x._rootParentNode.left);
			std::swap(_startNode, x._startNode);
		}
		std::swap(_size, x._size);
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::updateStartNode(void)
	{
		if (_rootParentNode.left != &_rootParentNode)
			_startNode = tree_min(static_cast<b_node_ptr>(&_rootParentNode));
		else
			_startNode = &_rootParentNode;
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::node_ptr
	tree<K, V, Vcomp, Alloc>::constructNode(const value_type &x)
	{
		node_ptr newN;

		newN = _nodeAlloc.allocate(1);
		// std::cout << "newN: " << newN << std::endl;
		_nodeAlloc.construct(newN, x);
		return (newN);
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::removeNode(b_node_ptr x)
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
		while (i < 2 && ((bf = height(x->right) - height(x->left)) == -2 ||
		                 (bf == 2) || i == 1))
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
		int i;

		i = 0;
		while (x != _rootParentNodeAddress)
		{
			rot = getRotation(x);
			if (rot != "")
				applyRotation(x, rot);
			x = x->parent;
		}
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	template <typename II>
	void tree<K, V, Vcomp, Alloc>::insert(II first, II last)
	{
		while (first != last)
		{
			this->insert(*first);
			first++;
		}
	}
	/*
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	pair<typename tree<K, V, Vcomp, Alloc>::iterator, bool>
	tree<K, V, Vcomp, Alloc>::insert(const value_type &x)
	{
		K key;
		node_ptr child;
		node_ptr newN;
		pair<iterator, bool> res;

		key   = x.first;
		child = this->findOrParent(key);
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
			_size++;
			// this->updateStartNode();
			if (child == _startNode && isLeft(newN))
				_startNode = newN;
			balanceAfterInsert(static_cast<b_node_ptr>(child),
			                   static_cast<b_node_ptr>(&_rootParentNode));
		}
		return (res);
	}
	/*
	 * find a node key if it exists else postition where a node with this key
	 * should go
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::node_ptr
	tree<K, V, Vcomp, Alloc>::findOrParent(const K &key)
	{
		if (_rootParentNode.left == static_cast<b_node_ptr>(&_rootParentNode))
			return (&_rootParentNode);
		b_node_ptr tmpRoot;
		b_node_ptr tmp;

		tmpRoot = _rootParentNode.left;
		tmp     = tmpRoot;
		while (tmp != nullptr)
		{
			if (_vcomp((static_cast<node_ptr>(tmp))->value.first, key) == true)
			{
				tmp = tmpRoot->right;
				if (tmp != nullptr)
					tmpRoot = tmp;
			}
			else if (_vcomp(key, (static_cast<node_ptr>(tmp))->value.first) ==
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
		return (static_cast<node_ptr>(tmpRoot));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::const_node_ptr
	tree<K, V, Vcomp, Alloc>::findOrParent(const K &key) const
	{
		if (_rootParentNode.left ==
		    static_cast<const_b_node_ptr>(&_rootParentNode))
			return (static_cast<const_node_ptr>(&_rootParentNode));
		b_node_ptr tmpRoot;
		b_node_ptr tmp;

		tmpRoot = _rootParentNode.left;
		tmp     = tmpRoot;
		while (tmp != nullptr)
		{
			if (_vcomp((static_cast<node_ptr>(tmp))->value.first, key) == true)
			{
				tmp = tmpRoot->right;
				if (tmp != nullptr)
					tmpRoot = tmp;
			}
			else if (_vcomp(key, (static_cast<node_ptr>(tmp))->value.first) ==
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
		return (static_cast<const_node_ptr>(tmpRoot));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::SetChildBeforeEraseAndRemove(
	    b_node_ptr x, b_node_ptr child)
	{
		if (isRight(x) == true)
			x->parent->right = child;
		else
			x->parent->left = child;
		if (child != nullptr)
			child->parent = x->parent;
		this->removeNode(x);
		this->updateStartNode();
		_size--;
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::node_ptr
	tree<K, V, Vcomp, Alloc>::cloneNode(node_ptr x)
	{
		node_ptr newN;

		newN = constructNode(x->value);
		return (newN);
	}
	/*
	 * precondition x->left != nullptr && x->right != nullptr
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::replaceNode(b_node_ptr x, b_node_ptr y)
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
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::erase(iterator position)
	{
		b_node_ptr x;
		b_node_ptr tmp;
		b_node_ptr xParent;

		x       = position.getNodePtr();
		xParent = x->parent;
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
		balanceAfterInsert(xParent, static_cast<b_node_ptr>(&_rootParentNode));
	}
	// post-order traversal
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::destroyTree(b_node_ptr root)
	{
		if (root != nullptr && root->left != nullptr)
			destroyTree(root->left);
		if (root != nullptr && root->right != nullptr)
			destroyTree(root->right);
		if (root != nullptr)
			this->removeNode(root);
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::clear(void)
	{
		if (_rootParentNode.left != &_rootParentNode)
		{
			this->destroyTree(_rootParentNode.left);
			_rootParentNode.left = &_rootParentNode;
			this->updateStartNode();
			_size = 0;
		}
	}
}  // namespace ft

#endif /* ifndef TREE_HPP */
