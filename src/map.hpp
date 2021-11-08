/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:20 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/08 19:20:46 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

#include "iterator.hpp"
#include "tree.hpp"
#include "tree_iterator.hpp"

namespace ft
{
	template <typename K, typename V, typename Comp = std::less<K>,
	          typename Alloc = std::allocator<ft::pair<const K, V> > >
	class map
	{
	public:
		typedef K key_type;
		typedef V mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Comp key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef tree_iterator<value_type> iterator;
		typedef tree_const_iterator<value_type> const_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		tree<key_type, mapped_type, key_compare, allocator_type> t;

	public:
		iterator begin(void);
		const_iterator begin(void) const;
		iterator end(void);
		const_iterator end(void) const;
		reverse_iterator rbegin(void);
		const_reverse_iterator rbegin(void) const;
		reverse_iterator rend();
		const_reverse_iterator rend(void) const;
	};
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::iterator map<K, V, Comp, Alloc>::begin(
	    void)
	{
		return (t.begin());
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::const_iterator
	map<K, V, Comp, Alloc>::begin(void) const
	{
		return (t.begin());
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::iterator map<K, V, Comp, Alloc>::end(void)
	{
		return (t.end());
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::const_iterator map<K, V, Comp, Alloc>::end(
	    void) const
	{
		return (t.end());
	}
}  // namespace ft

#endif
