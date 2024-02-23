/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:01:00 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/23 16:26:05 by mtoof            ###   ########.fr       */
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
		this->_btc_database.clear();
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
		std::cerr << "Couldn't open the file" << std::endl;
		throw FileNotExistException();
	}
	std::stringstream data;
	data << fd.rdbuf();
	std::string key, value;
	std::regex keyFormat("^\\d{4}-\\d{1,2}-\\d{1,2}$");
	std::regex valueFormat("^\\d+(.\\d+)?$");

	int counter = 0;
	while (!data.eof())
	{
		counter++;
		// check format
		std::string line;
		data >> line;
		if (line.find(',') != std::string::npos)
		{
			std::stringstream tmp;
			tmp << line;
			getline(tmp, key, ',');
			getline(tmp, value, '\n');
		}
		else
			continue;
		bool key_result = std::regex_match(key, keyFormat);
		bool value_result = std::regex_match(value, valueFormat);
		if (counter == 1 && key == "date")
			continue;
		if (!key.empty() && !value.empty() && key_result && value_result && checkData(key, value))
			_btc_database.insert(std::pair<std::string, std::string>(key, value));
	}
	fd.close();
}

bool DataBase::checkData(std::string date, std::string rate)
{
	if (!checkDateValue(date) || !checkRateValue(rate))
		return false;
	return true;
}

bool DataBase::checkDateValue(std::string str)
{
	int year, month, day;
	char dash;
	std::istringstream(str) >> year >> dash >> month >> dash >> day;
	std::tm timeinfo{};
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;

	int leapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

	std::time_t result = mktime(&timeinfo);
	if (result == -1)
		return false;
	switch (timeinfo.tm_mon)
	{
	case 1: // February
		// Check for leap year
		if (day > 29 || (day == 29 && !leapYear))
		{
			std::cout << timeinfo.tm_mon << std::endl;
			return false; // Invalid date
		}
		break;
	case 3:	 // April
	case 5:	 // June
	case 8:	 // September
	case 10: // November
		if (timeinfo.tm_mday > 30)
			return false;
		break;
	default:
		if (day > 31)
			return false;
		break;
	}
	return (timeinfo.tm_year == year - 1900 &&
			timeinfo.tm_mon == month - 1 &&
			timeinfo.tm_mday == day);
}

bool DataBase::checkRateValue(std::string str)
{
	if (str.empty())
		return false;
	else
	{
		int index = 0;
		int dot = 0;
		while (str[index])
		{
			if (!std::isdigit(str[index]) && str[index] != '.')
				return false;
			if (str[index] == '.')
				dot++;
			if (dot > 1)
				return false;
			index++;
		}
	}
	return true;
}

const char *DataBase::InvalidDataException::what() const noexcept
{
	return ("Invalid database file, Found an unusual character(s)!!!");
}

const char *DataBase::FileNotExistException::what() const noexcept
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
