/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/03 21:23:06 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colour.hpp"

int main()
{
	Bureaucrat bureaucrat_a("bureaucrat_a", 12);
	Form form_a("form_a10", false, 10, 5);
	try
	{
		form_a.beSigned(bureaucrat_a); // throw an exception
		bureaucrat_a.signForm(form_a); // Skipped this line
	}
	catch (Form::GradeTooLowException &excp)
	{
		std::cout << excp.what() << std::endl;	
	}
	bureaucrat_a.signForm(form_a);
	bureaucrat_a.incrementGrade();
	bureaucrat_a.incrementGrade();
	bureaucrat_a.signForm(form_a);
	try
	{
		form_a.beSigned(bureaucrat_a);
	}
	catch (Form::GradeTooLowException &excp)
	{
		std::cout << excp.what() << std::endl;	
	}
	return 0;
}