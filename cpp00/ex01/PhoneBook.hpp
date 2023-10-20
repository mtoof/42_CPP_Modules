/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:53:43 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/20 19:26:57 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

typedef enum e_userinput
{
	EXIT,
	ADD, 
	SEARCH,
	INVALID
}	t_userinput;

class PhoneBook
{
private:
	static		const int max_size = 8;
	Contact		contacts[max_size];
	int			counter;
	int			index;
	void 		add_contact();
	std::string search_contact();
public:
	PhoneBook();
	~PhoneBook();
	t_userinput	command();
};

#endif
