/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:01:00 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/25 21:00:49 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/DataBase.hpp"

DataBase::DataBase() : _map(false), _btc_database()
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

void DataBase::parseFile(std::string databaseFileName, std::string inputfile)
{
	std::ifstream fd;
	if (_map == false)
	{
		readfile(databaseFileName, fd);
		parseData(fd);
		if (_btc_database.empty())
			throw InvalidDataException();
	}
	readfile(inputfile, fd);
	parseData(fd);
}

void DataBase::readfile(std::string filename, std::ifstream &fd)
{
	fd.open(filename);
	if (fd.fail())
	{
		std::cout << "Error: " << filename << ", ";
		throw FailDataFileException();
	}
	struct stat fileStat;
	if (stat(filename.c_str(), &fileStat) == 0)
	{
		if (S_ISDIR(fileStat.st_mode))
		{
			std::cout << filename;
			throw DataBaseIsDirectoryException();
		}
	}
}

void DataBase::parseData(std::ifstream &fd)
{
	std::stringstream data;
	data << fd.rdbuf();
	std::string key, value;
	std::regex keyFormat("^\\d{4}-\\d{1,2}-\\d{1,2}$");
	std::regex valueFormat("^\\d+(.\\d+)?$");
	std::regex inputValueFormat("^[+-]?\\d+(\\.\\d+)?$");
	std::string delimiter = (!_map) ? "," : " | ";
	int counter = 0;
	while (!data.eof())
	{
		counter++;
		// check format
		std::string line;
		getline(data, line);
		if (int position = line.find(delimiter) != std::string::npos)
		{
			std::stringstream tmp;
			tmp << line;
			if (!_map)
			{
				getline(tmp, key, ',');
				getline(tmp, value, '\n');
			}
			else
			{
				tmp >> key >> delimiter >> value;
			}
		}
		else
		{
			if (_map == true)
				std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		bool key_result = std::regex_match(key, keyFormat);
		if (_map == true)
			valueFormat = inputValueFormat;
		bool value_result = std::regex_match(value, valueFormat);
		if (counter == 1 && key == "date")
			continue;
		if (!key.empty() && !value.empty() && key_result == true && value_result == true && checkData(key, value) == VALID_DATA)
			if (_map == false)
				_btc_database.insert(std::pair<std::string, std::string>(key, value));
	}
	_map = true;
	fd.close();
}

int DataBase::checkData(std::string date, std::string rate)
{
	int date_status = checkDateValue(date);
	int rate_status = checkRateValue(rate);

	switch (date_status)
	{
	case INVALID_DATE:
		if (_map == true)
			std::cout << "Error: bad input => " << date << std::endl;
		return INVALID_DATE;
		break;
	}
	switch (rate_status)
	{
	case NAGAVTIVE_NUMBER:
		if (_map == true)
			std::cout << "Error: not a positive number." << std::endl;
		return NAGAVTIVE_NUMBER;
		break;
	case TOOLARGE_NUMBER:
		if (_map == true)
			std::cout << "Error: Too large a number." << std::endl;
		return TOOLARGE_NUMBER;
		break;
	case INVALID_RATE:
		if (_map == true)
			std::cout << "Error: Invalid number => " << rate << std::endl;
		return INVALID_RATE;
		break;
	}
	if (_map == true)
	{
		std::map<std::string, std::string>::iterator it;
		it = _btc_database.lower_bound(date);
		if (it != _btc_database.begin() && it != _btc_database.end())
			it--;
		else
		{
			std::cout << "Error: " << date << " is outside the valid range of dates in the database." << std::endl;
			return INVALID_DATE;
		}
		if (it != _btc_database.end())
			std::cout << date << " => " << rate << " = " << std::stof(rate) * std::stof(it->second) << std::endl;
	}
	return VALID_DATA;
}

int DataBase::checkDateValue(std::string str)
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
		return INVALID_DATE;
	switch (timeinfo.tm_mon)
	{
	case 1: // February
		// Check for leap year
		if (day > 29 || (day == 29 && !leapYear))
		{
			std::cout << timeinfo.tm_mon << std::endl;
			return INVALID_DATE; // Invalid date
		}
		break;
	case 3:	 // April
	case 5:	 // June
	case 8:	 // September
	case 10: // November
		if (timeinfo.tm_mday > 30)
			return INVALID_DATE;
		break;
	default:
		if (day > 31)
			return INVALID_DATE;
		break;
	}
	return (timeinfo.tm_year == year - 1900 &&
			timeinfo.tm_mon == month - 1 &&
			timeinfo.tm_mday == day)
			   ? VALID_DATA
			   : INVALID_DATE;
}

int DataBase::checkRateValue(std::string str)
{
	if (str.empty())
		return INVALID_RATE;
	else
	{
		int index = 0;
		int dot = 0;
		while (str[index])
		{
			if (!std::isdigit(str[index]) && str[index] != '.' && str[index] != '-' && str[index] != '+')
				return INVALID_RATE;
			if (str[index] == '.')
				dot++;
			if (dot > 1)
				return INVALID_RATE;
			index++;
		}
		try // check if the string is a number
		{
			float f_result = 0;
			int i_result = 0;
			dot == 1 ? f_result = std::stof(str) : i_result = std::stoi(str);
			if (i_result < 0 || f_result < 0.0)
				return NAGAVTIVE_NUMBER;
			if (_map == true && (i_result > 1000 || f_result > 1000.0))
			{
				return TOOLARGE_NUMBER;
			}
		}
		catch (std::exception &e)
		{
			return TOOLARGE_NUMBER;
		}
	}
	return VALID_DATA;
}

const char *DataBase::InvalidDataException::what() const noexcept
{
	return ("Invalid database file!!!");
}

const char *DataBase::FailDataFileException::what() const noexcept
{
	return ("Couldn't open the Database file!!!");
}

const char *DataBase::DataBaseIsDirectoryException::what() const noexcept
{
	return (" is a directory, not a file!!!");
}

void DataBase::printDataBase() const
{
	std::map<std::string, std::string>::const_iterator pair;

	for (pair = _btc_database.begin(); pair != _btc_database.end(); pair++)
	{
		std::cout << pair->first << " " << pair->second << std::endl;
	}
}
