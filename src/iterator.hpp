/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:11:59 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/19 15:40:07 by abel-mak         ###   ########.fr       */
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
}  // namespace ft

#endif /* ifsdef ITERATOR_HPP */
