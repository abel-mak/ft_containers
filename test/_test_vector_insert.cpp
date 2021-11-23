/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_vector_insert.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:38:44 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/23 19:28:10 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include "../src/vector.hpp"

void test_vector_insert(void)
{
	{
		std::vector<int> x;
		std::vector<int> y;
		ft::vector<int>::iterator it;

		// std::cout << " ===== " << x.capacity() << std::endl;
		// std::cout << " ===== " << y.capacity() << std::endl;
		// x.insert(x.begin(), 5);
		// y.insert(y.begin(), 5);
		// std::cout << " ===== " << x.capacity() << std::endl;
		// std::cout << " ===== " << y.capacity() << std::endl;
		// assert(x.size() == y.size());
		// assert(*(x.begin()) == 5);
		// x.insert(x.begin(), 7);
		// y.insert(y.begin(), 7);
		// std::cout << " ===== " << x.capacity() << std::endl;
		// std::cout << " ===== " << y.capacity() << std::endl;
		// assert(x.size() == y.size());
		// assert(*(x.begin()) == 7);
		// std::cout << " ===== " << x.capacity() << std::endl;
		// std::cout << " ===== " << y.capacity() << std::endl;
		// x.insert(x.begin() + 1, 6);
		// y.insert(y.begin() + 1, 6);
		// assert(x.size() == y.size());
		// assert(*(x.begin() + 1) == 6);

		// it = x.begin();
		// while (it != x.end())
		//{
		//	std::cout << " ==== " << *it << std::endl;
		//	it++;
		// }
		std::cout << " ===== " << x.capacity() << std::endl;
		x.insert(x.begin(), 3, 100);
		std::cout << " ===== " << x.capacity() << std::endl;
		std::cout << " ===== " << x.capacity() << std::endl;
		x.insert(x.begin() + 1, 3, 5);
		std::cout << " ===== " << x.capacity() << std::endl;
		assert(*(x.begin() + 1) == 5);
	}
}

//int main()
//{
//	test_vector_insert();
//}
