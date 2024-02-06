/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/06 11:04:43 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colour.hpp"

int main()
{
	//Low grade ShrubberyCreationForm
	std::cout << BLUE  "First test" RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 139);
		ShrubberyCreationForm haaga("Haaga");
		haaga.beSigned(bob);
		haaga.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE  "2nd test" RESET << std::endl;
	//Successfull sign and execute ShrubberyCreationForm
	try
	{
		Bureaucrat tommy("Tommy", 12);
		ShrubberyCreationForm home("Home");
		home.beSigned(tommy);
		home.execute(tommy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << BLUE  "3rd test" RESET << std::endl;
	//Low grade Presidentialpardonform
	try
	{
		Bureaucrat Jane("Jane", 25);
		PresidentialPardonForm form_x1("Alex");
		form_x1.execute(Jane);
		form_x1.beSigned(Jane);
		Bureaucrat James("James", 5);
		form_x1.execute(Jane);
		// alex.execute(James);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << BLUE  "4th test" RESET << std::endl;
	try
	{
		Bureaucrat Jane("Jane", 72);
		RobotomyRequestForm office_lawn("office_lawn");
		office_lawn.execute(Jane);
		office_lawn.beSigned(Jane);
		Bureaucrat James("James", 46);
		Bureaucrat tommy("Tommy", 42);
		office_lawn.execute(Jane);
		office_lawn.execute(tommy);
		office_lawn.execute(James);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}