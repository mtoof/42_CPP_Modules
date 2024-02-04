/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:35 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/04 14:13:55 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colour.hpp"

Bureaucrat::Bureaucrat() : _name("no name"), _grade(150)
{
	std::cout << "Bureaucrat " << GREEN << this->getName() << RESET " default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name_val, int grade_val) : _name(name_val)
{
	std::cout << "Bureaucrat " << GREEN << this->getName() << RESET " argument constructor called" << std::endl;
	if (grade_val > LOWEST_GRADE)
	{
		this->_grade = 42;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade_val < HIGHEST_GRADE)
	{
		this->_grade = 42;
		throw Bureaucrat::GradeTooHighException();
	}
	_grade = grade_val;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : _name(rhs.getName()), _grade(rhs.getGrade())
{
	std::cout << "Bureaucrat " << GREEN << this->_name << RESET " copy constructor called" << std::endl;
	if (this->getGrade() > LOWEST_GRADE)
	{
		this->_grade = 42;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->getGrade() < HIGHEST_GRADE)
	{
		this->_grade = 42;
		throw Bureaucrat::GradeTooHighException();
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	if (this->getGrade() > LOWEST_GRADE)
	{
		this->_grade = 42;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->getGrade() < HIGHEST_GRADE)
	{
		this->_grade = 42;
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << "Bureaucrat " << GREEN << this->getName() << RESET " copy assingment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << GREEN << this->_name << RESET " destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Decrement grade called for " << GREEN << this->getName() << RESET << std::endl;
	if (this->_grade + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Increment grade called for " << GREEN << this->getName() << RESET << std::endl;
	if (this->_grade - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return (RED "Grade is too high!" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return (RED "Grade is too low!" RESET);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	return (out << GREEN << rhs.getName() << RESET << ", bureaucrat grade " << GREEN << rhs.getGrade() << RESET);
}