/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:53:13 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/19 17:54:14 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colour.hpp"

Form::Form(): _name("No_name"), _signature(false), _grade_required_to_sign(42), _grade_required_to_execute(42)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string name_val, int grade_to_sign, int grade_to_execute): 
_name(name_val), _signature(false), _grade_required_to_sign(grade_to_sign), _grade_required_to_execute(grade_to_execute)
{
	std::cout << "Form Default constructor called" << std::endl;
	if (this->getGradeToSign() < HIGHEST_GRADE || this->getGradeToExecute() < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (this->getGradeToSign() > LOWEST_GRADE || this->getGradeToExecute() > LOWEST_GRADE)
		throw Form::GradeTooLowException();
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
	std::cout << "Form " GREEN << this->getName() << RESET " Destructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSignature() const
{
	return this->_signature;
}

int Form::getGradeToSign() const
{
	return this->_grade_required_to_sign;
}

int Form::getGradeToExecute() const
{
	return this->_grade_required_to_execute;
}

void Form::beSigned(Bureaucrat &bureaucrate)
{
	if (this->_signature == false)
	{
		if (bureaucrate.getGrade() > (int)this->getGradeToSign())
			throw Form::GradeTooLowException();
		else
			this->_signature = true;
	}
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return (RED "Grade is too high!" RESET);
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return (RED "Grade is too low!" RESET);
}


std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form name: " << form.getName()
	<< " signature : " << std::boolalpha << form.getSignature()
	<< " grade to be signed off: " << form.getGradeToSign()
	<< " grade to be executed: " << form.getGradeToExecute();
	return out;
}