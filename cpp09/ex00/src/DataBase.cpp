/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:01:00 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/21 17:27:14 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/DataBase.hpp"

DataBase::DataBase()
{
	
}

DataBase::DataBase(const DataBase &rhs)
{
	*this = rhs;
}

DataBase &DataBase::operator=(const DataBase &rhs)
{
	if (this != &rhs)
	{
		this->_btc_database.empty();
		this->_btc_database=rhs._btc_database;
	}
	return (*this);
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
		if (counter == 1 && key == "date")
			continue;
		if (key.empty() || value.empty())
			throw InvalidDataException();
		else if (!key.empty() && !value.empty())
			_btc_database.insert(std::pair<std::string, std::string>(key, value));
	}
	checkData();
}

void DataBase::checkDateValue(std::string str)
{
	struct tm date;
	const char *format = "%Y-%m-%d";
	std::regex regex_format("^\\d{4}-\\d{1,2}-\\d{1,2}$");
	std::smatch match;
	if (strptime(str.c_str(), format, &date) == NULL)
		throw InvalidDataException();
	if (std::regex_match(str, match, regex_format) == false)
		throw InvalidDataException();
	int day = 0;
	try
	{
		// int year = std::stoi(match[0]);
		// int month = std::stoi(match[1]);
		day = atoi(match[2].str().c_str());
		if (day > 31)
			throw InvalidDataException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
	std::map<std::string, std::string>::const_iterator pair;
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

void DataBase::printDataBase() const
{
	std::map<std::string, std::string>::const_iterator pair;

	for (pair = _btc_database.begin(); pair != _btc_database.end(); pair++)
	{
		std::cout << pair->first << " " << pair->second << std::endl;
	}
}
