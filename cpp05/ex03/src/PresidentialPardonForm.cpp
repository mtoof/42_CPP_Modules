/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:29:31 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/20 12:06:49 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(): AForm("No_name", 25, 5),_target("No_location")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5),_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs): AForm(rhs),_target(rhs._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
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
