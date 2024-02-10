/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:57:31 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/10 16:06:31 by mtoof            ###   ########.fr       */
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
	CHAR_TYPE,
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

	static void getType(std::string str);

	static short _type;
	static char	_sign;
	
public:
	static void converter(std::string str);
};

#endif