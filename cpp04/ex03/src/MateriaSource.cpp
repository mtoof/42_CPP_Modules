/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:23:25 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/07 16:00:15 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MateriaSource.hpp"
#include "../header/AMateria.hpp"

MateriaSource::MateriaSource():_counter(0)
{
	std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int index = 0; index < 4; index++)
	{
		if (this->_inventory[index] != NULL)
			delete this->_inventory[index];
	}
}

void MateriaSource::learnMateria(AMateria* learn)
{
	if (learn != NULL)
	{
		for (int index = 0; index < 4; index++)
		{
			if (this->_inventory[index] == NULL)
			{
				this->_inventory[index] = learn;
				std::cout << GREEN "Learned " << learn->getType() << " successfully" RESET << std::endl;
				break;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	AMateria* tmp = NULL;
	if (!type.empty())
	{
		for (int index = 0; index < 4;index++)
		{
			if (this->_inventory[index] != NULL && \
			!_inventory[index]->getType().compare(type))
			{
				tmp = _inventory[index]->clone();
				std::cout << GREEN "Created " << type << " successfully" RESET << std::endl;

				break;
			}
		}
	}
	return (tmp);
}