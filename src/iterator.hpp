/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:11:59 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/02 12:26:55 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
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
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};
	/**************************************************************************/
	/*
	 * __wrap_iter
	 * [] other constructors
	 * [x] operator++()
	 * [x] operator++(int)
	 * [x] operator--()
	 * [x] operator--(int)
	 * [x] operator*()
	 * [x] operator->()
	 * [x] operator+=()
	 * [x] operator+()
	 * [x] operator-=()
	 * [x] operator-()
	 * [x] base()
	 */
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
		typedef P iterator_type;
		typedef
		    typename iterator_traits<P>::iterator_category iterator_category;
		typedef typename iterator_traits<P>::value_type value_type;
		typedef typename iterator_traits<P>::difference_type difference_type;
		typedef typename iterator_traits<P>::pointer pointer;
		typedef typename iterator_traits<P>::reference reference;

		normal_iterator(void);
		normal_iterator(P current);
		normal_iterator(const normal_iterator &src);
		reference operator*();
		normal_iterator operator++(int);
		normal_iterator &operator++();
		normal_iterator operator--(int);
		normal_iterator &operator--();
		reference operator[](const difference_type &n);
		normal_iterator &operator+=(const difference_type &n);
		normal_iterator operator+(const difference_type &n) const;
		normal_iterator &operator-=(const difference_type &n);
		normal_iterator operator-(const difference_type &n) const;
		P base(void) const;
		pointer operator->();
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
		this->current = src.current;
	}
	template <typename P>
	normal_iterator<P> normal_iterator<P>::operator++(int)
	{
		normal_iterator<P> tmp(this->current);
		this->current++;
		return (tmp);
	}
	template <typename P>
	typename normal_iterator<P>::reference normal_iterator<P>::operator*()
	{
		return (*(this->current));
	}
	template <typename P>
	normal_iterator<P> &normal_iterator<P>::operator++()
	{
		this->current++;
		return (*this);
	}
	template <typename P>
	normal_iterator<P> normal_iterator<P>::operator--(int)
	{
		normal_iterator<P> tmp(this->current);
		this->current--;
		return (tmp);
	}
	template <typename P>
	normal_iterator<P> &normal_iterator<P>::operator--()
	{
		this->current--;
		return (*this);
	}
	template <typename P>
	typename normal_iterator<P>::reference normal_iterator<P>::operator[](
	    const typename normal_iterator<P>::difference_type &n)
	{
		return this->current[n];
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
	    const typename normal_iterator<P>::difference_type &n) const
	{
		normal_iterator<P> tmp(this->current + n);
		return (tmp);
	}
	template <typename P>
	normal_iterator<P> &normal_iterator<P>::operator-=(
	    const typename normal_iterator<P>::difference_type &n)
	{
		this->current -= n;
		return (*this);
	}
	template <typename P>
	normal_iterator<P> normal_iterator<P>::operator-(
	    const typename normal_iterator<P>::difference_type &n) const
	{
		normal_iterator<P> tmp(this->current - n);
		return (tmp);
	}
	template <typename P>
	typename normal_iterator<P>::pointer normal_iterator<P>::operator->()
	{
		return (this->current);
	}
	template <typename P>
	P normal_iterator<P>::base(void) const
	{
		return (this->current);
	}
	/**************************************************************************/
	/*
	 * reverse_iterator
	 * [x] constructor
	 * [x] operator=()
	 * [x] operator*()
	 * [x] operator->()
	 * [x] operator++()
	 * [x] operator++(int)
	 * [x] operator--()
	 * [x] operator--(int)
	 * [x] operator+=()
	 * [x] operator+()
	 * [x] operator-=()
	 * [x] operator-()
	 * [x] operator[]()
	 * [x] base()
	 */
	template <typename I>
	class reverse_iterator
	    : public iterator<typename iterator_traits<I>::iterator_category,
	                      typename iterator_traits<I>::value_type,
	                      typename iterator_traits<I>::difference_type,
	                      typename iterator_traits<I>::pointer,
	                      typename iterator_traits<I>::reference>
	{
	private:
		I current;

	public:
		typedef I iterator_type;
		typedef typename iterator_traits<I>::difference_type difference_type;
		typedef typename iterator_traits<I>::pointer pointer;
		typedef typename iterator_traits<I>::reference reference;

		reverse_iterator(void);
		explicit reverse_iterator(const I &tmp);
		reverse_iterator(const reverse_iterator &src);
		reverse_iterator &operator=(const reverse_iterator &rhs);
		reference operator*() const;
		pointer operator->() const;
		reverse_iterator &operator++();
		reverse_iterator operator++(int);
		reverse_iterator &operator--();
		reverse_iterator operator--(int);
		reverse_iterator operator+(const difference_type &n);
		reverse_iterator &operator+=(const difference_type &n);
		reverse_iterator operator-(const difference_type &n);
		reverse_iterator &operator-=(const difference_type &n);
		reference &operator[](const difference_type &n) const;
		I base(void) const;
	};
	template <typename I>
	reverse_iterator<I>::reverse_iterator(void)
	{
	}
	template <typename I>
	reverse_iterator<I>::reverse_iterator(const I &tmp) : current(tmp)
	{
	}
	template <typename I>
	reverse_iterator<I>::reverse_iterator(const reverse_iterator<I> &src)
	{
		*this = src;
	}
	template <typename I>
	reverse_iterator<I> &reverse_iterator<I>::operator=(
	    const reverse_iterator<I> &rhs)
	{
		this->current = rhs.current;
		return (*this);
	}
	template <typename I>
	typename reverse_iterator<I>::reference reverse_iterator<I>::operator*()
	    const
	{
		return (*this->current);
	}
	template <typename I>
	typename reverse_iterator<I>::pointer reverse_iterator<I>::operator->()
	    const
	{
		return (this->current);
	}
	template <typename I>
	reverse_iterator<I> &reverse_iterator<I>::operator++()
	{
		this->current--;
		return (*this);
	}
	template <typename I>
	reverse_iterator<I> reverse_iterator<I>::operator++(int)
	{
		reverse_iterator<I> tmp(this->current);
		this->current--;
		return (tmp);
	}
	template <typename I>
	reverse_iterator<I> &reverse_iterator<I>::operator--()
	{
		this->current++;
		return (*this);
	}
	template <typename I>
	reverse_iterator<I> reverse_iterator<I>::operator--(int)
	{
		reverse_iterator<I> tmp(this->current);
		this->current++;
		return (tmp);
	}
	template <typename I>
	reverse_iterator<I> reverse_iterator<I>::operator+(
	    const typename reverse_iterator<I>::difference_type &n)
	{
		reverse_iterator<I> tmp(this->current - n);
		return (tmp);
	}
	template <typename I>
	reverse_iterator<I> &reverse_iterator<I>::operator+=(
	    const typename reverse_iterator<I>::difference_type &n)
	{
		this->current -= n;
		return (*this);
	}
	template <typename I>
	reverse_iterator<I> reverse_iterator<I>::operator-(
	    const typename reverse_iterator<I>::difference_type &n)
	{
		reverse_iterator<I> tmp(this->current + n);
		return (tmp);
	}
	template <typename I>
	reverse_iterator<I> &reverse_iterator<I>::operator-=(
	    const typename reverse_iterator<I>::difference_type &n)
	{
		this->current += n;
		return (*this);
	}
	template <typename I>
	typename reverse_iterator<I>::reference &reverse_iterator<I>::operator[](
	    const reverse_iterator<I>::difference_type &n) const
	{
		return (this->current[n]);
	}
	template <typename I>
	I reverse_iterator<I>::base(void) const
	{
		return (this->current);
	}
	/**************************************************************************/
	/*
	 * comparaison for normal_iterator
	 * [x] operator==
	 * [x] operator!=
	 * [x] operator<
	 * [x] operator>
	 * [x] operator<=
	 * [x] operator>=
	 */
	template <typename P>
	bool operator==(const normal_iterator<P> &a, const normal_iterator<P> &b)
	{
		return (a.base() == b.base());
	}
	template <typename P>
	bool operator!=(const normal_iterator<P> &a, const normal_iterator<P> &b)
	{
		return (!(a == b));
	}
	template <typename P>
	bool operator<(const normal_iterator<P> &a, const normal_iterator<P> &b)
	{
		return (a.base() < b.base());
	}
	template <typename P>
	bool operator>(const normal_iterator<P> &a, const normal_iterator<P> &b)
	{
		return (!(a < b) && (a != b));
	}
	template <typename P>
	bool operator<=(const normal_iterator<P> &a, const normal_iterator<P> &b)
	{
		return (!(a > b));
	}
	template <typename P>
	bool operator>=(const normal_iterator<P> &a, const normal_iterator<P> &b)
	{
		return (!(a < b));
	}
	/**************************************************************************/
	/*
	 * comparaison for normal_iterator
	 * [x] operator==
	 * [x] operator!=
	 * [x] operator<
	 * [x] operator>
	 * [x] operator<=
	 * [x] operator>=
	 */
	template <typename I>
	bool operator==(const reverse_iterator<I> &a, const reverse_iterator<I> &b)
	{
		return (a.base() == b.base());
	}
	template <typename I>
	bool operator!=(const reverse_iterator<I> &a, const reverse_iterator<I> &b)
	{
		return (!(a == b));
	}
	template <typename I>
	bool operator<(const reverse_iterator<I> &a, const reverse_iterator<I> &b)
	{
		return (a.base() > b.base());
	}
	template <typename I>
	bool operator>(const reverse_iterator<I> &a, const reverse_iterator<I> &b)
	{
		return (!(a < b) && (a != b));
	}
	template <typename I>
	bool operator<=(const reverse_iterator<I> &a, const reverse_iterator<I> &b)
	{
		return (!(a > b));
	}
	template <typename I>
	bool operator>=(const reverse_iterator<I> &a, const reverse_iterator<I> &b)
	{
		return (!(a < b));
	}

}  // namespace ft

#endif /* ifsdef ITERATOR_HPP */
