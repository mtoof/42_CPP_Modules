/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:17 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/20 17:03:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include <memory>

class Intern
{
private:
	
public:
	Intern();
	Intern(Intern const &rhs);
	Intern &operator=(Intern const &rhs);
	~Intern();
	std::shared_ptr<AForm> makeForm(std::string form_name, std::string target);
};

#endif