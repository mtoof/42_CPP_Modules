/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/04 14:13:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colour.hpp"

int main()
{
	Bureaucrat bureaucrat_a("br_a", 1);
	Bureaucrat bureaucrat_b("br_b", 150);
	// Grade is too high for bureaucrat_a
	try
	{
		bureaucrat_a.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &exc) 
	{
		std::cerr << exc.what() << std::endl;
	}
	// Grade is too low for bureaucrat_b
	try
	{
		bureaucrat_b.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &exc) 
	{
		std::cerr << exc.what() << std::endl;
	}
	//copy assignment operator
	bureaucrat_a = bureaucrat_b;
	std::cout << BLUE "print bureaucrat_a details, name= " << bureaucrat_a.getName() << " grade= " << bureaucrat_a.getGrade() << RESET << std::endl;
	//copy constructor
	Bureaucrat bureaucrat_c(bureaucrat_a);
	std::cout << BLUE "print bureaucrat_c details, name= " << bureaucrat_c.getName() << " grade= " << bureaucrat_c.getGrade() << RESET << std::endl;
	return 0;
}