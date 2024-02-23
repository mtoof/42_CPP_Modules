/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:56:22 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/23 15:11:33 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include <exception>
#include <utility>
#include <regex>

class DataBase
{
private:
	std::map <std::string, std::string> _btc_database;
	bool checkDateValue(std::string str);
	bool checkRateValue(std::string str);

public:
	DataBase();
	DataBase(const DataBase &rhs);
	DataBase &operator=(const DataBase &rhs);
	~DataBase();
	void readDataFile();
	bool checkData(std::string date, std::string rate);
	class InvalidDataException: public std::exception
	{
		public:
			const char* what() const noexcept;
	};
	class FileNotExistException: public std::exception
	{
		public:
			const char* what() const noexcept;
	};
	void getDataBase() const;
	void printDataBase() const;
};

#endif
