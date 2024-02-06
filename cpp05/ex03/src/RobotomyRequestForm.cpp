/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:30:10 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/05 14:30:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(): AForm("No_name", false, 72, 45),_target("No_location")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", false, 72, 45),_target(target)
{
	std::cout << "RobotomyRequestForm argument constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs): AForm(rhs),_target(rhs._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm copy assignment operator constructor called" << std::endl;
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
