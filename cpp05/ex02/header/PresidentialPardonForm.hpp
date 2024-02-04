/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:20:58 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/04 19:00:40 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &rhs);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	~PresidentialPardonForm();
	virtual void execute(const Bureaucrat &executor) const override;
};

#endif