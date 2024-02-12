/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:57:21 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/12 22:58:15 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cfloat>
#include <cmath>
#include <stdexcept>
#include <sstream>

short ScalarConverter::_type = 0;
char ScalarConverter::_sign = '\0';
bool ScalarConverter::_char_possible = true;
bool ScalarConverter::_int_possible = true;
bool ScalarConverter::_float_possible = true;
bool ScalarConverter::_double_possible = true;
bool ScalarConverter::_found_dot = false;
bool ScalarConverter::_found_scientific_notation = false;
bool ScalarConverter::_char_invalid = false;
bool ScalarConverter::_int_invalid = false;
bool ScalarConverter::_float_invalid = false;
bool ScalarConverter::_double_invalid = false;

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs){(void)rhs;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter(void){}


void ScalarConverter::converter(std::string str)
{
	std::cout << std::fixed << std::setprecision(1);
	int index = 0;
	isSign(str, index);
	getType(str, index);
	// check_limits(str);
	castToChar(str);
	castToInt(str);
	castToFloat(str);
	castToDouble(str);
}

void ScalarConverter::getType(std::string str, int index)
{
	_type = isLiteral(str);
	if (_type)
	{
		_char_possible = false;
		_int_possible = false;
	}
	if (!_type)
	{
		if (isChar(str)) _type = CHAR_TYPE;
		if (isInt(str, index))	_type = INT_TYPE;
		isFloatOrDouble(str, index);
		if (!_type)
		{
			//Change it to invalid
		}
	}
}

void ScalarConverter::isSign(std::string str, int &index)
{
	if (str[index] == '+' || str[index] == '-')
	{
		_sign = str[index];
		index++;
	}
}

int ScalarConverter::isLiteral(std::string &str)
{
	if (!str.compare("inff") || !str.compare("+inff"))
	{
		str = std::numeric_limits<float>::max();
		return inff;
	}
	else if (!str.compare("-inff"))
	{
		str = std::numeric_limits<float>::min();
		return inff;
	}
	if (!str.compare("inf") || !str.compare("+inf"))
	{
		str = std::numeric_limits<double>::max();
		return inf;
	}
	else if (!str.compare("-inf"))
	{
		str = std::numeric_limits<double>::max();
		return inf;
	}
	if (!str.compare("nan"))
	{
		str = std::numeric_limits<double>::quiet_NaN();
		return nand;
	}
	return 0;
}

bool ScalarConverter::isChar(std::string str)
{
	if (str.length() == 1 && std::isalpha(str[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(std::string str, int &index)
{
	if (str.length() > 1)
		_char_possible = false;
	while (str[index])
	{
		if (std::isdigit(str[index]))
			index++;
		else
			return false;
	}
	return true;
}

bool ScalarConverter::isFloatOrDouble(std::string str, int &index)
{
	if (str.find('.') != std::string::npos)
	{
		if (str[index] == '.')
		{
			_found_dot = true;
			index++;
		}
		while (str[index])
		{
			if (std::isdigit(str[index]))
				index++;
			else if (_found_dot && str[index] == 'e' && !_found_scientific_notation)
			{
				_found_scientific_notation = true;	
				index++;
				if (str[index] == '+' || str[index] == '-')
					index++;
			}
			else if (str[index] == 'f' && str[index + 1] == '\0' && std::isdigit(str[index - 1]))
			{
				_type = FLOAT_TYPE;
				return true;
			}
			else if (str[index + 1] == '\0')
			{
				_type = DOUBLE_TYPE;
				return true;
			}
			else
				return false;
		}
	}
	return false;
}

// bool ScalarConverter::isDouble(std::string str, int &index)
// {

// 	while (str[index])
// 	{
// 		if (std::isdigit(str[index]))
// 			index++;
// 		else if (str[index] == '.')
// 		{
// 			if (_found_dot == false)
// 			{
// 				_found_dot = true;
// 				index++;
// 			}
// 			else if (_found_dot == true)
// 				return false;
// 		}
// 		else
// 			return false;
// 	}
// 	return true;
// }

// void ScalarConverter::check_limits(std::string str)
// {

// }

void	ScalarConverter::castToChar(std::string str)
{
	std::cout << "char: ";
	if (!_char_possible && !isprint(str.at(0)))
		std::cout << "Non displayable" << std::endl;
	else if (_char_possible && !isprint(str.at(0)))
		std::cout << "Non displayable" << std::endl;
	else if (!_char_possible || str.length() > 1)
		std::cout << "impossible" << std::endl;
	if (str.length() == 1 && _char_possible)
		std::cout << (static_cast <char>(str.at(0))) << std::endl;
}

void	ScalarConverter::castToInt(std::string str)
{
	std::cout << "int: ";
	if (!_int_possible)
		std::cout << "impossible" << std::endl;
	if (_int_possible)
	try
	{
		std::cout << (static_cast <int> (std::stoi(str.c_str()))) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Invalid input" << std::endl;
	}
}

void	ScalarConverter::castToFloat(std::string str)
{
	std::cout <<  "float: ";
	if (_float_possible)
	{
		try
		{
			std::cout << (static_cast <float> (std::stof(str.c_str())));
			std::cout << "f" << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Invalid input" << std::endl;
		}
	}
	if (!_float_possible)
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::castToDouble(std::string str)
{
	std::cout <<  "double: ";
	if (_double_possible)
	{
	try
	{
		double result = std::stod(str);
		// Check for overflow or underflow
		if (_type != inf && (result >= DBL_MAX || result <= DBL_MIN))
		{
			throw std::out_of_range("Overflow");
		}
		std::cout << static_cast<double>(result) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Out of range" << std::endl;
	}
	}
	if (!_double_possible)
		std::cout << "impossible" << std::endl;
}
