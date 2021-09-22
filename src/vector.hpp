/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:49 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/22 17:36:56 by abel-mak         ###   ########.fr       */
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
		class test
		{
		public:
			int a;
			int b;
		};

		// class iterator : public std::iterator<>
		//{
		//};

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
		vector(void);
		vector(const vector &src);
		virtual ~vector(void);
		vector(size_t n, T const value);
		vector(size_t n);
		void hello(void);
		void fill(T value);
		value_type &operator[](size_t pos);
		size_t size(void);
		size_t capacity(void);
		iterator begin(void);

	private:
		value_type *ptr;
		size_t sizeVar;
		size_t capacityVar;
		Allocator al;
	};
	template <typename T, typename Allocator>
	void vector<T, Allocator>::hello(void)
	{
		std::cout << "hello world!" << std::endl;
	}
	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(void) : ptr(0)
	{
		ptr    = al.allocate(4);
		ptr[0] = 1;
		ptr[1] = 3;
		ptr[2] = 3;
		ptr[3] = 7;
	}
	template <typename T, typename Allocator>
	vector<T, Allocator>::~vector(void)
	{
		std::cout << "vector destructor called" << std::endl;
	}
	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(size_t n, T const value)
	    : ptr(0), sizeVar(0), capacityVar(0)
	{
		sizeVar     = n;
		capacityVar = n;
		// while (capacityVar < sizeVar)
		//{
		//	if (capacityVar == 0)
		//		capacityVar = 2;
		//	else
		//		capacityVar = capacityVar * 2;
		//}
		ptr = al.Allocatorate(n);
		this->fill(value);
	}
	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(size_t n) : ptr(0), sizeVar(0), capacityVar(0)
	{
		sizeVar     = n;
		capacityVar = n;
		// while (capacityVar < sizeVar)
		//{
		//	if (capacityVar == 0)
		//		capacityVar = 2;
		//	else
		//		capacityVar = capacityVar * 2;
		//}
		ptr = al.Allocatorate(n);
		this->fill(T());
	}
	template <typename T, typename Allocator>
	void vector<T, Allocator>::fill(T value)
	{
		int i;

		i = 0;
		while (static_cast<size_t>(i) < sizeVar)
		{
			ptr[i] = value;
			i++;
		}
	}
	template <typename T, typename Allocator>
	T &vector<T, Allocator>::operator[](size_t pos)
	{
		return (ptr[pos]);
	}
	template <typename T, typename Allocator>
	size_t vector<T, Allocator>::size(void)
	{
		return (this->sizeVar);
	}
	template <typename T, typename Allocator>
	size_t vector<T, Allocator>::capacity(void)
	{
		return (this->capacityVar);
	}
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::begin(void)
	{
		vector<T, Allocator>::iterator i(this->ptr);
		return i;
	}
}  // namespace ft

#endif /* MAIN_H */
