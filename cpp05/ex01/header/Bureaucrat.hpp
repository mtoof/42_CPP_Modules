/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:20 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/08 12:29:38 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name_val, int grade_val);
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();
	
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);
	
	class GradeTooHighException: public std::exception
	{
		public:
		virtual const char* what() const noexcept;
	};
	class GradeTooLowException: public std::exception
	{
		public:
		virtual const char* what() const noexcept;
	};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &input);

#endif