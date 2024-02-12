/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:57:31 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/12 22:58:07 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

typedef enum e_inputtype
{
	CHAR_TYPE = 1,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	inff,
	inf,
	nand,
} t_inputtype;

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &rhs);
	ScalarConverter &operator=(ScalarConverter const &rhs);
	~ScalarConverter();

	static void getType(std::string str, int index);
	static void isSign(std::string str, int &index);
	static bool isChar(std::string str);
	static bool isInt(std::string str, int &index);
	static bool isFloatOrDouble(std::string str, int &index);
	// static bool isDouble(std::string str, int &index);
	static int 	isLiteral(std::string &str);
	
	static void castToChar(std::string str);
	static void castToInt(std::string str);
	static void castToFloat(std::string str);
	static void castToDouble(std::string str);

	// static void check_limits(std::string str);

	static short _type;
	static char	_sign;
	static bool _found_dot;
	static bool _found_scientific_notation;
	static bool _char_possible;
	static bool _int_possible;
	static bool _float_possible;
	static bool _double_possible;
	static bool _char_invalid;
	static bool _int_invalid;
	static bool _float_invalid;
	static bool _double_invalid;
	
public:
	static void converter(std::string str);
};

#endif