/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:43:14 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/23 14:02:36 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/DataBase.hpp"

int main(int ac, char **av)
{
	DataBase database;

	if (ac != 2)
	{
		std::cout << "<input file> is missing" << std::endl;
		std::cout << av[0] << " <input file>" << std::endl;
		return -1;
	}
	try
	{
		database.readDataFile();
		database.printDataBase();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}