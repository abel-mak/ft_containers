/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:27:08 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/20 18:11:14 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

	public:
		first_type first;
		second_type second;
		pair &operator=(const pair &rhs);
		pair(const pair &src);
		pair(void);
		pair(const T1 &a, const T2 &b);
	};

	template <typename T1, typename T2>
	pair<T1, T2>::pair(void) : first(0), second(0)
	{
	}
	template <typename T1, typename T2>
	pair<T1, T2> &pair<T1, T2>::operator=(const pair<T1, T2> &rhs)
	{
		this->first  = rhs.first;
		this->second = rhs.second;
		return (*this);
	}
	template <typename T1, typename T2>
	pair<T1, T2>::pair(const pair<T1, T2> &src)
	{
		*this = src;
	}
	template <typename T1, typename T2>
	pair<T1, T2>::pair(const T1 &a, const T2 &b) : first(a), second(b)
	{
	}
}  // namespace ft

#endif /* ifndef UTILITY_HPP */
