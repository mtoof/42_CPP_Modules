/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:54:49 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/01 12:41:25 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_index(0), counter(0){}

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
		std::cout<< "You can use only ADD, SEARCH or EXIT command\n"<<std::endl;
		return (INVALID);
	}
	
}

void	PhoneBook::add_contact(void)
{
	Contact contact = Contact::addContact();

	if (!contact.is_valid())
	{
		std::cout<< "\nERROR: Invalid contact!\n" <<std::endl;
		return ;
	}
	std::cout<< "===================================" <<std::endl;
	std::cout<< "Added successfully!" <<std::endl;
	std::cout<< "===================================\n" <<std::endl;
	contacts[contact_index] = contact;
	contact_index = (contact_index + 1) % max_size;
	if (counter < max_size)
		counter++;
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::print_contact_list(void) const
{
	std::cout <<"\n"<< std::right<<std::setw(10)<<"Index"<<"|" \
	<<std::setw(10) << truncate("First name") << "|" \
	<<std::setw(10) << truncate("Last name") << "|" \
	<<std::setw(10) << truncate("Nickname")<<std::endl;
	for(int index = 0; index < counter; index++)
	{
		std::cout << std::right<<std::setw(10)<< index << "|" \
		<< std::setw(10) << truncate(contacts[index].get_firstname()) << "|" \
		<< std::setw(10) << truncate(contacts[index].get_lastname()) << "|" \
		<< std::setw(10) << truncate(contacts[index].get_nickname()) << std::endl;
	}
	std::cout<<"\n"<<std::endl;
}

int		my_stoi(std::string str)
{
	for(int	i = 0; i < (int)str.length(); i++)
	{
		if (i == 0 && (str.at(i) == '-' || str.at(i) == '+'))
			i++;
		if (!isdigit(str.at(i)))
			return (-1);
	}
	return (atoi(str.c_str()));
}

void	PhoneBook::search_contact(void)
{
	int			result_index;
	std::string input_index;

	print_contact_list();
	if (counter == 0)
	{
		std::cout << "\nThe phonebook is empty\n"<<std::endl;
		return ;
	}
	std::cout << "Contact index > ";
	user_input(input_index);
	result_index = -1;
	try {result_index = my_stoi(input_index);} catch(...){};
	if (result_index < 0 || result_index > counter - 1)
	{
		std::cout<<"Wrong index\n"<<std::endl;
		return ;
	}
	std::cout<<"\n"<<std::endl;
	contacts[result_index].display();
	std::cout<<"\n"<<std::endl;
}
