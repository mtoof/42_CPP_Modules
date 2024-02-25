/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:57:39 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/25 19:34:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Rpn.hpp"

int main(int ac, char **av)
{
	Rpn rpn;
	if (ac != 2)
	{
		std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
		return (1);
	}
	if (!rpn.parse(av[1]))
		return (1);
	return (0);
}