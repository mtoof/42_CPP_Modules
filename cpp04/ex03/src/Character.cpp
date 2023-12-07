/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:45:52 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/07 16:12:46 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character()
{
	std::cout << "Character Constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
 		_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character Argument Constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
 		_inventory[i] = NULL;
}

Character::Character(const Character &rhs)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	if (this != &rhs)
		*this = rhs;
}

Character &Character::operator=(const Character &rhs)
{
	std::cout << "Character Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs.getName();
		for (int index = 0; index < 4; index++)
		{
			if (this->_inventory[index] != NULL)
				delete this->_inventory[index];
		}
		
		for (int index = 0; index < 4; ++index)
		{
			if (rhs._inventory[index] != NULL)
				_inventory[index] = rhs._inventory[index]->clone();
			else
				_inventory[index] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* materia)
{
	if (materia != NULL)
	{
		for (int idx = 0; idx < 4; idx++)
		{
			if (this->_inventory[idx] == NULL)
			{
				this->_inventory[idx] = materia->clone();
				std::cout << GREEN "Materia " << materia->getType() << " equipted successfully" RESET << std::endl;
				return;
			}
			else if (idx == 3 && this->_inventory[idx] != NULL)
				std::cout << RED "No empty slot to equip Materia" RESET << std::endl;
		}
	}
	else
		std::cout << RED "Materia can't be NULL" RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >=0 && idx < 4)
	{
		this->_inventory[idx] = NULL;
		std::cout << GREEN "Materia " << _inventory[idx]->getType() << " unequipted successfully" RESET << std::endl;

	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_inventory[idx] != NULL)
		{
			this->_inventory[idx]->use(target);
			return;
		}
		else
			std::cout << RED "Slot number " << idx << " is empty!" RESET << std::endl;
	}
	else
		std::cout << RED "Wrong slot index number" RESET << std::endl;
}