/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:57:21 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/11 22:15:37 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


short ScalarConverter::_type = 0;
char ScalarConverter::_sign = '\0';
bool ScalarConverter::_char_possible = true;
bool ScalarConverter::_int_possible = true;
bool ScalarConverter::_float_possible = true;
bool ScalarConverter::_double_possible = true;
bool ScalarConverter::_found_dot = false;

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
	int index = 0;
	isSign(str, index);
	getType(str, index);
	std::cout << _type << " " << str << std::endl;
}

void ScalarConverter::getType(std::string str, int index)
{
	_type = isLiteral(str);
	std::cout << _type;
	if (_type)
	{
		_char_possible = false;
		_int_possible = false;
	}
	if (!_type)
	{
		if (isChar(str)) _type = CHAR_TYPE;
		if (isInt(str, index))	_type = INT_TYPE;
		if (isFloat(str, index))	_type = FLOAT_TYPE;
		if (isDouble(str, index)) _type = DOUBLE_TYPE;
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

int ScalarConverter::isLiteral(std::string str)
{
	if (!str.compare("+inff") || !str.compare("-inff"))
		return inff;
	if (!str.compare("+inf") || !str.compare("-inf"))
		return inf;
	if (!str.compare("nan"))
		return nan;
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
	while (str[index])
	{
		if (std::isdigit(str[index]))
			index++;
		else
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(std::string str, int &index)
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
		else if (str[index] == 'f' && str[index + 1] == '\0' && std::isdigit(str[index - 1]))
			return true;
		else
			return false;
	}
	return false;
}

bool ScalarConverter::isDouble(std::string str, int &index)
{

	while (str[index])
	{
		if (std::isdigit(str[index]))
			index++;
		else if (str[index] == '.')
		{
			std::cout << std::boolalpha << _found_dot << std::endl;
			if (_found_dot == false)
			{
				_found_dot = true;
				index++;
			}
			else if (_found_dot == true)
				return false;
		}
		else
			return false;
	}
	return true;
}

void ScalarConverter::printout(std::string str)
{
	if (!_char_possible)
		std::cout << "impossible" << std::endl;
	else if (_char_possible && !isprint(str.at(0)))
		std::cout << "Non displayable" << std::endl;
	if (!_int_possible)
		std::cout << "impossible" << std::endl;
}