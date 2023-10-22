/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:28:32 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/22 15:59:23 by mtoof            ###   ########.fr       */
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
	std::string const&get_firstname() const;
	std::string	const&get_lastname() const;
	std::string	const&get_nickname() const;
	std::string	const&get_phonenumber() const;
	std::string	const&get_darkestsecret() const;
	void			display(void) const;
	bool			is_valid(void) const;
	static Contact	addContact(void);
};

#endif
