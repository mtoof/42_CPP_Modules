/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:52:14 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/04 18:12:49 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signature;
	const unsigned int _grade_required_to_sign;
	const unsigned int _grade_required_to_execute;

public:
	AForm();
	AForm(std::string name_val, bool sign_val, unsigned int grade_to_sign, unsigned int grade_to_execute);
	AForm(const AForm &rhs);
	AForm &operator=(const AForm &form);
	virtual ~AForm();
	void beSigned(Bureaucrat &bureaucrat);
	std::string getName() const;
	bool getSignature() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream & operator<<(std::ostream & o, AForm const &input);

#endif