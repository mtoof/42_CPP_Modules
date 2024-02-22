/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:01:00 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/22 18:30:43 by mtoof            ###   ########.fr       */
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
		this->_btc_database = rhs._btc_database;
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
		std::string line;
		getline(data, line);
		std::regex regex_format("^\\d{4}-\\d{2}-\\d{2},\\d+(\\.\\d+)?$"); // need to separate it to two expression one for key and another one for the value
		std::smatch match;
		// check format
		if (counter != 1 && std::regex_match(line, match, regex_format) == false)
		{
			std::cout << line << std::endl;
			throw InvalidDataException();
		}
		getline(data, key, ',');
		getline(data, value, '\n');
		if (counter == 1 && key == "date")
			continue;
		if (key.empty() || value.empty())
			throw InvalidDataException();
		else if (!key.empty() && !value.empty())
		{
			// Check for duplication before insert the pair
			if (_btc_database.find(key) != _btc_database.end())
				throw DuplicatedkeyException();
			_btc_database.insert(std::pair<std::string, std::string>(key, value));
		}
	}
	fd.close();
	checkData();
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

void DataBase::checkDateValue(std::string str)
{
	struct tm date;
	const char *format = "%Y-%m-%d";
	std::regex regex_format("^\\d{4}-\\d{1,2}-\\d{1,2}$");
	std::smatch match;
	// check if it's a date
	if (strptime(str.c_str(), format, &date) == NULL)
	{
		std::cout << str << std::endl;
		throw InvalidDateValueException();
	}
	// check format
	if (std::regex_match(str, match, regex_format) == false)
	{
		std::cout << str << std::endl;
		throw InvalidDateValueException();
	}
	checkDateValueInDetail(str);
}

void DataBase::checkDateValueInDetail(std::string str)
{
	std::stringstream ss;
	std::string year, month, day;
	ss << str;
	while (!ss.eof())
	{
		getline(ss, year, '-');
		getline(ss, month, '-');
		getline(ss, day, '-');
	}

	int int_year = 0, int_month = 0, int_day = 0;
	try
	{
		int_year = std::stoi(year);
		int_month = std::stoi(month);
		int_day = std::stoi(day);
	}
	catch (const std::exception &e)
	{
		throw e;
	}

	switch (int_month)
	{
	case 2:
		// check for leap year
		if ((int_year % 4 == 0 && int_year % 100 != 0) || int_year % 400 == 0)
		{
			if (int_day > 29)
			{
				std::cout << str << std::endl;
				throw InvalidDateValueException();
			}
		}
		else
		{
			if (int_day > 28)
			{
				std::cout << str << std::endl;
				throw InvalidDateValueException();
			}
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (int_day > 30)
		{
			std::cout << str << std::endl;
			throw InvalidDateValueException();
		}
		break;
	default:
		if (int_day > 31)
		{
			std::cout << str << std::endl;
			throw InvalidDateValueException();
		}
		break;
	}
}

void DataBase::checkRateValue(std::string str)
{
	if (str.empty())
		throw InvalidDataException();
	else
	{
		int index = 0;
		int dot = 0;
		while (str[index])
		{
			if (!std::isdigit(str[index]) && str[index] != '.')
				throw InvalidDataException();
			if (str[index] == '.')
				dot++;
			if (dot > 1)
				throw InvalidRateValueException();
			index++;
		}
	}
}

const char *DataBase::InvalidDataException::what() const noexcept
{
	return ("Invalid database file, Found an unusual character!!!");
}

const char *DataBase::FileNotExistException::what() const noexcept
{
	return ("data.csv File does not exist!!!");
}

const char *DataBase::DuplicatedkeyException::what() const noexcept
{
	return ("Found duplicated key!!!");
}

const char *DataBase::InvalidDateValueException::what() const noexcept
{
	return ("Found Invalid date value!!!");
}

const char *DataBase::InvalidRateValueException::what() const noexcept
{
	return ("Found Invalid exchange rate value!!!");
}

void DataBase::printDataBase() const
{
	std::map<std::string, std::string>::const_iterator pair;

	for (pair = _btc_database.begin(); pair != _btc_database.end(); pair++)
	{
		std::cout << pair->first << " " << pair->second << std::endl;
	}
}
