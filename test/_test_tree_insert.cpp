/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tree_insert.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:16 by abel-mak          #+#    #+#             */
/*   Updated: 2021/10/29 19:24:50 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/tree.hpp"
#include "../src/tree_iterator.hpp"
#include "../src/utility.hpp"

void test_insert()
{
	{
		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int>>>
		    t;
		ft::tree_node<ft::pair<const int, int>> a;
		ft::tree_node<ft::pair<const int, int>> b;
		ft::tree_node<ft::pair<const int, int>> c;

		t.insert(a);
		// t.insert()
	}
}
