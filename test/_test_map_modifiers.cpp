/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_map_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:57:06 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/12 10:33:47 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>

#include "../src/map.hpp"

void test_map_modifiers()
{
	{
		ft::map<int, double> m;
		ft::map<int, double>::value_type v1(1, 1.5);
		ft::map<int, double>::value_type v2(2, 2.5);
		ft::map<int, double>::value_type v3(3, 3.5);
		{
			ft::map<int, double>::iterator it = m.insert(m.begin(), v2);
			assert(m.begin() == it);
			assert(m.size() == 1);
			assert((*it).first == 2);
		}
		{
			ft::map<int, double>::iterator it = m.insert(m.begin(), v1);
			assert(m.begin() == it);
			assert(m.size() == 2);
			assert((*it).first == 1);
		}
		{
			ft::map<int, double>::iterator it = m.insert(m.begin(), v3);
			assert(--(m.end()) == it);
			assert(m.size() == 3);
			assert((*it).first == 3);
		}
	}
	{

	}
	std::cout << " test_map_modifiers [OK]" << std::endl;
}
