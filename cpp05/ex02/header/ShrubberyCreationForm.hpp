/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:21:04 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/08 12:29:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"
#include <sstream>
#include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	virtual ~ShrubberyCreationForm();
	virtual void execute(const Bureaucrat &executor) const override;
};

#endif