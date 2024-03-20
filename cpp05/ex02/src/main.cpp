/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/20 11:46:58 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/colour.hpp"

int main()
{
	//Low grade ShrubberyCreationForm
	std::cout << BLUE  "First test" RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 139);
		ShrubberyCreationForm district1("district1");
		bob.signForm(district1);
		bob.executeForm(district1);
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
		tommy.signForm(home);
		tommy.executeForm(home);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << BLUE  "3rd test" RESET << std::endl;
	//Low grade Presidentialpardonform
	try
	{
		Bureaucrat jane("Jane", 25);
		PresidentialPardonForm form_x1("Alex");
		jane.signForm(form_x1);
		jane.executeForm(form_x1);
		Bureaucrat James("James", 5);
		James.executeForm(form_x1);
		// alex.execute(James);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << BLUE  "4th test" RESET << std::endl;
	try
	{
		Bureaucrat jane("Jane", 72);
		RobotomyRequestForm office_lawn("office_lawn");
		jane.signForm(office_lawn);
		jane.executeForm(office_lawn);
		Bureaucrat james("James", 46);
		james.signForm(office_lawn);
		james.executeForm(office_lawn);
		Bureaucrat tommy("Tommy", 42);
		tommy.signForm(office_lawn);
		tommy.executeForm(office_lawn);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}