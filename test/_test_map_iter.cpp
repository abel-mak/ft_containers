/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_map_iter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:58:16 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/08 19:20:49 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/map.hpp"

void test_map_iter(void)
{
	{
		const ft::map<int, int> m;
		ft::map<int, int>::const_iterator it;

		it = m.begin();

		while (it != m.end())
		{
			std::cout << "=======" << std::endl;
			it++;
		}
	}
}

