/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:48:31 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/23 19:14:17 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

namespace ft
{
	template <typename Y, typename Comp, typename Alloc>
	class tree
	{
	public:
		typedef Y value_type;
		typedef Comp value_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
	};
}  // namespace ft

#endif /* ifndef TREE_HPP */
