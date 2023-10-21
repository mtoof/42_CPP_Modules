/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:28:32 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/21 21:19:33 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact();
	~Contact();
	std::string const&get_FirstName() const;
	std::string	const&get_LastName() const;
	std::string	const&get_NickName() const;
	std::string	const&get_PhoneNumber() const;
	std::string	const&get_DarkestSecret() const;
	void		display(void) const;
	bool		isValid(void) const;
	void		addContact(void) const;
};

#endif
