/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:15:45 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/07 16:30:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Ice.hpp"
#include "../header/ICharacter.hpp"
Ice::Ice()
{
	std::cout << "Ice Constructor called" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice &rhs):AMateria(rhs)
{
	std::cout << "Ice Copy Constructor called" << std::endl;

	if (!rhs.getType().empty() && !this->getType().compare(rhs.getType()))
	{
		this->_type = rhs.getType();
	}
	else if (this->getType().empty())
		this->_type = rhs.getType();
}

Ice &Ice::operator=(const Ice &rhs)
{
	std::cout << "Ice Copy Assignment operator called" << std::endl;

	if (!rhs.getType().empty() && !this->getType().compare(rhs.getType()))
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << RED "* shoots an ice bolt at " << target.getName() << " *"  RESET << std::endl;
}