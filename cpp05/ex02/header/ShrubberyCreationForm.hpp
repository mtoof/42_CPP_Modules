/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:21:04 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/04 19:15:55 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm();
	virtual void execute(const Bureaucrat &executor) const override;
};

#endif