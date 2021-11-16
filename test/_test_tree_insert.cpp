/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tree_insert.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:16 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/16 15:43:44 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>

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

typedef ft::tree<int, int, std::less<int>,
                 std::allocator<ft::pair<const int, int> > >
    tree;

void test_tree_insert()
{
	int seed = atoi("1");

	srand(seed);
	{
		tree t;

		for (int i = 0; i < 1000000; ++i)
		{
			seed = rand();
			t.insert(ft::make_pair(seed, rand()));
		}
		assert(t.size() == 1000000);
		assert(isBalanced(t.getRoot()) == true);
	}
	{
		tree t;

		for (int i = 0; i < 1000000; ++i)
		{
			t.insert(ft::make_pair(i, rand()));
		}
		assert(t.size() == 1000000);
		assert(isBalanced(t.getRoot()) == true);
	}
	std::cout << " test_tree_insert [OK]" << std::endl;
}

//int main(void)
//{
//	test_tree_insert();
//}
