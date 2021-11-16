/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mak <abel-mak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:11:35 by abel-mak          #+#    #+#             */
/*   Updated: 2021/11/16 15:45:02 by abel-mak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void test();
void test_balance_after();
void test_insert();
void test_iterator();
void test_erase();
void test_size();
void test_clear();
void test_map_iter();
void test_map_operations();
void test_map_modifiers();
void test_tree_insert();
void test_tree_erase();

int main(void)
{
	test();
	test_balance_after();
	test_insert();
	test_iterator();
	test_erase();
	test_size();
	test_clear();
	test_map_iter();
	test_map_operations();
	test_map_modifiers();
	test_tree_insert();
	test_tree_erase();
}
