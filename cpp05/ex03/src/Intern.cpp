/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:42 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/06 17:40:35 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &rhs)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = rhs;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}


Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

std::shared_ptr<AForm> Shrub_form(std::string const target) {return std::make_shared<ShrubberyCreationForm>(target);}
std::shared_ptr<AForm> Presidential_form(std::string const target) {return std::make_shared<ShrubberyCreationForm>(target);}
std::shared_ptr<AForm> Robotomy_request(std::string const target) {return std::make_shared<ShrubberyCreationForm>(target);}

std::shared_ptr<AForm> Intern::makeForm(std::string form_name, std::string target)
{
	std::string form_list[] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	Aform_function functions_list[] = {
		Shrub_form,
		Presidential_form,
		Robotomy_request
	};
	
	if (form_name.empty() || target.empty())
	{
		std::cout << RED "The Intern can't make any Forms without having names for Form and target" RESET << std::endl;
		return nullptr;
	}

	for(int item = 0; item < 3; item++)
	{
		if (form_list[item].compare(form_name) == 0)
		{
			std::cout << GREEN "Intern creates " << BLUE << form_name << RESET << std::endl;
			return functions_list[item](target);
		}
	}
	std::cout << RED "Intern couldn't create the " << BLUE << form_name << RED " because the form does not exist." RESET << std::endl;
	return (nullptr);
}
