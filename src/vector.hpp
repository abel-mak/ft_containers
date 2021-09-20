/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:49 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/18 16:59:19 by abel-mak         ###   ########.fr       */
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
	template <typename T>
	class vector
	{
		typedef T value_type;
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

	private:
		value_type *ptr;
		size_t sizeVar;
		size_t capacityVar;
		std::allocator<T> alloc;
	};
	template <typename T>
	void vector<T>::hello(void)
	{
		std::cout << "hello world!" << std::endl;
	}
	template <typename T>
	vector<T>::vector(void) : ptr(0)
	{
	}
	template <typename T>
	vector<T>::~vector(void)
	{
		std::cout << "vector destructor called" << std::endl;
	}
	template <typename T>
	vector<T>::vector(size_t n, T const value)
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
		ptr = alloc.allocate(n);
		this->fill(value);
	}
	template <typename T>
	vector<T>::vector(size_t n) : ptr(0), sizeVar(0), capacityVar(0)
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
		ptr = alloc.allocate(n);
		this->fill(T());
	}
	template <typename T>
	void vector<T>::fill(T value)
	{
		int i;

		i = 0;
		while (static_cast<size_t>(i) < sizeVar)
		{
			ptr[i] = value;
			i++;
		}
	}
	template <typename T>
	T &vector<T>::operator[](size_t pos)
	{
		return (ptr[pos]);
	}
	template <typename T>
	size_t vector<T>::size(void)
	{
		return (this->sizeVar);
	}
	template <typename T>
	size_t vector<T>::capacity(void)
	{
		return (this->capacityVar);
	}
}  // namespace ft

#endif /* MAIN_H */
