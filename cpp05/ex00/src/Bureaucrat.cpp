/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:35 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/02 21:31:05 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colour.hpp"

Bureaucrat::Bureaucrat():_name("no name"), _grade(150)
{
	std::cout <<  "Bureaucrat " << GREEN << this->getName() << RESET " default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name_val, int grade_val): _name(name_val)
{
	std::cout << "Bureaucrat " << GREEN << this->getName() << RESET " argument constructor called" << std::endl;
	if (grade_val > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade_val < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade_val;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs): _name(rhs.getName()), _grade(rhs.getGrade())
{
	std::cout << "Bureaucrat " << GREEN << this->_name << RESET " copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
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
	std::cout << "Decrement called for " << GREEN << this->getName() << RESET << std::endl;
	this->_grade += 1;
	if (this->_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Increment called for " << GREEN << this->getName() << RESET << std::endl;
	this->_grade -= 1;
	if (this->_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return (RED "Grade is too high!" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return (RED "Grade is too low!" RESET);
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const &rhs)
{
	return (out << GREEN << rhs.getName() << RESET << ", bureaucrat grade " << GREEN << rhs.getGrade() << RESET);
}