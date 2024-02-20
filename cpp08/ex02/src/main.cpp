/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:27:09 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/20 15:48:33 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "result after copy constructor stack" << std::endl;

	std::cout << "======================================" << std::endl;
	std::list<int> list1;
	list1.push_back(5);
	list1.push_back(17);
	std::cout << list1.back() << std::endl;
	list1.pop_back();
	std::cout << list1.size() << std::endl;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(737);
	//[...]
	list1.push_back(0);
	std::list<int>::iterator item_begin = list1.begin();
	std::list<int>::iterator item_end = list1.end();
	++item_begin;
	--item_begin;
	while (item_begin != item_end)
	{
		std::cout << *item_begin << std::endl;
		++item_begin;
	}
	std::cout << "========================================" << std::endl;
	std::list<int> list2(list1);
	std::cout << "result after copy constructor list" << std::endl;
	
	std::list<int>::iterator item_begin2 = list2.begin();
	std::list<int>::iterator item_end2 = list2.end();
	++item_begin2;
	--item_begin2;
	while (item_begin2 != item_end2)
	{
		std::cout << *item_begin2 << std::endl;
		++item_begin2;
	}
	return 0;
}