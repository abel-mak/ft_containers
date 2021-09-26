/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:37:59 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/26 15:32:29 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft
{
	template <typename T>
	struct is_integral
	{
	public:
		const static bool value = false;
	};
	template <>
	struct is_integral<bool>
	{
	public:
		const static bool value = true;
	};
	template <>
	struct is_integral<char> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<unsigned char> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<signed char> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<wchar_t> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<char16_t> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<char32_t> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<short> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<unsigned short> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<int> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<unsigned int> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<long> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<unsigned long> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<long long> : public is_integral<bool>
	{
	};
	template <>
	struct is_integral<unsigned long long> : public is_integral<bool>
	{
	};
	/**************************************************************************/
	template <bool Cond, typename T = void>
	struct enable_if
	{
	};
	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}  // namespace ft

#endif /* ifndef TYPE_TRAITS_HPP */
