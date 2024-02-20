/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractData.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:51:15 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/20 23:29:31 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

std::stringstream dataBase()
{
	std::ifstream fd;
	fd.open("data.csv");
	if (fd.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
		exit(1);
	}

	std::stringstream data;
	data << fd.rdbuf();
	std::map<std::string, std::string> btc_database;
	std::string key;
	std::string value;

	while (!data.eof())
	{
		getline(data, key, ',');
		getline(data, value, '\n');
		if (!key.empty() && !value.empty())
			btc_database.insert(std::pair<std::string, std::string>(key, value));
		else
		{
			std::cout << "Got Invalid database file, Found an empty key or value!!!" << std::endl;
			exit(1);
		}
			
	}
	return data;
}