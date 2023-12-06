/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:34:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/06 18:20:34 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AMateria.hpp"
#include "../header/ICharacter.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria Argument constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &rhs)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	if (!rhs.getType().empty() && !this->getType().compare(rhs.getType()))
	{
		*this = rhs;
	}
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	std::cout << "AMateria Copy Assignment operator called" << std::endl;
	if (!rhs.getType().empty() && !this->getType().compare(rhs.getType()))
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used " << this->getType() << " on " << target.getName() << std::endl;
}
