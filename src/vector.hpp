/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:31:32 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/12 19:13:01 by abel-mak         ###   ########.fr       */
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
	 * [x] resize
	 * [x] capacity
	 * [x] empty
	 * [x] reserve
	 **
	 * [x] operator[]
	 * [x] at
	 * [x] front
	 * [x] back
	 **
	 * [x] assign
	 * [x] push_back
	 * [x] pop_back
	 * [x] insert
	 * [x] erase
	 * [] swap
	 * [x] clear
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
		~vector(void);
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
		bool empty(void) const;
		void resize(size_type n);
		void resize(size_type n, const_reference val);
		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		reference at(size_type n);
		const_reference at(size_type n) const;
		reference front(void);
		const_reference front(void) const;
		reference back(void);
		const_reference back(void) const;
		void push_back(const value_type &val);
		void pop_back(void);
		void clear(void);
		template <typename InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const value_type &val);
		iterator insert(iterator position, const_reference val);
		void insert(iterator position, size_type n, const_reference val);
		template <typename II>
		void insert(iterator position, II first, II last);
		iterator erase(const iterator position);
		iterator erase(const iterator first, const iterator last);
		void swap(vector &x);

	private:
		void vectorFree(void);
		template <typename II, typename OI>
		void copyConstructFromRange(
		    typename enable_if<!is_integral<II>::value, II>::type first,
		    II last, OI target);
		void constructRange(iterator first, iterator last);
		void copyConstructRange(iterator first, iterator last,
		                        const_reference val);
		pointer allocAndConstruct(const size_type &n);
		void __destroyEnd(pointer ptr);
		void __newAlloc(size_type n);
		void __rotate(size_type n);
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
	vector<T, A>::~vector<T, A>(void)
	{
		this->vectorFree();
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
		typename vector<T, A>::const_reverse_iterator tmp(_end);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::const_reverse_iterator vector<T, A>::rend(void) const
	{
		typename vector<T, A>::const_reverse_iterator tmp(_begin);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::reverse_iterator vector<T, A>::rbegin(void)
	{
		typename vector<T, A>::reverse_iterator tmp(_end);
		return (tmp);
	}
	template <typename T, typename A>
	typename vector<T, A>::reverse_iterator vector<T, A>::rend(void)
	{
		typename vector<T, A>::reverse_iterator tmp(_begin);
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
		typename vector<T, A>::iterator first;
		typename vector<T, A>::iterator last;

		first = this->begin();
		last  = this->end();
		while (first != last)
		{
			_alloc.destroy(first.base());
			first++;
		}
		_alloc.deallocate(_begin, this->size());
	}
	template <typename T, typename A>
	template <typename II, typename OI>
	void vector<T, A>::copyConstructFromRange(
	    typename enable_if<!is_integral<II>::value, II>::type first, II last,
	    OI target)
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
	void vector<T, A>::copyConstructRange(iterator first, iterator last,
	                                      const_reference val)
	{
		while (first != last)
		{
			_alloc.construct(first.base(), val);
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

			copyConstructFromRange(this->begin(), this->end(), tmpIter);
			// constructRange(vector<T, A>::iterator(tmpBegin + tmpSize),
			//             vector<T, A>::iterator(tmpBegin + n));
			this->vectorFree();
			_begin    = tmpBegin;
			_end      = _begin + tmpSize;
			_endAlloc = _begin + n;
		}
	}
	template <typename T, typename A>
	bool vector<T, A>::empty(void) const
	{
		return (this->size() == 0);
	}
	template <typename T, typename A>
	void vector<T, A>::resize(vector<T, A>::size_type n)
	{
		size_type i;

		if (n < this->size())
		{
			vector<T, A>::size_type diff = (this->size() - n);
			i                            = 0;
			while (i < diff)
			{
				_alloc.destroy(_end--);
				i++;
			}
		}
		else if (n > this->size())
		{
			size_type diff;

			diff = n - this->capacity();
			this->reserve(
			    std::max(2 * this->capacity(), n));  // modify the capacity
			iterator first(_end);
			iterator last(_end + diff);
			constructRange(first, last);
			_end = _end + diff;
		}
	}
	template <typename T, typename A>
	void vector<T, A>::resize(size_type n, const_reference val)
	{
		size_type i;

		if (n < this->size())
		{
			vector<T, A>::size_type diff = (this->size() - n);
			i                            = 0;
			while (i < diff)
			{
				_alloc.destroy(_end--);
				i++;
			}
		}
		else if (n > this->size())
		{
			size_type diff;

			diff = n - this->capacity();
			this->reserve(
			    std::max(2 * this->capacity(), n));  // modify the capacity
			iterator first(_end);
			iterator last(_end + diff);
			copyConstructRange(first, last, val);
			_end = _end + diff;
		}
	}
	template <typename T, typename A>
	typename vector<T, A>::reference vector<T, A>::operator[](
	    vector<T, A>::size_type n)
	{
		return (_begin[n]);
	}
	template <typename T, typename A>
	typename vector<T, A>::const_reference vector<T, A>::operator[](
	    vector<T, A>::size_type n) const
	{
		return (_begin[n]);
	}
	template <typename T, typename A>
	typename vector<T, A>::reference vector<T, A>::at(size_type n)
	{
		if (n < this->size())
			return (_begin[n]);
		else
			throw std::out_of_range("vector");
	}
	template <typename T, typename A>
	typename vector<T, A>::const_reference vector<T, A>::at(size_type n) const
	{
		if (n < this->size())
			return (_begin[n]);
		else
			throw std::out_of_range("vector");
	}
	template <typename T, typename A>
	typename vector<T, A>::reference vector<T, A>::front(void)
	{
		return (*_begin);
	}
	template <typename T, typename A>
	typename vector<T, A>::const_reference vector<T, A>::front(void) const
	{
		return (*_begin);
	}
	template <typename T, typename A>
	typename vector<T, A>::reference vector<T, A>::back(void)
	{
		return (*(_end - 1));
	}
	template <typename T, typename A>
	typename vector<T, A>::const_reference vector<T, A>::back(void) const
	{
		return (*(_end - 1));
	}
	template <typename T, typename A>
	void vector<T, A>::push_back(const value_type &val)
	{
		size_type nextCapacity;
		size_type curCapacity;
		size_type curSize;

		curSize     = this->size();
		curCapacity = this->capacity();
		if (this->capacity() - this->size() >= 1)
		{
			*(_end++) = val;
		}
		else
		{
			nextCapacity = (curCapacity == 0) ? 1 : curCapacity * 2;
			this->reserve(nextCapacity);
			_alloc.construct(_end++, val);
		}
	}
	template <typename T, typename A>
	void vector<T, A>::pop_back(void)
	{
		_alloc.destroy(--_end);
	}
	template <typename T, typename A>
	void vector<T, A>::clear(void)
	{
		while (_end != _begin)
		{
			_alloc.destroy(--_end);
		}
	}
	template <typename T, typename A>
	void vector<T, A>::__destroyEnd(pointer ptr)
	{
		pointer tmp;

		tmp = ptr;
		while (tmp != _end)
		{
			_alloc.destroy(tmp);
			tmp++;
		}
		_end = ptr;
	}
	template <typename T, typename A>
	template <typename Iterator>
	void vector<T, A>::assign(Iterator first, Iterator last)
	{
		size_type dist;
		typename ft::vector<value_type>::iterator tmp(_begin);

		dist = std::distance(first, last);
		if (dist <= this->capacity())
		{
			if (this->size() >= dist)
			{
				if (this->size() > dist)
					__destroyEnd(_begin + dist);
				std::copy(first, last, tmp);
			}
			else if (this->size() < dist)
			{
				std::copy(first, first + this->size(), _begin);
				copyConstructFromRange(first + this->size(), last,
				                       this->begin() + this->size());
				_end = _begin + dist;
			}
		}
		else
		{
			this->vectorFree();
			__newAlloc(dist);
			copyConstructFromRange(first + this->size(), last, this->begin());
		}
	}
	template <typename T, typename A>
	void vector<T, A>::__newAlloc(size_type n)
	{
		_begin    = _alloc.allocate(n);
		_end      = _begin + n;
		_endAlloc = _end;
	}
	template <typename T, typename A>
	void vector<T, A>::assign(size_type n, const value_type &val)
	{
		size_type i;
		size_type curSize;

		curSize = this->size();
		if (n <= this->capacity())
		{
			if (curSize >= n)
			{
				if (curSize > n)
					__destroyEnd(_begin + n);
				i = 0;
				while (i < n)
				{
					*(_begin + i) = val;
					i++;
				}
			}
			else if (curSize < n)
			{
				i = 0;
				while (i < this->size())
				{
					*(_begin + i) = val;
					i++;
				}
				copyConstructRange(this->begin() + curSize, this->begin() + n,
				                   val);
				_end = _begin + n;
			}
		}
		else
		{
			this->vectorFree();
			__newAlloc(n);
			copyConstructRange(this->begin(), this->end(), val);
		}
	}
	template <typename T, typename A>
	void vector<T, A>::__rotate(size_type n)
	{
		iterator first = this->begin();
		size_type i;
		size_type curSize;
		size_type count;
		value_type tmp;

		curSize = this->size();
		if (curSize > 1)
		{
			count = 0;
			while (count < n)
			{
				tmp = first[curSize - 1];
				i   = curSize - 1;
				while (i > 0)
				{
					first[i] = first[i - 1];
					i--;
				}
				first[0] = tmp;
				count++;
			}
		}
	}
	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::insert(iterator position,
	                                                     const_reference val)
	{
		size_type nextSize;
		size_type index;

		index = (position).base() - (this->begin()).base();
		if (index >= this->size())
			return;
		if (this->size() + 1 > this->capacity())
		{
			this->reserve(this->size() * 2);
		}
		nextSize = this->size();
		copyConstructRange(this->begin() + nextSize,
		                   this->begin() + nextSize + 1, val);
		_end++;
		this->__rotate(1 + index);
		return (position);
	}
	template <typename T, typename A>
	void vector<T, A>::insert(iterator position, size_type n,
	                          const_reference val)
	{
		size_type nextSize;
		size_type index;

		index = (position).base() - (this->begin()).base();
		if (index >= this->size())
			return;
		std::cout << "index: " << index << std::endl;
		if (this->size() + n > this->capacity())
		{
			this->reserve(std::max(this->size() * 2, this->size() + n));
		}
		nextSize = this->size();
		copyConstructRange(this->begin() + nextSize,
		                   this->begin() + nextSize + n, val);
		_end += n;
		this->__rotate(n + index);
	}
	template <typename T, typename A>
	template <typename II>
	void vector<T, A>::insert(iterator position, II first, II last)
	{
		size_type dist;
		size_type nextSize;
		size_type index;

		index = (position).base() - (this->begin()).base();
		if (index >= this->size())
			return;
		dist = std::distance(first, last);
		if (this->size() + dist > this->capacity())
		{
			this->reserve(std::max(this->size() * 2, this->size() + dist));
		}
		nextSize = this->size();
		copyConstructFromRange(first, last, this->end());
		_end += dist;
		this->__rotate(dist + 1);
	}
	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::erase(const iterator position)
	{
		pointer new_end;

		std::copy(position + 1, this->end(), position);
		new_end = _end - 1;
		__destroyEnd(new_end);
		return (position);
	}
	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::erase(const iterator first,
	                                                    const iterator last)
	{
		pointer new_end;

		std::copy(last, this->end(), first);
		new_end = _end - std::distance(first, last);
		__destroyEnd(new_end);
		return (first);
	}
	template <typename T, typename A>
	void vector<T, A>::swap(vector &x)
	{
		std::swap(this->_begin, x._begin);
		std::swap(this->_end, x._end);
		std::swap(this->_endAlloc, x._endAlloc);
	}
}  // namespace ft

#endif /* VECTOR_HPP */
