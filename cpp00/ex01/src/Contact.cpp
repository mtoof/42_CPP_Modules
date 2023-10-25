/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:29:22 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/23 13:39:38 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{	
}

Contact Contact::addContact()
{
	Contact contact;

	std::cout<<"\n"<<std::flush;
	std::cout << "First name: "<<std::flush;
	user_input(contact.first_name);
	std::cout << "Last name: "<<std::flush;
	user_input(contact.last_name);
	std::cout << "Nickname: "<<std::flush;
	user_input(contact.nickname);
	std::cout << "Phone number: "<<std::flush;
	user_input(contact.phone_number);
	std::cout << "Darkest secret: "<<std::flush;
	user_input(contact.darkest_secret);
	std::cout<<"\n"<<std::flush;
	return(contact);
}

bool	Contact::is_valid() const
{
	if (first_name.empty() || last_name.empty() \
	|| nickname.empty() || phone_number.empty() \
	|| darkest_secret.empty())
		return (false);
	return (true);
}

std::string const&Contact::get_firstname() const
{
	return (first_name);
}

std::string	const&Contact::get_lastname() const
{
	return (last_name);
}

std::string	const&Contact::get_nickname() const
{
	return (nickname);
}

void	Contact::display(void) const
{
	std::cout<<"First name : " << first_name <<std::endl;
	std::cout<<"Last name : " << last_name <<std::endl;
	std::cout<<"Nickname : " << nickname <<std::endl;
	std::cout<<"Phone number: " << phone_number <<std::endl;
	std::cout<<"Darkest secret: " << darkest_secret <<std::endl;
}