/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:21:01 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/08 12:30:35 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &rhs);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	virtual ~RobotomyRequestForm();
	virtual void execute(const Bureaucrat &executor) const override;
};

#endif