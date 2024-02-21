/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:56:22 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/21 14:09:08 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <fstream>
#include <time.h>
#include <exception>
#include <utility>

class DataBase
{
private:
	std::map <std::string, std::string> _btc_database;
	static void checkDateValue(std::string str);
	static void checkRateValue(std::string str);

public:
	DataBase();
	DataBase(const DataBase &rhs);
	DataBase &operator=(const DataBase &rhs);
	~DataBase();
	void readDataFile();
	void checkData();
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
};

#endif
