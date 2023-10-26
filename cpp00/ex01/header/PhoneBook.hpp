/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:53:43 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/23 11:53:27 by mtoof            ###   ########.fr       */
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
	int			contact_index;
	int			counter;
	void 		add_contact(void);
	void		search_contact(void);
	void		print_contact_list(void) const;
public:
				PhoneBook();
				~PhoneBook();
	t_userinput	command();
};

void	user_input(std::string &prompt);

#endif