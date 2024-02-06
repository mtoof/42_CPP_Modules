/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:52:14 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/06 13:24:22 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signature;
	const unsigned int _grade_required_to_sign;
	const unsigned int _grade_required_to_execute;

public:
	Form();
	Form(std::string name_val, unsigned int grade_to_sign, unsigned int grade_to_execute);
	Form(const Form &rhs);
	Form &operator=(const Form &form);
	~Form();
	std::string getName() const;
	bool getSignature() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);
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

std::ostream & operator<<(std::ostream & o, Form const &input);

#endif