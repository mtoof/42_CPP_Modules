/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:01:00 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/22 13:07:34 by mtoof            ###   ########.fr       */
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
		{
			//Check for duplication before insert the pair
			if (_btc_database.find(key) != _btc_database.end())
				throw DuplicatedkeyException();
			_btc_database.insert(std::pair<std::string, std::string>(key, value));
		}
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
	{
		std::cout << str << std::endl;
		throw InvalidDateValueException();
	}
	if (std::regex_match(str, match, regex_format) == false)
	{
		std::cout << str << std::endl;
		throw InvalidDateValueException();
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

const char* DataBase::DuplicatedkeyException::what() const noexcept
{
	return ("Found duplicated key!!!");
}

const char* DataBase::InvalidDateValueException::what() const noexcept
{
	return ("Found Invalid date value!!!");
}

void DataBase::printDataBase() const
{
	std::map<std::string, std::string>::const_iterator pair;

	for (pair = _btc_database.begin(); pair != _btc_database.end(); pair++)
	{
		std::cout << pair->first << " " << pair->second << std::endl;
	}
}
