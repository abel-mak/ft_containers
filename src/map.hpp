/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:20 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/11 20:18:22 by abel-mak         ###   ########.fr       */
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
	 * [x] constructor
	 *
	 **
	 * [x] empty
	 * [x] size
	 * [x] max_size
	 **
	 * [x] operator[]
	 **
	 * [x] insert
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
	 * [x] find
	 * 		iterator find (const key_type& k);
	 * 		const_iterator find (const key_type& k) const;
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
		typedef typename tree<key_type, mapped_type, key_compare,
		                      allocator_type>::node_ptr node_ptr;
		typedef typename tree<key_type, mapped_type, key_compare,
		                      allocator_type>::b_node_ptr b_node_ptr;
		typedef
		    typename tree<key_type, mapped_type, key_compare,
		                  allocator_type>::const_b_node_ptr const_b_node_ptr;
		typedef typename tree<key_type, mapped_type, key_compare,
		                      allocator_type>::const_node_ptr const_node_ptr;

	public:
		class value_compare : std::binary_function<value_type, value_type, bool>
		{
			friend class map<K, V, Comp, Alloc>;
			friend class tree<K, V, value_compare, Alloc>;

		protected:
			key_compare _comp;
			value_compare()
			{
			}
			value_compare(key_compare comp) : _comp(comp)
			{
			}

		public:
			bool operator()(key_type x, key_type y) const
			{
				return _comp(x, y);
			}
		};

	private:
		allocator_type _alloc;
		key_compare _comp;

	public:
		tree<key_type, mapped_type, value_compare, allocator_type> t;
		map();
		explicit map(const key_compare &comp,
		             const allocator_type &alloc = allocator_type());
		template <class II>
		map(II first, II last, const key_compare &comp = key_compare(),
		    const allocator_type &alloc = allocator_type());
		map(const map &src);
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
		iterator find(const key_type &k);
		const_iterator find(const key_type &k) const;
	};
	template <typename K, typename V, typename Comp, typename Alloc>
	map<K, V, Comp, Alloc>::map()
	{
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	map<K, V, Comp, Alloc>::map(const key_compare &comp,
	                            const allocator_type &alloc)
	    : t(value_compare(comp), alloc)
	{
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	template <typename II>
	map<K, V, Comp, Alloc>::map(II first, II second, const key_compare &comp,
	                            const allocator_type &alloc)
	    : t(first, second, value_compare(comp), alloc)
	{
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	map<K, V, Comp, Alloc>::map(const map &src) : t(src.t)
	{
	}
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
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::iterator map<K, V, Comp, Alloc>::find(
	    const key_type &k)
	{
		node_ptr endPtr;
		node_ptr x;

		endPtr = static_cast<node_ptr>((t.end()).getNodePtr());
		x      = t.findOrParent(k);
		if (endPtr != x && x->value.first == k)
		{
			return (iterator(x));
		}
		return (iterator(endPtr));
	}
	template <typename K, typename V, typename Comp, typename Alloc>
	typename map<K, V, Comp, Alloc>::const_iterator
	map<K, V, Comp, Alloc>::find(const key_type &k) const
	{
		const_b_node_ptr endPtr = ((t.end()).getNodePtr());
		const_b_node_ptr x      = t.findOrParent(k);

		if (endPtr != x && (static_cast<const_node_ptr>(x))->value.first == k)
			return (const_iterator(x));
		return (const_iterator(endPtr));
	}
}  // namespace ft

#endif
