/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:48:31 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/19 15:34:27 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <string>

#include "../test/test_header.hpp"
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
		typedef K key_type;
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
		void copyTree(b_node_ptr root);
		void secondUpdateHeight(b_node_ptr x);
		int oOneHeight(b_node_ptr x);
		void checkImbalance(b_node_ptr x);
		void thirdUpdateHeight(b_node_ptr x);
		void balance(b_node_ptr x);
		std::string getRotationMem(b_node_ptr x);
		void updateHeightAfterBalance(b_node_ptr x, std::string &rot);

	public:
		tree(void);
		tree(tree const &src);
		~tree();
		tree(const value_type &vcomp,
		     const allocator_type &alloc = allocator_type());
		template <typename II>
		tree(II first, II last, const value_compare &vcomp = value_compare(),
		     const allocator_type &alloc = allocator_type());
		pair<iterator, bool> insert(const value_type &v);
		template <typename II>
		void insert(II first, II last);
		node_ptr getRoot(void);
		node_ptr getRoot(void) const;
		iterator begin(void);
		const_iterator begin(void) const;
		iterator end(void);
		const_iterator end(void) const;
		size_type size(void) const;
		void swap(tree &x);
		void clear(void);
		void erase(iterator position);
		size_type erase(const key_type &k);
		void erase(iterator first, iterator last);
		node_ptr findOrParent(const key_type &k);
		size_type count(const key_type &k) const;
		const_node_ptr findOrParent(const key_type &k) const;
		iterator upper_bound(const key_type &k);
		const_iterator upper_bound(const key_type &k) const;
		iterator lower_bound(const key_type &k);
		const_iterator lower_bound(const key_type &k) const;
		pair<const_iterator, const_iterator> equal_range(
		    const key_type &k) const;
		pair<iterator, iterator> equal_range(const key_type &k);
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
	typename tree<K, V, Vcomp, Alloc>::node_ptr
	tree<K, V, Vcomp, Alloc>::getRoot(void) const
	{
		if (_rootParentNode.left ==
		    static_cast<const_b_node_ptr>(&_rootParentNode))
			return (nullptr);
		return (static_cast<node_ptr>(_rootParentNode.left));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	tree<K, V, Vcomp, Alloc>::~tree()
	{
		this->clear();
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
		this->copyTree(src.getRoot());
		// this->insert(src.begin(), src.end());
		//  this->updateStartNode();
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
	void tree<K, V, Vcomp, Alloc>::copyTree(b_node_ptr root)
	{
		if (root == nullptr)
			return;
		if (root->left != nullptr)
			this->copyTree(root->left);
		this->insert((static_cast<node_ptr>(root))->value);
		if (root->right != nullptr)
			this->copyTree(root->right);
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
	template <typename b_node_ptr>
	std::string getRotation(b_node_ptr x)
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
	/*
	 * apply rotation for only the first imbalanced node and the break!!!
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	std::string tree<K, V, Vcomp, Alloc>::getRotationMem(b_node_ptr x)
	{
		int bf;
		std::string res = "";
		int i;

		i = 0;
		// the first iteration is to check for imbalacance
		// the second one is to see which side of the node is heavy
		while (i < 2 &&
		       ((bf = this->oOneHeight(static_cast<node_ptr>(x->right)) -
		              this->oOneHeight(static_cast<node_ptr>(x->left))) == -2 ||
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
	/*
	 * precondition x not a nullptr
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::balance(b_node_ptr x)
	{
		std::string rot;
		int i;

		i   = 0;
		rot = this->getRotationMem(x);
		if (rot != "")
		{
			applyRotation(x, rot);
			this->updateHeightAfterBalance(x, rot);
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
			{
				applyRotation(x, rot);
				break;
			}
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
	 *
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	int tree<K, V, Vcomp, Alloc>::oOneHeight(b_node_ptr x)
	{
		if (x == nullptr)
			return (-1);
		return ((static_cast<node_ptr>(x))->height);
	}
	/*
	 * precondition x is not a nullptr
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::updateHeightAfterBalance(b_node_ptr x,
	                                                        std::string &rot)
	{
		b_node_ptr tmp;

		static_cast<node_ptr>(x)->height =
		    std::max(oOneHeight(x->right), oOneHeight(x->left)) + 1;
		if (rot == "rl" || rot == "lr")
		{
			if (isLeft(x) == true)
			{
				tmp = x->parent->right;
			}
			else
			{
				tmp = x->parent->left;
			}
			if (tmp != nullptr)
				static_cast<node_ptr>(tmp)->height =
				    std::max(oOneHeight(tmp->right), oOneHeight(tmp->left)) + 1;
		}
		thirdUpdateHeight(x->parent);
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::secondUpdateHeight(b_node_ptr x)
	{
		node_ptr tmp;
		int height;

		height = 1;
		while (x != &_rootParentNode)
		{
			tmp = static_cast<node_ptr>(x);
			if (height > tmp->height)
				tmp->height = height++;
			else
				break;
			x = x->parent;
		}
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::thirdUpdateHeight(b_node_ptr x)
	{
		node_ptr tmp;

		while (x != &_rootParentNode)
		{
			tmp = static_cast<node_ptr>(x);
			tmp->height =
			    std::max(oOneHeight(x->right), oOneHeight(x->left)) + 1;
			x = x->parent;
		}
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::checkImbalance(b_node_ptr x)
	{
		int bf;

		bf = 0;
		while (x != &_rootParentNode)
		{
			bf = oOneHeight(x->right) + 1 - (oOneHeight(x->left) + 1);
			if (bf == 2 || bf == -2)
			{
				this->balance(x);
				break;
			}
			x = x->parent;
		}
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	pair<typename tree<K, V, Vcomp, Alloc>::iterator, bool>
	tree<K, V, Vcomp, Alloc>::insert(const value_type &x)
	{
		K key;
		node_ptr child;
		node_ptr newN;

		key   = x.first;
		child = this->findOrParent(key);
		if (child == &_rootParentNode || key != child->value.first)
		{
			newN         = constructNode(x);
			newN->parent = child;
			newN->height = 0;
			if (child != &_rootParentNode)
			{
				if (key < child->value.first)
					child->left = newN;
				else if (key > child->value.first)
					child->right = newN;
				this->secondUpdateHeight(child);
			}
			else
				child->left = newN;
			_size++;
			if (child == _startNode && isLeft(newN))
				_startNode = newN;
			checkImbalance(child);
			return (ft::pair<iterator, bool>(iterator(newN), true));
		}
		return (ft::pair<iterator, bool>(iterator(child), false));
	}
	/*
	 * find a node with this key if it exists else return postition where
	 * a node with this key should go
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::node_ptr
	tree<K, V, Vcomp, Alloc>::findOrParent(const key_type &key)
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
	tree<K, V, Vcomp, Alloc>::findOrParent(const key_type &key) const
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
		this->thirdUpdateHeight(x->parent);
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
	 * y will always be either a leaf node or node that has right child
	 */
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::replaceNode(b_node_ptr x, b_node_ptr y)
	{
		b_node_ptr yRight;

		yRight = y->right;
		if (isLeft(y) == true)
		{
			y->parent->left = nullptr;
		}
		else
		{
			y->parent->right = y->right;
		}
		y->left         = x->left;
		y->right        = x->right;
		y->parent       = x->parent;
		x->left->parent = y;
		if (x->right != nullptr)
			x->right->parent = y;
		if (isLeft(x) == true)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::erase(iterator position)
	{
		b_node_ptr x;
		b_node_ptr tmp;
		b_node_ptr xParent;

		x = position.getNodePtr();
		if (x == nullptr)
			return;
		xParent = x->parent;
		if (x->left != nullptr && x->right != nullptr)
		{
			tmp     = nextNode(x);
			xParent = tmp->parent;
			this->replaceNode(x, tmp);
			if (xParent != x)
				this->thirdUpdateHeight(nextNode(tmp));
			else
			{
				xParent = tmp;
				this->thirdUpdateHeight(tmp);
			}
			// erase(iterator(tmp));
			this->removeNode(x);
			_size--;
		}
		else if (x->left != nullptr && x->right == nullptr)
			SetChildBeforeEraseAndRemove(x, x->left);
		else if (x->right != nullptr && x->left == nullptr)
			SetChildBeforeEraseAndRemove(x, x->right);
		else
			SetChildBeforeEraseAndRemove(x, nullptr);
		// balanceAfterInsert(xParent,
		// static_cast<b_node_ptr>(&_rootParentNode));
		this->checkImbalance(xParent);
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	void tree<K, V, Vcomp, Alloc>::erase(iterator first, iterator last)
	{
		while (first != last)
		{
			erase(first);
			first++;
		}
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::size_type
	tree<K, V, Vcomp, Alloc>::erase(const key_type &k)
	{
		b_node_ptr x;

		x = this->findOrParent(k);
		if (x == &_rootParentNode || static_cast<node_ptr>(x)->value.first != k)
			return (0);
		erase(iterator(x));
		return (1);
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
	// return node with key or node with key bigger
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::iterator
	tree<K, V, Vcomp, Alloc>::lower_bound(const key_type &k)
	{
		b_node_ptr root;
		b_node_ptr res;

		res  = &_rootParentNode;
		root = this->getRoot();
		while (root != nullptr)
		{
			if (value_compare()(static_cast<node_ptr>(root)->value.first, k) ==
			    false)
			{
				res  = root;
				root = root->left;
			}
			else
				root = root->right;
		}
		return (iterator(res));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::const_iterator
	tree<K, V, Vcomp, Alloc>::lower_bound(const key_type &k) const
	{
		const_b_node_ptr root;
		const_b_node_ptr res;

		res  = &_rootParentNode;
		root = this->getRoot();
		while (root != nullptr)
		{
			if (value_compare()(static_cast<const_node_ptr>(root)->value.first,
			                    k) == false)
			{
				res  = root;
				root = root->left;
			}
			else
				root = root->right;
		}
		return (const_iterator(res));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::iterator
	tree<K, V, Vcomp, Alloc>::upper_bound(const key_type &k)
	{
		b_node_ptr root;
		b_node_ptr res;

		res  = &_rootParentNode;
		root = this->getRoot();
		while (root != nullptr)
		{
			if (value_compare()(k, static_cast<node_ptr>(root)->value.first))
			{
				res  = root;
				root = root->left;
			}
			else
				root = root->right;
		}
		return (iterator(res));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::const_iterator
	tree<K, V, Vcomp, Alloc>::upper_bound(const key_type &k) const
	{
		const_b_node_ptr root;
		const_b_node_ptr res;

		res  = &_rootParentNode;
		root = this->getRoot();
		while (root != nullptr)
		{
			if (value_compare()(k,
			                    static_cast<const_node_ptr>(root)->value.first))
			{
				res  = root;
				root = root->left;
			}
			else
				root = root->right;
		}
		return (const_iterator(res));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	typename tree<K, V, Vcomp, Alloc>::size_type
	tree<K, V, Vcomp, Alloc>::count(const key_type &k) const
	{
		const_b_node_ptr x;

		x = this->findOrParent(k);
		if (x == &_rootParentNode ||
		    static_cast<const_node_ptr>(x)->value.first != k)
			return (0);
		return (1);
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	pair<typename tree<K, V, Vcomp, Alloc>::iterator,
	     typename tree<K, V, Vcomp, Alloc>::iterator>
	tree<K, V, Vcomp, Alloc>::equal_range(const key_type &k)
	{
		b_node_ptr x;

		x = this->findOrParent(k);
		return (pair<iterator, iterator>(iterator(x), iterator(nextNode(x))));
	}
	template <typename K, typename V, typename Vcomp, typename Alloc>
	pair<typename tree<K, V, Vcomp, Alloc>::const_iterator,
	     typename tree<K, V, Vcomp, Alloc>::const_iterator>
	tree<K, V, Vcomp, Alloc>::equal_range(const key_type &k) const
	{
		const_b_node_ptr x;

		x = this->findOrParent(k);
		return (pair<const_iterator, const_iterator>(const_iterator(x),
		                                             const_iterator(x)));
	}
}  // namespace ft

#endif /* ifndef TREE_HPP */
