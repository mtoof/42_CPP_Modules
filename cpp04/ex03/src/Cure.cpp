/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:15:30 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/10 13:52:25 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cure.hpp"
#include "../header/ICharacter.hpp"
Cure::Cure()
{
	std::cout << "Cure Constructor called" << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure &rhs):AMateria(rhs)
{
	std::cout << "Cure Copy Constructor called" << std::endl;

	if (!rhs.getType().empty() && !this->getType().compare(rhs.getType()))
	{
		*this = rhs;
	}
	else if (this->getType().empty() && !rhs.getType().empty())
		this->_type = rhs.getType();
}

Cure &Cure::operator=(const Cure &rhs)
{
	std::cout << "Cure Copy Assignment operator called" << std::endl;

	if (!rhs.getType().empty() && !this->getType().empty() && !this->getType().compare(rhs.getType()))
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << GREEN "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}