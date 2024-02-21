/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:01:00 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/21 14:30:46 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"

DataBase::DataBase()
{
	
}

DataBase::~DataBase()
{
	
}

void DataBase::readDataFile()
{
	std::ifstream fd;
	fd.open("data.csv");
	if (fd.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
		throw FileNotExistException();
	}
	std::stringstream data;
	data << fd.rdbuf();
	std::string key;
	std::string value;
	int counter = 0;
	while (!data.eof())
	{
		counter++;
		getline(data, key, ',');
		getline(data, value, '\n');
		if (key == "date" && counter == 1)
			continue;
		std::cout << value << std::endl;
		if (!key.empty() && !value.empty())
			_btc_database.insert(std::pair<std::string, std::string>(key, value));
	}
	checkData();
}

void DataBase::checkDateValue(std::string str)
{
	struct tm date;
	std::string format = "%Y-%m-%d";
	
	if (str.empty() || strptime(str.c_str(), format.c_str(), &date) == NULL)
		throw InvalidDataException();
}

void DataBase::checkRateValue(std::string str)
{
	if (str.empty())
		throw InvalidDataException();
	else
	{
		int index = 0;
		while (str[index])
		{
			if (!std::isdigit(str[index]) && str[index] != '.')
				throw InvalidDataException();
			index++;
		}
	}
}

void DataBase::checkData()
{
	std::map<std::string, std::string>::iterator pair;
	for (pair = _btc_database.begin(); pair != _btc_database.end(); pair++)
	{
		checkDateValue(pair->first);
		checkRateValue(pair->second);
	}
}

const char* DataBase::InvalidDataException::what() const noexcept
{
	return ("Invalid database file, Found an unusual character!!!");
}

const char* DataBase::FileNotExistException::what() const noexcept
{
	return ("data.csv File does not exist!!!");
}