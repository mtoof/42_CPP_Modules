/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/06 17:36:01 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "../header/Intern.hpp"
#include "colour.hpp"

int main()
{
	//Low grade ShrubberyCreationForm
	std::cout << BLUE  "First test" RESET << std::endl;
	try
	{
		Intern jimmy;
		std::shared_ptr<AForm> ptr = jimmy.makeForm("test", "test2");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE  "2nd test" RESET << std::endl;
	//Successfull sign and execute ShrubberyCreationForm
	try
	{
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << BLUE  "3rd test" RESET << std::endl;
	//Low grade Presidentialpardonform
	try
	{
		
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << BLUE  "4th test" RESET << std::endl;
	try
	{
		
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}