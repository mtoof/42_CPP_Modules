/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:56:56 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/25 21:00:31 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Rpn.hpp"

Rpn::Rpn()
{
}

Rpn::~Rpn()
{
}

Rpn::Rpn(const Rpn &rhs) : _numberStack(rhs._numberStack)
{
}

Rpn &Rpn::operator=(const Rpn &rhs)
{
	if (this != &rhs)
	{
		while (!_numberStack.empty())
			_numberStack.pop();
		_numberStack = rhs._numberStack;
	}
	return (*this);
}

bool Rpn::parse(std::string expression)
{
	int counter = 0;
	std::stringstream ss;
	ss << expression;
	std::string num;
	if (ss.str().empty())
	{
		std::cerr << RED "Error!!!" RESET << std::endl;
		return false;
	}
	while (!ss.eof())
	{
		counter++;
		ss >> num;
		if (num.length() == 1 && !isdigit(num[0])) // operators
		{
			if (!handleOperators(num))
				return false;
		}
		else
		{
			if (!handleOperands(num))
				return false;
		}
	}
	print();
	return true;
}

bool Rpn::handleOperators(std::string &operatorstr)
{
	std::regex format("[+\\-/*]");
	if (std::regex_match(operatorstr, format) && _numberStack.size() >= 2)
	{
		int first = _numberStack.top();
		_numberStack.pop();
		int second = _numberStack.top();
		_numberStack.pop();
		switch (operatorstr[0])
		{
		case '+':
			_numberStack.push(first + second);
			break;
		case '-':
			_numberStack.push(second - first);
			break;
		case '*':
			_numberStack.push(first * second);
			break;
		case '/':
			_numberStack.push(second / first);
			break;
		default:
			std::cerr << RED "Invalid character!!!" RESET << std::endl;
			return false;
			break;
		}
	}
	else
	{
		std::cerr << RED "Invalid expression!!!" RESET << std::endl;
		return false;
	}
	return true;
}

bool Rpn::handleOperands(std::string &number)
{
	try
	{
		for (int index = 0; number[index]; index++)
		{
			if (!std::isdigit(number[index]) && number[index] != '-')
			{
				std::cerr << RED "Error!!!" RESET << std::endl;
				return false;
			}
		}
		int result = std::stoi(number);
		if (result < 10)
			_numberStack.push(result);
		else
		{
			std::cerr << RED "Invalid Number!!!" RESET << std::endl;
			return false;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << RED "Invalid Number!!!" RESET << std::endl;
		return false;
	}
	return (true);
}

void Rpn::print()
{
	while (_numberStack.size())
	{
		if (_numberStack.size() == 1)
			std::cout << _numberStack.top() << std::endl;
		else
			std::cout << _numberStack.top() << " ";
		_numberStack.pop();
	}
}