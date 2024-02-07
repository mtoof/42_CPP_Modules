/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:12:42 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/07 18:02:55 by mtoof            ###   ########.fr       */
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

std::shared_ptr<AForm> Shrub_form(std::string const target) {return std::make_shared<ShrubberyCreationForm>(target);}
std::shared_ptr<AForm> Presidential_form(std::string const target) {return std::make_shared<PresidentialPardonForm>(target);}
std::shared_ptr<AForm> Robotomy_request(std::string const target) {return std::make_shared<RobotomyRequestForm>(target);}


// template<typename Derived>
// std::shared_ptr<AForm> make_shared_ptr(const std::string& class_name, const std::string& target) {
// 	return std::make_shared<Derived>(target);


#define MAKE_FORM(Name) [](const std::string& target) -> std::shared_ptr<AForm> { return make_shared_ptr<Name>(target); }

std::shared_ptr<AForm> Intern::makeForm(std::string form_name, std::string target)
{
	// std::string form_list[] = 
	// {
	// 	"shrubbery creation",
	// 	"robotomy request",
	// 	"presidential pardon"
	// };
	
	// Aform_function functions_list[] = {
	// 	Shrub_form,
	// 	Presidential_form,
	// 	Robotomy_request
	// };

	// static std::unordered_map<std::string, std::string> umap = {
	// 	{"shrubbery creation", "ShrubberyCreationForm"},
	// 	{"robotomy request", "RobotomyRequestForm"},
	// 	{"presidential pardon", "PresidentialPardonForm"}
    // };
	
    static std::unordered_map<std::string, std::function<std::shared_ptr<AForm>(const std::string&)>> formFactories = {
        {"shrubbery creation", MAKE_FORM(ShrubberyCreationForm)},
        {"robotomy request", MAKE_FORM(RobotomyRequestForm)},
        {"presidential pardon", MAKE_FORM(PresidentialPardonForm)}
    };
	
	if (form_name.empty() || target.empty())
	{
		std::cout << RED "The Intern can't make any Forms without having names for Form and target" RESET << std::endl;
		return nullptr;
	}

	// for(int item = 0; item < 3; item++)
	// {
	// 	if (form_list[item].compare(form_name) == 0)
	// 	{
	// 		std::cout << GREEN "Intern creates " << BLUE << form_name << GREEN " for " BLUE << target <<RESET << std::endl;
	// 		return functions_list[item](target);
	// 	}
	// }
	auto item = formFactories.find(form_name);
	if (item != formFactories.end())
	{
		std::cout << GREEN "Intern creates " << BLUE << form_name << GREEN " for " BLUE << target <<RESET << std::endl;
		return item->second(target);
	}
	std::cout << RED "Intern couldn't create the " << BLUE << form_name << RED " because the form does not exist." RESET << std::endl;
	return (nullptr);
}

https://www.phind.com/search?cache=p5pm2dbm627g56medd33jfsu
