/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:20:22 by mtoof             #+#    #+#             */
/*   Updated: 2023/08/30 18:06:29 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int index = 1; index < ac; index++)
		for (int c_index = 0; av[index][c_index]; c_index++)
			std::cout << (char)(toupper(av[index][c_index]));
	std::cout << std::endl;
	return (0);
}
