/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:54:49 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/22 16:44:05 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), counter(0){}

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
	{
		add_contact();
		return (ADD);
	}
	if (!prompt.compare("SEARCH"))
	{
		search_contact();
		return (SEARCH);
	}
	else
	{
		std::cout<< "INVALID INPUT!"<<std::endl;
		std::cout<< "You can use only ADD, SEARCH or EXIT command"<<std::endl;
		return (INVALID);
	}
	
}

void	PhoneBook::add_contact(void)
{
	Contact contact = Contact::addContact();

	if (!contact.is_valid())
	{
		std::cout<< "\nERROR: Invalid contact!" <<std::endl;
		return ;
	}
	contacts[index] = contact;
	index = (index + 1) % max_size;
	if (counter < max_size)
		counter++;
}

void	PhoneBook::search_contact(void)
{
		
}