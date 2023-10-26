/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:37:26 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/26 09:52:20 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable = " << &str << std::endl;
	std::cout << "The memory address held by stringPTR      = " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF      = " << &stringREF << std::endl;
	std::cout << "=================================================================" << std::endl;

	 std::cout << "The value of the string variable = " << str << std::endl;
	 std::cout << "The value of the stringPTR       = " << *stringPTR << std::endl;
	 std::cout << "The value of the stringREF       = " << stringREF << std::endl;
}