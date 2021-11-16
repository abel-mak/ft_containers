/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tree_erase.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:14:49 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/16 16:17:47 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <map>

#include "../src/tree.hpp"
#include "../src/tree_iterator.hpp"
#include "../src/utility.hpp"
#include "../src/vector.hpp"

typedef ft::tree<int, int, std::less<int>,
                 std::allocator<ft::pair<const int, int> > >
    tree;

void test_tree_erase()
{
	int seed = atoi("1");

	srand(seed);
	{
		tree t;
		tree::iterator it;
		ft::vector<tree::iterator> arr;

		for (int i = 0; i < 100; ++i)
		{
			seed = rand();
			it   = (t.insert(ft::make_pair(seed, rand()))).first;
			if (i >= 50 && i < 50 + 3)
				arr.push_back(it);
		}
		t.erase(tree::iterator(t.getRoot()));
		t.erase(tree::iterator(arr[0]));
		t.erase(tree::iterator(arr[1]));
		t.erase(tree::iterator(arr[2]));
		assert(t.size() == 96);
		assert(isBalanced(t.getRoot()) == true);
	}
	//{
	//	tree t;
	//	tree::iterator it;
	//	ft::vector<tree::iterator> arr;

	//	for (int i = 0; i < 100; ++i)
	//	{
	//		it = (t.insert(ft::make_pair(i, rand()))).first;
	//		if (i >= 50 && i < 50 + 3)
	//			arr.push_back(it);
	//	}
	//	// std::cout << arr.size() << std::endl;
	//	// print2D(t.getRoot());
	//	t.erase(tree::iterator(t.getRoot()));
	//	t.erase(tree::iterator(arr[0]));
	//	t.erase(tree::iterator(arr[1]));
	//	t.erase(tree::iterator(arr[2]));
	//	std::cout << arr[1]->first << std::endl;
	//	std::cout << arr[2]->first << std::endl;
	//	assert(t.size() == 96);
	//	assert(isBalanced(t.getRoot()) == true);
	//}
	// std::cout << " test_tree_erase [OK]" << std::endl;
}
//		m.erase(std::map<int, int>::iterator(arr[0]));
//		print2D(t.getRoot());
//		m.erase(std::map<int, int>::iterator(arr[1]));
//		m.erase(std::map<int, int>::iterator(arr[2]));
//		std::cout << (--arr[2])->first << std::endl;
//		std::cout << (--arr[2])->first << std::endl;
//		std::cout << (--arr[2])->first << std::endl;
//		std::cout << (--arr[2])->first << std::endl;
//		std::cout << (--arr[2])->first << std::endl;
//		std::cout << (--arr[2])->first << std::endl;
