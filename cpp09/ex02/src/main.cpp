/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:35 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/27 13:47:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe sortNumbers;
	if (ac < 3)
	{
		std::cerr << "Error: Not enough numbers to be sorted" << std::endl;
		return 1;
	}
	for (int num = 1; av[num]; num++)
	{
		for (int index = 0; av[num][index]; index++)
		{
			if (!std::isdigit(av[num][index]) && av[num][index] != '+')
			{		
				std::cout << av[num] << std::endl;
				std::cerr << "Error: All the arguments must be a positive integer" << std::endl;
				return 1;
			}
		}
	}
	try
	{
		sortNumbers.parseNumbers(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}