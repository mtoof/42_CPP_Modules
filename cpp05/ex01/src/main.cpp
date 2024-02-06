/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/06 10:57:44 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"
#include "colour.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat_a("bureaucrat_a", 12);
		Form form_a("form_a10", false, 10, 5);
		form_a.beSigned(bureaucrat_a); // throw an exception
		bureaucrat_a.signForm(form_a); // Skipped this line
	}
	catch (Form::GradeTooLowException &excp)
	{
		std::cerr << excp.what() << std::endl;	
	}
	try
	{
		Bureaucrat bureaucrat_a("bureaucrat_a", 12);
		Form form_a("form_a10", false, 10, 5);
		bureaucrat_a.signForm(form_a);
		bureaucrat_a.incrementGrade();
		bureaucrat_a.incrementGrade();
		bureaucrat_a.signForm(form_a);
		form_a.beSigned(bureaucrat_a);
	}
	catch (Form::GradeTooLowException &excp)
	{
		std::cerr << excp.what() << std::endl;	
	}
	return 0;
}