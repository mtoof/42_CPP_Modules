/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:35 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/26 15:25:21 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

int main(int ac, char **av)
{
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
	return 0;
}