/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:53:13 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/02 23:20:27 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("No_name"), _signature(false), _grade_required_to_sign(MIN_GRADE_TO_SIGN), _grade_required_to_execute(MIN_GRADE_TO_EXECUTE)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string name_val, bool sign_val, unsigned int grade_to_sign, unsigned int grade_to_execute): 
_name(name_val), _signature(sign_val), _grade_required_to_sign(grade_to_sign), _grade_required_to_execute(grade_to_execute)
{
	std::cout << "Form Default constructor called" << std::endl;
	if (this->getGradeToSign() < HIGHEST_GRADE || this->getGradeToExecute() < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (this->getGradeToSign() > LOWEST_GRADE || this->getGradeToExecute() > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form const &rhs):
_name(rhs._name), _signature(rhs._signature)
, _grade_required_to_sign(rhs._grade_required_to_sign)
, _grade_required_to_execute(rhs._grade_required_to_execute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}
Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form Copy assignment constructor called" << std::endl;
	if (this != &rhs)
	{
		this->_signature = rhs.getSignature();
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSignature() const
{
	return this->_signature;
}

unsigned int Form::getGradeToSign() const
{
	return this->_grade_required_to_sign;
}

unsigned int Form::getGradeToExecute() const
{
	return this->_grade_required_to_execute;
}

void Form::beSigned(Bureaucrat &rhs)
{
	if (this->_signature == false)
	{
		if (rhs.getGrade() > (int)this->getGradeToSign())
			throw Bureaucrat::GradeTooLowException();
		this->_signature = true;
	}		
}

std::ostream &operator<<(std::ostream &out, Form const &rhs)
{
	out << "Form name: " << rhs.getName()
	<< " signature : " << std::boolalpha << rhs.getSignature()
	<< " grade to be signed off: " << rhs.getGradeToSign()
	<< " grade to be executed: " << rhs.getGradeToExecute();
	return out;
}