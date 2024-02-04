/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:06:37 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/04 19:40:44 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colour.hpp"

int main()
{
	Bureaucrat tommy("Tommy", 12);
	ShrubberyCreationForm home("Home");
	home.beSigned(tommy);
	home.execute(tommy);
	return 0;
}