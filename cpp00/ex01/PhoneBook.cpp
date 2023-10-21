/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:54:49 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/21 21:53:15 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{	
}

PhoneBook::~PhoneBook()
{
}

t_userinput PhoneBook::command()
{
	std::string prompt;
	
	std::cout<<"> ";
	user_input(prompt);
	if (!prompt.compare("EXIT"))
		return (EXIT);
	if (!prompt.compare("ADD"))
		return (ADD);
	if (!prompt.compare("SEARCH"))
		return (SEARCH);
	else
	{
		std::cout<< "INVALID INPUT!"<<std::endl;
		std::cout<< "You can use ADD, SEARCH or EXIT command"<<std::endl;
		return (INVALID);
	}
	
}