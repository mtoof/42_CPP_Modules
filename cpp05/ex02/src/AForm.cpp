/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:53:13 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/04 18:12:40 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "colour.hpp"

AForm::AForm(): _name("No_name"), _signature(false), _grade_required_to_sign(42), _grade_required_to_execute(42)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string name_val, bool sign_val, unsigned int grade_to_sign, unsigned int grade_to_execute): 
_name(name_val), _signature(sign_val), _grade_required_to_sign(grade_to_sign), _grade_required_to_execute(grade_to_execute)
{
	std::cout << "AForm Default constructor called" << std::endl;
	if (this->getGradeToSign() < HIGHEST_GRADE || this->getGradeToExecute() < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (this->getGradeToSign() > LOWEST_GRADE || this->getGradeToExecute() > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &rhs):
_name(rhs._name), _signature(rhs._signature)
, _grade_required_to_sign(rhs._grade_required_to_sign)
, _grade_required_to_execute(rhs._grade_required_to_execute)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}
AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << "AForm Copy assignment constructor called" << std::endl;
	if (this != &rhs)
	{
		this->_signature = rhs.getSignature();
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " GREEN << this->getName() << RESET " Destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSignature() const
{
	return this->_signature;
}

unsigned int AForm::getGradeToSign() const
{
	return this->_grade_required_to_sign;
}

unsigned int AForm::getGradeToExecute() const
{
	return this->_grade_required_to_execute;
}

void AForm::beSigned(Bureaucrat &bureaucrate)
{
	if (this->_signature == false)
	{
		if (bureaucrate.getGrade() > (int)this->getGradeToSign())
			throw AForm::GradeTooLowException();
		else
			this->_signature = true;
	}
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return (RED "Grade is too high!" RESET);
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return (RED "Grade is too low!" RESET);
}

std::ostream &operator<<(std::ostream &out, AForm const &Aform)
{
	out << "AForm name: " << Aform.getName()
	<< " signature : " << std::boolalpha << Aform.getSignature()
	<< " grade to be signed off: " << Aform.getGradeToSign()
	<< " grade to be executed: " << Aform.getGradeToExecute();
	return out;
}