/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_map_operations.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:33:41 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/11 20:18:54 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>

#include "test_header.hpp"
//#include <map>

#include "../src/map.hpp"
void test_map_operations()
{
	{
		typedef ft::pair<const int, double> V;
		typedef ft::map<int, double> M;
		{
			typedef M::iterator R;
			V ar[] = {V(5, 5), V(6, 6),   V(7, 7),   V(8, 8),
			          V(9, 9), V(10, 10), V(11, 11), V(12, 12)};
			M m(ar, ar + sizeof(ar) / sizeof(ar[0]));
			R r = m.find(5);
			assert(r == m.begin());
			r = m.find(6);
			assert(r == std::next(m.begin()));
			r = m.find(7);
			assert(r == std::next(m.begin(), 2));
			r = m.find(8);
			assert(r == std::next(m.begin(), 3));
			r = m.find(9);
			assert(r == std::next(m.begin(), 4));
			r = m.find(10);
			assert(r == std::next(m.begin(), 5));
			r = m.find(11);
			assert(r == std::next(m.begin(), 6));
			r = m.find(12);
			assert(r == std::next(m.begin(), 7));
			r = m.find(4);
			assert(r == std::next(m.begin(), 8));
		}
		{
			typedef M::const_iterator R;
			V ar[] = {V(5, 5), V(6, 6),   V(7, 7),   V(8, 8),
			          V(9, 9), V(10, 10), V(11, 11), V(12, 12)};
			const M m(ar, ar + sizeof(ar) / sizeof(ar[0]));
			R r = m.find(5);
			assert(r == m.begin());
			r = m.find(6);
			assert(r == std::next(m.begin()));
			r = m.find(7);
			assert(r == std::next(m.begin(), 2));
			r = m.find(8);
			assert(r == std::next(m.begin(), 3));
			r = m.find(9);
			assert(r == std::next(m.begin(), 4));
			r = m.find(10);
			assert(r == std::next(m.begin(), 5));
			r = m.find(11);
			assert(r == std::next(m.begin(), 6));
			r = m.find(12);
			assert(r == std::next(m.begin(), 7));
			r = m.find(4);
			assert(r == std::next(m.begin(), 8));
		}
	}
	std::cout << " test_map_operations [OK]" << std::endl;
}
