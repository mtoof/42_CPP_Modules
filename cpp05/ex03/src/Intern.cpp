/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:42 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/08 12:23:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"
#include <unordered_map>

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


#define MAKE_FORM(Name) \
    [](const std::string& target) -> std::shared_ptr<AForm> { return std::make_shared<Name>(target); }

std::shared_ptr<AForm> Intern::makeForm(std::string form_name, std::string target)
{
	if (form_name.empty() || target.empty())
	{
		std::cout << RED "The Intern can't make any Forms without having names for Form and target" RESET << std::endl;
		return nullptr;
	}
	
    static std::unordered_map<std::string, std::function<std::shared_ptr<AForm>(const std::string&)>> formFactories = {
        {"shrubbery creation", MAKE_FORM(ShrubberyCreationForm)},
        {"robotomy request", MAKE_FORM(RobotomyRequestForm)},
        {"presidential pardon", MAKE_FORM(PresidentialPardonForm)}
    };
	
	auto item = formFactories.find(form_name);
	if (item != formFactories.end())
	{
		std::cout << GREEN "Intern creates " << BLUE << form_name << GREEN " for " BLUE << target <<RESET << std::endl;
		return item->second(target);
	}
	std::cout << RED "Intern couldn't create the " << BLUE << form_name << RED " because the form is undefined and not exist." RESET << std::endl;
	return (nullptr);
}
