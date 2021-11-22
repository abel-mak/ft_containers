/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:17:28 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/22 11:52:12 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>

#include "../src/iterator.hpp"

int sum(int a, int b)
{
	return (a + b);
}

void test_iterator(void)
{
	{
		{
			std::__wrap_iter<char *> std_i1;
			ft::normal_iterator<char *> ft_i1(std_i1.base());

			assert(ft_i1.base() == std_i1.base());
			assert((ft_i1++).base() == (std_i1++).base());
			assert((++ft_i1).base() == (++std_i1).base());
			assert((ft_i1--).base() == (std_i1--).base());
			assert((--ft_i1).base() == (--std_i1).base());
			assert((ft_i1 += 5).base() == (std_i1 += 5).base());
			assert((ft_i1 -= 5).base() == (std_i1 -= 5).base());
			assert((ft_i1 + 5).base() == (std_i1 + 5).base());
			assert((ft_i1 - 5).base() == (std_i1 - 5).base());
			{} {
				std::__wrap_iter<char *> std_rev1;
				ft::normal_iterator<char *> ft_rev1(std_rev1.base());

				std::__wrap_iter<char *> std_rev2;
				ft::normal_iterator<char *> ft_rev2(std_rev2.base());
				bool b1, b2;

				std_rev1++;
				ft_rev1++;

				std::cout << static_cast<void *>(std_rev1.base()) << std::endl;
				std::cout << static_cast<void *>(ft_rev1.base()) << std::endl;
				b1 = (std_rev1 == std_rev2);
				b2 = (ft_rev1 == ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 > std_rev2);
				b2 = (ft_rev1 > ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 < std_rev2);
				b2 = (ft_rev1 < ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 >= std_rev2);
				b2 = (ft_rev1 >= ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 <= std_rev2);
				b2 = (ft_rev1 <= ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 != std_rev2);
				b2 = (ft_rev1 != ft_rev2);
				assert(b1 == b2);
			}
		}

		{
			{
				std::reverse_iterator<ft::normal_iterator<char *> > std_rev1;
				ft::reverse_iterator<ft::normal_iterator<char *> > ft_rev1(
				    std_rev1.base());

				assert((static_cast<void *>(std_rev1.base().base()) ==
				        static_cast<void *>(ft_rev1.base().base())));
				ft_rev1++;
				std_rev1++;
				assert((static_cast<void *>(std_rev1.base().base()) ==
				        static_cast<void *>(ft_rev1.base().base())));

				assert(ft_rev1.base() == std_rev1.base());
				assert((ft_rev1++).base() == (std_rev1++).base());
				assert((++ft_rev1).base() == (++std_rev1).base());
				assert((ft_rev1--).base() == (std_rev1--).base());
				assert((--ft_rev1).base() == (--std_rev1).base());
				assert((ft_rev1 += 5).base() == (std_rev1 += 5).base());
				assert((ft_rev1 -= 5).base() == (std_rev1 -= 5).base());
				assert((ft_rev1 + 5).base() == (std_rev1 + 5).base());
				assert((ft_rev1 - 5).base() == (std_rev1 - 5).base());
			}
			{
				struct test
				{
					int a;
					test()
					{
						a = 3;
					}
					test(int z)
					{
						a = z;
					}
				};
				{
					int arr[] = {1, 2};
					std::reverse_iterator<int *> std_rev(arr + 3);
					ft::reverse_iterator<int *> ft_rev(arr + 3);

					assert(std_rev[0] == ft_rev[0]);
					assert(std_rev[1] == ft_rev[1]);
					assert(*std_rev == *ft_rev);
				}
				{
					struct test t1;
					struct test t2(10);
					struct test tarr[] = {t1, t2};
					std::reverse_iterator<struct test *> std_rev(tarr + 3);
					ft::reverse_iterator<struct test *> ft_rev(tarr + 3);
					assert(std_rev[0].a == ft_rev[0].a);
					assert(std_rev[1].a == ft_rev[1].a);
					assert((*std_rev).a == (*ft_rev).a);
					assert((std_rev)->a == (ft_rev)->a);
				}
			}
			{
				std::reverse_iterator<char *> std_rev1;
				ft::reverse_iterator<char *> ft_rev1(std_rev1.base());

				std::reverse_iterator<char *> std_rev2;
				ft::reverse_iterator<char *> ft_rev2(std_rev2.base());
				bool b1, b2;

				std_rev1++;
				ft_rev1++;

				std::cout << static_cast<void *>(std_rev1.base()) << std::endl;
				std::cout << static_cast<void *>(ft_rev1.base()) << std::endl;
				b1 = (std_rev1 == std_rev2);
				b2 = (ft_rev1 == ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 > std_rev2);
				b2 = (ft_rev1 > ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 < std_rev2);
				b2 = (ft_rev1 < ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 >= std_rev2);
				b2 = (ft_rev1 >= ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 <= std_rev2);
				b2 = (ft_rev1 <= ft_rev2);
				assert(b1 == b2);
				b1 = (std_rev1 != std_rev2);
				b2 = (ft_rev1 != ft_rev2);
				assert(b1 == b2);
			}
		}
	}
}
