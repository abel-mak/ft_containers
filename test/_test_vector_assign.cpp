/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_vector_assign.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:48:25 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/24 18:19:00 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/vector.hpp"

void test_vector_assign(void)
{
	{
		int arr1[] = {42};
		int arr2[] = {1, 101, 42};
		{
			ft::vector<int> v;
			v.assign(arr1, arr1 + 1);
			assert(v[0] == 42);
		}
		{
			ft::vector<int> v;
			v.assign(arr2, arr2 + 3);
			assert(v[0] == 1);
			assert(v[1] == 101);
			assert(v[2] == 42);
		}
	}
	std::cout << " test_vector_assign [OK]" << std::endl; 
}

//int main()
//{
//	test_vector_assign();
//}
