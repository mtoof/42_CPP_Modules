/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:56:22 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/25 21:00:38 by mtoof            ###   ########.fr       */
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
#include <float.h>
#define DATABASE_FILE "data.csv"
enum status
{
	NAGAVTIVE_NUMBER,
	TOOLARGE_NUMBER,
	INVALID_RATE,
	INVALID_DATE,
	VALID_DATA,
	INVALID_DATA,
};

class DataBase
{
private:
	bool _map;
	std::map<std::string, std::string> _btc_database;
	void readfile(std::string filename, std::ifstream &fd);
	int checkDateValue(std::string str);
	int checkRateValue(std::string str);
	void parseData(std::ifstream &fd);
	void readInputFile(std::ifstream &fd);
	int checkData(std::string date, std::string rate);

public:
	DataBase();
	DataBase(const DataBase &rhs);
	DataBase &operator=(const DataBase &rhs);
	~DataBase();

	void parseFile(std::string databaseFileName, std::string inputFile);
	void printDataBase() const;

	class InvalidDataException : public std::exception
	{
	public:
		const char *what() const noexcept;
	};
	class FailDataFileException : public std::exception
	{
	public:
		const char *what() const noexcept;
	};
	class DataBaseIsDirectoryException : public std::exception
	{
	public:
		const char *what() const noexcept;
	};
};

#endif
