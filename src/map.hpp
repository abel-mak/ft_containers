/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:20 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/09 18:55:29 by abel-mak         ###   ########.fr       */
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
	/*
	 * [x] iterator	begin ()
	 * [x] const_iterator begin () const
	 * [x] iterator	end ()
	 * [x] const_iterato rend () const
	 * [x] reverse_iterator	rbegin ()
	 * [x] const_reverse_iterator rbegin () const
	 * [x] reverse_iterator rend ()
	 * [x] const_reverse_iterator rend () const
	 **
	 * [x] empty
	 * [x] size
	 * [x] max_size
	 **
	 * [x] operator[]
	 **
	 * [] insert
	 * 		pair<iterator,bool> insert (const value_type& val);
	 * 		iterator insert (iterator position, const value_type& val);
	 * 		template <class InputIterator>
	 *      	void insert (InputIterator first, InputIterator last);
	 * [] erase
	 * [] swap
	 * [] clear
	 **
	 * [] key_comp
	 * [] value_comp
	 **
	 * [] find
	 * [] count
	 * [] lower_bound
	 * [] upper_bound
	 * [] equal_range
	 */
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
		allocator_type _alloc;
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
		bool empty(void) const;
		size_type size(void) const;
		size_type max_size(void) const;
		mapped_type &operator[](const key_type &k);
		pair<iterator, bool> insert(const value_type &val);
		iterator insert(iterator position, const value_type &val);
		template <typename II>
		void insert(II first, II last);
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
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::reverse_iterator
	map<K, V, Comp, Alloc>::rbegin(void)
	{
		return (const_reverse_iterator(this->end()));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::const_reverse_iterator
	map<K, V, Comp, Alloc>::rbegin(void) const
	{
		return (const_reverse_iterator(this->begin()));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	bool map<K, V, Comp, Alloc>::empty(void) const
	{
		return (t.size() == 0);
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::size_type map<K, V, Comp, Alloc>::size(
	    void) const
	{
		return (t.size());
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::size_type map<K, V, Comp, Alloc>::max_size(
	    void) const
	{
		return (t.max_size());
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::mapped_type &
	map<K, V, Comp, Alloc>::operator[](const key_type &k)
	{
		(*((this->insert(make_pair(k, mapped_type()))).first)).second;
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	ft::pair<typename map<K, V, Comp, Alloc>::iterator, bool>
	map<K, V, Comp, Alloc>::insert(const value_type &val)
	{
		return (t.insert(val));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::iterator map<K, V, Comp, Alloc>::insert(
	    iterator position, const value_type &val)
	{
		(void)position;
		return (t.insert(val));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	template <typename II>
	void map<K, V, Comp, Alloc>::insert(II first, II last)
	{
		while (first != last)
		{
			insert(*first);
			first++;
		}
	}
}  // namespace ft

#endif
