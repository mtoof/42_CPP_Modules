/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/07 16:33:08 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "../header/Intern.hpp"
#include "colour.hpp"

int main()
{
	//Low grade ShrubberyCreationForm
	std::cout << BLUE  "First test" RESET << std::endl;
	try
	{
		Intern jimmy;
		std::shared_ptr<AForm> test_form = jimmy.makeForm("test", "test2");
		Bureaucrat tony("Tony", 5);
		std::shared_ptr<AForm> tommy_pardon = jimmy.makeForm("presidential pardon", "Tommy");
		tommy_pardon->beSigned(tony);
		tony.incrementGrade();
		tommy_pardon->execute(tony);
		std::shared_ptr<AForm> robotomy = jimmy.makeForm("robotomy request", "Tommy");
		robotomy->beSigned(tony);
		tony.incrementGrade();
		robotomy->execute(tony);
		std::shared_ptr<AForm> shrubbery = jimmy.makeForm("shrubbery creation", "Tommy");
		shrubbery->beSigned(tony);
		shrubbery->execute(tony);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}