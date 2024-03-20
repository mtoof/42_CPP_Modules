/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:30:10 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/20 12:07:07 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(): AForm("No_name", 72, 45),_target("No_location")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45),_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs): AForm(rhs),_target(rhs._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << GREEN "RobotomyRequestForm execute called" RESET << std::endl;
	if (this->getSignature() == true)
	{
		if (executor.getGrade() <= (int)this->getGradeToExecute())
		{
			std::cout << BLUE "whirr, whirr." RESET << std::endl;
			// Create a random device to seed the generator
			std::random_device rd;
			// Initialize the random number generator
			std::mt19937 generator(rd());
			// Use the generator to produce random numbers
			std::uniform_int_distribution<int> distribution(0, 1);

			bool success = distribution(generator) == 1;
			if (success)
				std::cout << GREEN <<this->_target << " has been robotomized successfully." RESET << std::endl;
			else
				std::cout << RED "Robotomy has failed." RESET << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		std::cerr << RED << this->_target << "_RobotomyRequest form has not yet been signed." RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED "RobotomyRequestForm destructor called" RESET << std::endl;
}
