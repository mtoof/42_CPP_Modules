/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:01:20 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/15 20:02:57 by mtoof            ###   ########.fr       */
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
	for (int index = 0; index < 10; index++)
	{
		vec1.push_back(dis(genetrator));
	}
	try
	{
		::easyfind(vec1, 10);
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