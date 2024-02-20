/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:43:14 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/20 23:14:06 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "<input file> is missing" << std::endl;
		std::cout << av[0] << " <input file>" << std::endl;
		return -1;
	}
	std::map<std::string, std::string> map;
	dataBase();
	// extract_data(av[1]);
	return (0);
}