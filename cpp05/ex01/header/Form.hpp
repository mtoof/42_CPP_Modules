/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:52:14 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/02 23:14:47 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

# define MIN_GRADE_TO_SIGN 20
# define MIN_GRADE_TO_EXECUTE 15

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
	Form(std::string name_val, bool sign_val, unsigned int grade_to_sign, unsigned int grade_to_execute);
	Form(const Form &rhs);
	Form &operator=(const Form &rhs);
	void beSigned(Bureaucrat &rhs);
	std::string getName() const;
	bool getSignature() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	~Form();
};

std::ostream & operator<<(std::ostream & o, Form const &input);

#endif