/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_map_iter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:58:16 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/09 18:55:31 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>

#include "../src/map.hpp"

void test_map_iter(void)
{
	{
		ft::map<int, int> m;
		ft::map<int, int>::iterator it;
		std::map<int, int> M;

		it = m.begin();

		while (it != m.end())
		{
			std::cout << "=======" << std::endl;
			it++;
		}
		ft::pair<int, int> a;
		std::pair<int, int> b;

		m.insert(ft::make_pair(1, 1));
		M.insert(std::make_pair(1, 1));
		assert(m.size() == M.size());
	}
}

