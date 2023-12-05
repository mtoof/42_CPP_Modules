/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:15:45 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/05 17:33:44 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor Called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice &rhs)
{
	std::cout << "Ice copy constructor Called" << std::endl;
	*this = rhs;
}

Ice &Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
}

Ice::~Ice()
{
	
}

AMateria* Ice::clone() const
{
	
}

void Ice::use(ICharacter& target)
{
	
}