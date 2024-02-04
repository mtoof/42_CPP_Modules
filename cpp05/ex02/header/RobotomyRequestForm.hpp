/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:21:01 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/04 19:00:36 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &rhs);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	~RobotomyRequestForm();
	virtual void execute(const Bureaucrat &executor) const override;
};

#endif