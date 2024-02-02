/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/02 21:27:49 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat a("Br_a", 12);
		std::cout << "br_a = " << a << std::endl;
		Bureaucrat c(a);
		c.incrementGrade();
		std::cout << "br_c = "<< c << std::endl;
		try
		{
			Bureaucrat b("Br_b", 155);
			std::cout << b << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& exp)
		{
			std::cout << exp.what() << std::endl;
		}
		Bureaucrat b = a;
		std::cout << b << std::endl;
		std::cout << "c = " << c << std::endl;
		for (int i = 0; i < 12; i++)
		{
			a.incrementGrade();
		}
	}
	catch (const Bureaucrat::GradeTooHighException& exp)
	{
		std::cout << exp.what() << std::endl;
	}
	return 0;
}