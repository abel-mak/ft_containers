/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:11:59 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/23 17:48:19 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

/*
 * iterator tags are used so that for example a function has different
 * implementation for each type of iterator, it will specify that in the
 * arguments like so void my_function (BidectionalIterator begin,
 * BidirectionalIterator end, std::bidirectional_iterator_tag) and whenever we
 * call this function we must specify the type of the iterator like so
 * my_function(begin, end, std::iterator_traits<Iterator>::iterator_category());
 */

namespace ft
{
	template <typename I>
	struct iterator_traits
	{
		typedef typename I::value_type value_type;
		typedef typename I::iterator_category iterator_category;
		typedef typename I::difference_type difference_type;
		typedef typename I::pointer pointer;
		typedef typename I::reference reference;
	};
	// specialization
	template <typename T>
	struct iterator_traits<T *>
	{
		typedef typename std::random_access_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
	};
	template <typename Category, typename T, typename Distance = std::ptrdiff_t,
	          typename Pointer = T *, typename Reference = T &>
	class iterator
	{
	public:
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};
	/**************************************************************************/
	template <typename P>
	class normal_iterator
	    : public iterator<typename iterator_traits<P>::iterator_category,
	                      typename iterator_traits<P>::value_type,
	                      typename iterator_traits<P>::difference_type,
	                      typename iterator_traits<P>::pointer,
	                      typename iterator_traits<P>::reference>
	{
	private:
		P current;

	public:
		normal_iterator(void);
		normal_iterator(P current);
		explicit normal_iterator(const normal_iterator &src);
		normal_iterator(normal_iterator &src);
		typename normal_iterator<P>::reference operator*();
		normal_iterator<P> &operator++(int);
		normal_iterator<P> operator++();
		normal_iterator<P> &operator--(int);
		normal_iterator<P> operator--();
		normal_iterator<P> &operator=(const normal_iterator &rhs);
		typename normal_iterator<P>::reference operator[](
		    const typename normal_iterator<P>::difference_type &n);
		normal_iterator<P> &operator+=(
		    const typename normal_iterator<P>::difference_type &n);
		normal_iterator<P> operator+(
		    const typename normal_iterator<P>::difference_type &n);
	};
	template <typename P>
	normal_iterator<P>::normal_iterator(P current) : current(current)
	{
	}
	template <typename P>
	normal_iterator<P>::normal_iterator(void)
	{
	}
	template <typename P>
	normal_iterator<P>::normal_iterator(const normal_iterator<P> &src)
	{
		*this = src;
	}
	template <typename P>
	normal_iterator<P>::normal_iterator(normal_iterator<P> &src)
	{
		*this = src;
	}
	template <typename P>
	normal_iterator<P> &normal_iterator<P>::operator++(int)
	{
		this->current++;
		return (*this);
	}
	template <typename P>
	typename normal_iterator<P>::reference normal_iterator<P>::operator*()
	{
		return (*(this->current));
	}
	template <typename P>
	normal_iterator<P> normal_iterator<P>::operator++()
	{
		normal_iterator<P> tmp(this->current);
		this->current++;
		return (tmp);
	}
	template <typename P>
	normal_iterator<P> &normal_iterator<P>::operator--(int)
	{
		this->current--;
		return (*this);
	}
	template <typename P>
	normal_iterator<P> normal_iterator<P>::operator--()
	{
		normal_iterator<P> tmp(this->current);
		this->current--;
		return (tmp);
	}
	template <typename P>
	normal_iterator<P> &normal_iterator<P>::operator+=(
	    const typename normal_iterator<P>::difference_type &n)
	{
		this->current += n;
		return (*this);
	}
	template <typename P>
	normal_iterator<P> normal_iterator<P>::operator+(
	    const typename normal_iterator<P>::difference_type &n)
	{
		normal_iterator<P> tmp(this->current + n);
		return (tmp);
	}
	template <typename P>
	normal_iterator<P> &normal_iterator<P>::operator=(
	    const normal_iterator<P> &rhs)
	{
		this->current = rhs.current;
		return (*this);
	}
	template <typename P>
	typename normal_iterator<P>::reference normal_iterator<P>::operator[](
	    const typename normal_iterator<P>::difference_type &n)
	{
		return this->current[n];
	}
	/**************************************************************************/
	template <typename I>
	class reverse_iterator
	    : public iterator<typename I::iterator_category, typename I::value_type,
	                      typename I::difference_type, typename I::pointer,
	                      typename I::reference>
	{
		typedef I iterator_type;
	};
}  // namespace ft

#endif /* ifsdef ITERATOR_HPP */
