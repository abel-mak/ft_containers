/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:27:08 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/26 14:56:15 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
	/*
	 * pair
	 */
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

	public:
		first_type first;
		second_type second;
		pair &operator=(const pair &rhs);
		bool operator==(const pair &rhs) const;
		bool operator!=(const pair &rhs) const;
		bool operator<(const pair &rhs) const;
		bool operator>(const pair &rhs) const;
		bool operator>=(const pair &rhs) const;
		bool operator<=(const pair &rhs) const;
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
	template <typename T1, typename T2>
	bool pair<T1, T2>::operator==(const pair<T1, T2> &rhs) const
	{
		return (this->first == rhs.first && this->second == rhs.second);
	}
	template <typename T1, typename T2>
	bool pair<T1, T2>::operator!=(const pair<T1, T2> &rhs) const
	{
		return (this->first != rhs.first || this->second != rhs.second);
	}
	template <typename T1, typename T2>
	bool pair<T1, T2>::operator<(const pair<T1, T2> &rhs) const
	{
		if (this->first < rhs.first ||
		    (this->first == rhs.first && this->second < rhs.second))
			return (true);
		return (false);
	}
	template <typename T1, typename T2>
	bool pair<T1, T2>::operator>(const pair<T1, T2> &rhs) const
	{
		return (rhs < (*this));
	}
	template <typename T1, typename T2>
	bool pair<T1, T2>::operator>=(const pair<T1, T2> &rhs) const
	{
		return (!(*this < rhs));
	}
	template <typename T1, typename T2>
	bool pair<T1, T2>::operator<=(const pair<T1, T2> &rhs) const
	{
		return (!(*this > rhs));
	}
	/*
	 * make_pair
	 */
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 a, T2 b)
	{
		return pair<T1, T2>(a, b);
	}
}  // namespace ft

#endif /* ifndef UTILITY_HPP */
