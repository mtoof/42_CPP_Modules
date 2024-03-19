/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:42 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/19 19:22:33 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"
#include <functional>

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &rhs)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = rhs;
}

Intern &Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

using FormCreatorFunction = std::function<std::shared_ptr<AForm>(std::string)>;

static std::shared_ptr<AForm> create_shrubbery(std::string form_name)
{
	return std::make_shared<ShrubberyCreationForm>(form_name);
}

static std::shared_ptr<AForm> create_roboto(std::string form_name)
{
	return std::make_shared<RobotomyRequestForm>(form_name);
}

static std::shared_ptr<AForm> create_presidential(std::string form_name)
{
	 return std::make_shared<PresidentialPardonForm>(form_name);
}

std::shared_ptr<AForm> Intern::makeForm(std::string form_name, std::string target)
{
	if (form_name.empty() || target.empty())
	{
		std::cout << RED "The Intern can't make any Forms without having names for Form and target" RESET << std::endl;
		return nullptr;
	}

	FormCreatorFunction formCreators[] = {
		create_shrubbery,
		create_roboto,
		create_presidential
	};

	std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	for (int index = 0; index < 3; index++)
	{
		if (form_name == forms[index])
		{
			std::cout << GREEN "Intern creates " << BLUE << form_name << GREEN " for " BLUE << target << RESET << std::endl;
			return formCreators[index](target);
		}
	}
	std::cout << RED "Intern couldn't create the " << BLUE << form_name << RED " because the form is undefined and not exist." RESET << std::endl;
	return (nullptr);
}
