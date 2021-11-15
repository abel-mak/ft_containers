/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tree_insert.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:16 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/15 19:40:55 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>

#include "../src/tree.hpp"
#include "../src/tree_iterator.hpp"
#include "../src/utility.hpp"
#include "test_header.hpp"

#define MAX_RAM     4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define XF (MAX_RAM / (int)sizeof(Buffer))

void test_tree_insert()
{
	{
		int seed = atoi("1");
		srand(seed);

		ft::tree<int, int, std::less<int>,
		         std::allocator<ft::pair<const int, int> > >
		    t;
		std::map<int, int> m;
		for (int i = 0; i < 1000000; ++i)
		{
			seed = rand();
			// m.insert(std::make_pair(i, rand()));
			//    std::cout << i << " ===================" << std::endl;
			t.insert(ft::make_pair(i, rand()));
		}
		std::cout << t.size() << std::endl;
		//  print2D(t.getRoot());
		// assert(isBalanced(t.getRoot()) == true);
		//	ft::tree<int, int, std::less<int>,
		//	         std::allocator<ft::pair<const int, int> > >
		//	    b = t;
	}
	std::cout << " test_tree_insert [OK]" << std::endl;
}

//int main(void)
//{
//	test_tree_insert();
//}
