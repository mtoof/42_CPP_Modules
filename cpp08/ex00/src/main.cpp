/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:01:20 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/16 17:13:56 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 genetrator(rd());
	std::uniform_int_distribution<int> dis(1, 100);
	
	std::vector<int> vec1;
	int random_nb;
	for (int index = 0; index < 10; index++)
	{
		random_nb = dis(genetrator);
		vec1.push_back(random_nb);
	}
	std::cout << "last random number was :" << random_nb << std::endl;
	try
	{
		::easyfind(vec1, random_nb);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::vector<int> vec2{1,2,3,4,5};
	try
	{
		::easyfind(vec2, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		::easyfind(vec2, 4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}