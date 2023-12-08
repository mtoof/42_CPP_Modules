/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:45:52 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/08 14:07:49 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character():_name("Default name")
{
	std::cout << "Character Default Constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
 		_inventory[i] = NULL;
	for (int i = 0; i < FLIMIT; ++i)
 		floor[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character Argument Constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
 		_inventory[i] = NULL;
	for (int i = 0; i < FLIMIT; ++i)
 		floor[i] = NULL;
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
		
		for (int index = 0; index < FLIMIT; index++)
		{
			if (this->floor[index] != NULL)
				delete this->floor[index];
		}
		
		for (int index = 0; index < 4; ++index)
		{
			if (rhs._inventory[index] != NULL)
				this->_inventory[index] = rhs._inventory[index]->clone();
			else
				this->_inventory[index] = NULL;
		}
		for (int index = 0; index < FLIMIT; ++index)
		{
			if (rhs.floor[index] != NULL)
				this->floor[index] = rhs.floor[index]->clone();
			else
				this->floor[index] = NULL;
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
	for (int i = 0; i < FLIMIT; i++)
	{
		if (this->floor[i] != NULL)
			delete this->floor[i];
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
				this->_inventory[idx] = materia;
				std::cout << GREEN "Materia " << materia->getType() << " equipted successfully" RESET << std::endl;
				return;
			}
			else if (idx == 3 && this->_inventory[idx] != NULL)
				std::cout << RED "No empty slot to equip Materia" RESET << std::endl;
		}
	}
	else
		std::cout << RED "equip: Materia can't be NULL" RESET << std::endl;
}

void Character::unequip(int idx)
{
	if ((idx >=0 && idx < 4) && this->_inventory[idx])
	{
		for (int index = 0; index < FLIMIT; index++)
		{
			if (floor[index] == NULL)
			{
				floor[index] = _inventory[index];
				break;
			}
		}
		std::cout << GREEN "Materia " << _inventory[idx]->getType() << " unequipted successfully" RESET << std::endl;
		this->_inventory[idx] = NULL;
	}
	else if ((idx >=0 && idx < 4) && this->_inventory[idx] == NULL)
		std::cout << RED "unequip: Can't unequip, Slot number " << idx << " is empty" RESET << std::endl;
	else
		std::cout << RED "unequip: Wrong index number" RESET << std::endl;
		
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
			std::cout << RED "use: Slot number " << idx << " is empty!" RESET << std::endl;
	}
	else
		std::cout << RED "use: Wrong slot index number" RESET << std::endl;
}

AMateria* Character::pickup_item(const std::string item_name)
{
	AMateria* item = NULL;
	if (!item_name.empty())
	{
		for (int index = 0; index < FLIMIT; index++)
		{
			if (floor[index] != NULL && !floor[index]->getType().empty() && \
			!floor[index]->getType().compare(item_name))
			{
				item = floor[index];
				std::cout << GREEN "Picked up "<< item_name << " Materia successfully" RESET << std::endl;
				floor[index] = NULL;
				break;
			}
			else if (index == FLIMIT - 1)
				std::cout << RED "Coudn't find the item on the floor" RESET << std::endl;
		}
	}
	return (item);
}