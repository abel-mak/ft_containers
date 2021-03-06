/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tree_erase.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:14:49 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/20 17:43:34 by abel-mak         ###   ########.fr       */
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
		const tree tt;
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
	{
		tree t;
		tree a(t);
		tree::iterator it;
		ft::vector<tree::iterator> arr;

		for (int i = 0; i < 100; ++i)
		{
			it = (t.insert(ft::make_pair(i, rand()))).first;
			if (i >= 50 && i < 50 + 7)
				arr.push_back(it);
		}
		// std::cout << (t.lower_bound(5))->first << std::endl;
		t.erase(tree::iterator(t.getRoot()));
		t.erase(tree::iterator(arr[0]));
		t.erase(tree::iterator(arr[1]));
		t.erase(tree::iterator(arr[2]));
		t.erase(tree::iterator(arr[4]));
		t.erase(tree::iterator(arr[5]));
		t.erase(tree::iterator(arr[6]));
		a = t;
		assert(t.size() == a.size());
		assert(t.size() == 93);
		assert(isBalanced(t.getRoot()) == true);
	}
	{
		// std::map<int, int> m;
		// std::map<int, int>::iterator it;
		// ft::vector<std::map<int, int>::iterator> arr;
		// std::map<int, int>::iterator it2;

		// for (int i = 0; i < 100; ++i)
		//{
		//	it = (m.insert(std::make_pair(i, rand()))).first;
		//	if (i >= 50 && i < 50 + 3)
		//		arr.push_back(it);
		// }
		//   std::cout << (m.lower_bound(1000))->first << std::endl;
		//    m.erase(std::map<int, int>::iterator(arr[0]));
		//    m.erase(std::map<int, int>::iterator(arr[1]));
		//    m.erase(std::map<int, int>::iterator(arr[2]));
	}
	std::cout << " test_tree_erase [OK]" << std::endl;
}

// int main()
//{
//	test_tree_erase();
// }
