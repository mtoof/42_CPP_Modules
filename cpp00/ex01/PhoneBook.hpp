/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:53:43 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/21 20:52:54 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

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

void	user_input(std::string &prompt);

#endif
