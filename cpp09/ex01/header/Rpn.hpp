/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:55:55 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/25 19:31:05 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <regex>
#include <sstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
class Rpn
{
private:
	std::stack<int> _numberStack;
	Rpn(const Rpn &rhs);
	Rpn &operator=(const Rpn &rhs);
	bool handleOperators(std::string &operatorstr);
	bool handleOperands(std::string &number);
	void print();
public:
	Rpn();
	~Rpn();
	bool parse(std::string expression);
};

#endif