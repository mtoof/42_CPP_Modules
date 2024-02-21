/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:43:14 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/21 12:17:06 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "<input file> is missing" << std::endl;
		std::cout << av[0] << " <input file>" << std::endl;
		return -1;
	}
	DataBase database;
	try
	{
		database.readDataFile();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}