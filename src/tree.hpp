/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:48:31 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/25 19:04:27 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "tree_iterator.hpp"
#include "utility.hpp"

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
		pair<iterator, bool> insert(const value_type &v);
		node_ptr find(K &k);
	};
	template <typename K, typename V, typename Comp, typename Alloc>
	tree<K, V, Comp, Alloc>::tree(void)
	{
		_rootParentNode.parent = 0;
		_rootParentNode.left   = nullptr;
		_rootParentNode.right  = nullptr;
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	pair<typename tree<K, V, Comp, Alloc>::iterator, bool>
	tree<K, V, Comp, Alloc>::insert(const value_type &v)
	{
		K key = v.first;
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename tree<K, V, Comp, Alloc>::node_ptr tree<K, V, Comp, Alloc>::find(
	    K &k)
	{
		if (_rootParentNode.left == 0)
			return (nullptr);
		node_ptr root;

		root = _rootParentNode.left;
	}
}  // namespace ft

#endif /* ifndef TREE_HPP */
