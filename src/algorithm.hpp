/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:16:50 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/20 17:20:12 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{
	// from c++ docs template <class InputIterator1, class InputIterator2>
	template <typename I1, typename I2>
	bool lexicographical_compare(I1 first1, I1 last1, I2 first2, I2 last2)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (*first2 < *first1)
				return (false);
			first1++;
			first2++;
		}
		// means 2 less than 1 => so 2 is lex.. smaller return false
		// or if they equal => so 1 is not lex.. smaller return false
		if (first1 != last1 || (first1 == last1 && first2 == last2))
			return (false);
		return (true);
	}

	// comp(a, b) true => a < b
	template <typename I1, typename I2>
	bool lexicographical_compare(I1 first1, I1 last1, I2 first2, I2 last2,
	                             bool comp)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (comp(*first2, *first1))
				return (false);
			first1++;
			first2++;
		}
		if (first1 != last1 || (first1 == last1 && first2 == last2))
			return (false);
		return (true);
	}

	template <typename I1, typename I2>
	bool equal(I1 first1, I1 last1, I2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template <typename I1, typename I2>
	bool equal(I1 first1, I1 last1, I2 first2, bool pred)
	{
		while (first1 != last1)
		{
			if (pred(*first1, *first2) == false)
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
}  // namespace ft

#endif /*  */
