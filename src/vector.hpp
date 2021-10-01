/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:31:32 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/01 17:55:52 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// /Library/Developer/CommandLineTools/usr/include/c++/v1/
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iterator>

#include "./type_traits.hpp"
#include "iterator.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::size_type size_type;
		typedef typename Allocator::difference_type difference_type;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef normal_iterator<pointer> iterator;
		typedef normal_iterator<const_pointer> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		explicit vector(const allocator_type &alloc = allocator_type());
		explicit vector(size_type n,
		                const allocator_type &alloc = allocator_type());
		vector(size_type n, const value_type &val,
		       const allocator_type &alloc = allocator_type());
		template <typename InputIterator>
		vector(typename enable_if<!is_integral<InputIterator>::value,
		                          InputIterator>::type first,
		       InputIterator last,
		       const allocator_type &alloc = allocator_type());
		vector(const vector &src);
		size_type size(void) const;
		const_iterator begin(void) const;
		const_iterator end(void) const;

	private:
		Allocator _alloc;
		pointer _begin;
		pointer _end;
		pointer endAlloc;
	};
	template <typename T, typename A>
	vector<T, A>::vector(size_type n, const allocator_type &alloc)
	    : _alloc(alloc),
	      _begin(_alloc.allocate(n)),
	      _end(_begin + n),
	      endAlloc(_end)
	{
		vector<T, A>::size_type i;

		i = 0;
		while (i < n)
		{
			this->_alloc.construct(_begin + i);
			i++;
		}
	}
	template <typename T, typename A>
	vector<T, A>::vector(const vector<T, A>::allocator_type &alloc)
	    : _alloc(alloc), _begin(0), _end(0), endAlloc(0)
	{
	}
	template <typename T, typename A>
	vector<T, A>::vector(typename vector<T, A>::size_type n,
	                     const vector<T, A>::value_type &val,
	                     const vector<T, A>::allocator_type &alloc)
	    : _alloc(alloc),
	      _begin(this->_alloc.allocate(n)),
	      _end(_begin + n),
	      endAlloc(_end)
	{
		vector<T, A>::size_type i;

		i = 0;
		while (i < n)
		{
			this->_alloc.construct(_begin + i, val);
			i++;
		}
	}
	// enable_if Check whether it's an integral type.  If so, it's not an
	// iterator.
	template <typename T, typename A>
	template <typename InputIterator>
	vector<T, A>::vector(typename enable_if<!is_integral<InputIterator>::value,
	                                        InputIterator>::type first,
	                     InputIterator last,
	                     const vector<T, A>::allocator_type &alloc)
	    : _alloc(alloc),
	      _begin(_alloc.allocate(std::distance(first, last))),
	      _end(_begin + std::distance(first, last)),
	      endAlloc(_end)
	{
		pointer tmp;

		tmp = _begin;
		while (first != last)
		{
			this->_alloc.construct(tmp, *first);
			tmp++;
			first++;
		}
	}
	template <typename T, typename A>
	vector<T, A>::vector(const vector<T, A> &src)
	    : _begin(_alloc.allocate(src.size())),
	      _end(_begin + src.size()),
	      endAlloc(_end)
	{
		int i;
		const_iterator first = src.begin();
		const_iterator last  = src.end();

		i = 0;
		while (first != last)
		{
			_alloc.construct(_begin + i, *first);
			first++;
			i++;
		}
	}
	template <typename T, typename A>
	typename vector<T, A>::size_type vector<T, A>::size(void) const
	{
		return (_end - _begin);
	}
	template <typename T, typename A>
	typename vector<T, A>::const_iterator vector<T, A>::begin(void) const
	{
		typename vector<T, A>::const_iterator tmp(_begin);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::const_iterator vector<T, A>::end(void) const
	{
		typename vector<T, A>::const_iterator tmp(_end);
		return (tmp);
	}
}  // namespace ft

#endif /* VECTOR_HPP */
