/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:40 by abel-mak          #+#    #+#             */
/*   Updated: 2021/09/14 18:25:23 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <memory>
#include <vector>

#include "src/vector.hpp"

void put(int const s)
{
	std::cout << s << std::endl;
}

int main()
{
	//ft::vector<int> a(5, 2);
	std::allocator<int> alloc;
	std::vector<int> myints(5, 2);

	// assert(myints[0] == a[0]);
	// assert(myints.size() == a.size());
	// assert(myints.capacity() == a.capacity());
	// std::cout << "✅" << std::endl;
	// put(myints[0]);
	// put(myints.size());
	// put(myints.capacity());
	// put(a[0]);
	// put(a.size());
	// put(a.capacity());
	myints.push_back(10);
	while (1)
		;
	return (0);
}
