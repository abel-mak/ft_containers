/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:31:32 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/02 18:20:36 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// /Library/Developer/CommandLineTools/usr/include/c++/v1/
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

#include "./type_traits.hpp"
#include "iterator.hpp"
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
	 * [x] size
	 * [x] max_size
	 * [] resize
	 * [x] capacity
	 * [] empty
	 * [] reserve
	 **
	 */
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
		const_iterator begin(void) const;
		const_iterator end(void) const;
		iterator begin(void);
		iterator end(void);
		const_reverse_iterator rbegin(void) const;
		const_reverse_iterator rend(void) const;
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
		size_type size(void) const;
		size_type max_size(void) const;
		size_type capacity(void) const;
		void reserve(size_type n);

	private:
		void vectorFree(void);
		void copyConstructRange(iterator first, iterator last, iterator target);
		void constructRange(iterator first, iterator last);
		pointer allocAndConstruct(const size_type &n);
		Allocator _alloc;
		pointer _begin;
		pointer _end;
		pointer _endAlloc;
	};
	template <typename T, typename A>
	vector<T, A>::vector(size_type n, const allocator_type &alloc)
	    : _alloc(alloc),
	      _begin(_alloc.allocate(n)),
	      _end(_begin + n),
	      _endAlloc(_end)
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
	    : _alloc(alloc), _begin(0), _end(0), _endAlloc(0)
	{
	}
	template <typename T, typename A>
	vector<T, A>::vector(typename vector<T, A>::size_type n,
	                     const vector<T, A>::value_type &val,
	                     const vector<T, A>::allocator_type &alloc)
	    : _alloc(alloc),
	      _begin(this->_alloc.allocate(n)),
	      _end(_begin + n),
	      _endAlloc(_end)
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
	      _endAlloc(_end)
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
	      _endAlloc(_end)
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
	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::begin(void)
	{
		typename vector<T, A>::iterator tmp(_begin);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::end(void)
	{
		typename vector<T, A>::iterator tmp(_end);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::const_reverse_iterator vector<T, A>::rbegin(
	    void) const
	{
		typename vector<T, A>::const_reverse_iterator tmp(_end - 1);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::const_reverse_iterator vector<T, A>::rend(void) const
	{
		typename vector<T, A>::const_reverse_iterator tmp(_begin - 1);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::reverse_iterator vector<T, A>::rbegin(void)
	{
		typename vector<T, A>::reverse_iterator tmp(_end - 1);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::reverse_iterator vector<T, A>::rend(void)
	{
		typename vector<T, A>::reverse_iterator tmp(_begin - 1);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::size_type vector<T, A>::max_size(void) const
	{
		return (_alloc.max_size());
	}
	template <typename T, typename A>
	typename vector<T, A>::size_type vector<T, A>::capacity(void) const
	{
		return (_endAlloc - _begin);
	}
	template <typename T, typename A>
	void vector<T, A>::vectorFree(void)
	{
		typename vector<T, A>::iterator tmp;

		tmp = this->begin();
		while (tmp != this->end())
		{
			_alloc.destroy(tmp.base());
			tmp++;
		}
		_alloc.deallocate((this->begin()).base(), this->size());
	}
	template <typename T, typename A>
	void vector<T, A>::copyConstructRange(const vector<T, A>::iterator first,
	                                      const vector<T, A>::iterator last,
	                                      const vector<T, A>::iterator target)
	{
		while (first != last)
		{
			_alloc.construct(target.base(), *first);
			first++;
			target++;
		}
	}
	template <typename T, typename A>
	void vector<T, A>::constructRange(const vector<T, A>::iterator first,
	                                  const vector<T, A>::iterator last)
	{
		while (first != last)
		{
			_alloc.construct(first.base());
			first++;
		}
	}
	template <typename T, typename A>
	typename vector<T, A>::pointer vector<T, A>::allocAndConstruct(
	    const vector<T, A>::size_type &n)
	{
		typename vector<T, A>::pointer tmp;
		int i;

		tmp = _alloc.allocate(n);
		i   = 0;
		while (i < n)
		{
			_alloc.construct(tmp);
			tmp++;
			i++;
		}
	}
	template <typename T, typename A>
	void vector<T, A>::reserve(typename vector<T, A>::size_type n)
	{
		if (n > this->capacity())
		{
			typename vector<T, A>::pointer tmpBegin = _alloc.allocate(n);
			typename vector<T, A>::iterator tmpIter(tmpBegin);
			typename vector<T, A>::size_type tmpSize = this->size();

			copyConstructRange(this->begin(), this->end(), tmpIter);
			// constructRange(vector<T, A>::iterator(tmpBegin + tmpSize),
			//             vector<T, A>::iterator(tmpBegin + n));
			this->vectorFree();
			_begin    = tmpBegin;
			_end      = _begin + tmpSize;
			_endAlloc = _begin + n;
		}
	}
}  // namespace ft

#endif /* VECTOR_HPP */
