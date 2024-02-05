/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:29:31 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/05 15:14:45 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(): AForm("No_name", false, 25, 5),_target("No_location")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", false, 25, 5),_target(target)
{
	std::cout << "PresidentialPardonForm argument constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs): AForm(rhs),_target(rhs._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator constructor called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << GREEN "PresidentialPardonForm execute called" RESET << std::endl;
	if (this->getSignature() == true)
	{
		if (executor.getGrade() <= (int)this->getGradeToExecute())
		{
			std::cout << BLUE << "Attention attention" RESET << std::endl;
			std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox." RESET << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		std::cerr << RED << this->_target << "_PresidentialPardon form has not yet been signed." RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED "PresidentialPardonForm destructor called" RESET << std::endl;
}
