/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_vector_insert.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:38:44 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/24 18:24:45 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include "../src/vector.hpp"

void test_vector_insert(void)
{
	{
		ft::vector<int> x;
		std::vector<int> y;
		ft::vector<int>::iterator it;

		x.insert(x.begin(), 5);
		y.insert(y.begin(), 5);
		assert(x.size() == y.size());
		assert(*(x.begin()) == 5);
		x.insert(x.begin(), 7);
		y.insert(y.begin(), 7);
		assert(x.size() == y.size());
		assert(*(x.begin()) == 7);
		x.insert(x.begin() + 1, 6);
		y.insert(y.begin() + 1, 6);
		assert(x.size() == y.size());
		assert(*(x.begin() + 1) == 6);

		it = x.begin();
		x.insert(x.begin(), 3, 100);
		x.insert(x.begin() + 1, 3, 5);
		assert(*(x.begin() + 1) == 5);
	}
	std::cout << " test_vector_insert [OK] " << std::endl;
}

// int main()
//{
//	test_vector_insert();
// }
