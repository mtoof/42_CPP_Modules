/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:57:39 by mtoof             #+#    #+#             */
/*   Updated: 2024/04/08 19:03:09 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Rpn.hpp"

int main(int ac, char **av)
{
	Rpn rpn;
	std::string rpn_array[] = {
		"3 5 - 2 * 4 + -7 6 + /",
		"-2 8 * 4 3 - / 5 +",
		"9 2 - 5 4 - * -6 3 + /",
		"7 -3 * 6 + 4 2 * /",
		"-8 3 * 5 + 6 2 / -",
		"4 5 + -2 * 3 7 - /",
		"6 -4 * 8 2 - / 3 +",
		"2 9 - 3 5 * + -7 4 + /",
		"5 6 - 3 - 2 + -8 4 / *"
		};
	std::string test_answer[] =
		{
			"0",
			"-11",
			"-2",
			"-1",
			"-22",
			"4",
			"-1",
			"-2",
			"-2",
			"4"};

	if (ac != 2)
	{
		char answer;
		std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
		std::cout << "\nWould you like to contine with built-in test? [y/n] ";
		std::cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			for (size_t index = 0; index < sizeof(rpn_array) / sizeof(std::string); index++)
			{
				std::cout << index + 1 << ") " << rpn_array[index] << " => " << test_answer[index] << std::endl;
				std::cout << "RPN answer = ";
				rpn.parse(rpn_array[index]);
			}
		}
		return (1);
	}
	try
	{
		if (!rpn.parse(av[1]))
			return (1);
	}
	catch(std::exception &exp)
	{
		std::cout << exp.what() << std::endl;
		return 1;
	}
	return (0);
}