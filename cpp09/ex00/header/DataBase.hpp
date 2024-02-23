/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:56:22 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/24 00:58:27 by mtoof            ###   ########.fr       */
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
#include <sys/stat.h>

#define DATABASE_FILE "data.csv"

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
	void readInputFile(std::string filename);
	bool checkData(std::string date, std::string rate);
	void getDataBase() const;
	void printDataBase() const;
	
	class InvalidDataException: public std::exception
	{
		public:
			const char* what() const noexcept;
	};
	class FailDataFileException: public std::exception
	{
		public:
			const char* what() const noexcept;
	};
};

#endif
