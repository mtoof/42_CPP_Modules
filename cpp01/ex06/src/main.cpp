/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:31:59 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/29 13:41:01 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl harl_test;
		harl_test.complain(av[1]);
	}
	else
	{
		std::cout << "Not enough parameter" << std::endl;
		return (1);
	}
	return (0);
}