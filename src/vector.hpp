/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:49 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/27 18:05:16 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

/// /Library/Developer/CommandLineTools/usr/include/c++/v1/
#include <iostream>
#include <iterator>

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
		explicit vector(size_type n, const value_type &val = value_type(),
		                const allocator_type &alloc = allocator_type());
		template <typename InputIterator>
		vector(InputIterator first, InputIterator last,
		       const allocator_type &alloc = allocator_type());
		vector(const vector &src);

	private:
		pointer *_begin;
		pointer *_end;
		pointer *endAlloc;
		Allocator alloc;
	};
	template <typename T, typename A>
	vector<T, A>::vector(const vector<T, A>::allocator_type &alloc)
	    : _begin(0), _end(0), endAlloc(0), alloc(alloc)
	{
	}
	template <typename T, typename A>
	vector<T, A>::vector(vector<T, A>::size_type n,
	                     const vector<T, A>::value_type &val,
	                     const vector<T, A>::allocator_type &alloc)
	    : _begin(alloc.allocate(n)),
	      _end(this->begin + n),
	      endAlloc(this->begin + n),
	      alloc(alloc)
	{
		(void)val;
	}
	template <typename T, typename A>
	template <typename InputIterator>
	vector<T, A>::vector(InputIterator first, InputIterator last,
	                     const vector<T, A>::allocator_type &alloc)
	{
		(void)first;
		(void)last;
		(void)alloc;
	}
}  // namespace ft

#endif /* MAIN_H */
