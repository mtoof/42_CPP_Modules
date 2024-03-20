/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/20 12:05:52 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/Intern.hpp"
#include "colour.hpp"

int main()
{
	try
	{
		Intern jimmy;
		std::shared_ptr<AForm> test_form = jimmy.makeForm("test", "test2");
		Bureaucrat tony("Tony", 5);
		std::shared_ptr<AForm> tommy_pardon = jimmy.makeForm("presidential pardon", "Tommy");
		tony.signForm(*tommy_pardon);
		tony.executeForm(*tommy_pardon);
		std::shared_ptr<AForm> robotomy = jimmy.makeForm("robotomy request", "Tommy");
		tony.signForm(*robotomy);
		tony.executeForm(*robotomy);
		std::shared_ptr<AForm> shrubbery = jimmy.makeForm("shrubbery creation", "Tommy");
		tony.signForm(*shrubbery);
		tony.executeForm(*shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}