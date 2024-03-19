/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:30:32 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/19 18:05:20 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("No_name", 145, 137),_target("No_location")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm argument constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs): AForm(rhs), _target(rhs._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::cout << GREEN "ShrubberyCreationForm execute called" RESET << std::endl;
	if (this->getSignature() == true)
	{
		if (executor.getGrade() <= (int)this->getGradeToExecute())
		{
			std::stringstream out_string;
			std::ofstream executed_form_file(_target + "_shrubbery");
			if (!executed_form_file)
			{
				std::cerr << "Couldn't create the file" << std::endl;
				return;
			}
				out_string << "			      ,@@@@@@@," << std::endl;
				out_string << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
				out_string << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
				out_string << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
				out_string << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
				out_string << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
				out_string << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
				out_string << "       |o|        | |         | |" << std::endl;
				out_string << "       |.|        | |         | |" << std::endl;
				out_string << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
				std::cout << GREEN << this->_target <<"_shrubbery form executed successfully." RESET << std::endl;
				executed_form_file << out_string.str();
				executed_form_file.close();
		}
		else
			throw GradeTooLowException();
	}
	else
		std::cerr << RED << this->_target << "_shrubbery form has not yet been signed." RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
