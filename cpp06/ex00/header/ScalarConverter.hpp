/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:57:31 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/11 22:12:41 by mtoof            ###   ########.fr       */
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
	nan,
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
	static bool isFloat(std::string str, int &index);
	static bool isDouble(std::string str, int &index);
	static int isLiteral(std::string str);
	static void	printout(std::string str);
	static void castFromChar(char);
	static void castFromInt(std::string str);
	static void castFromFloat(std::string str);
	static void castFromDouble(std::string str);

	static short _type;
	static char	_sign;
	static bool _found_dot;
	static bool _char_possible;
	static bool _int_possible;
	static bool _float_possible;
	static bool _double_possible;
	
public:
	static void converter(std::string str);
};

#endif