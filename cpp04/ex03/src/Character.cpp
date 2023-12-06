/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:45:52 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/06 18:53:48 by mtoof            ###   ########.fr       */
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
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = materia;
					break;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >=0 && idx < 4)
		this->_inventory[idx] = NULL;
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
			std::cout << "slot number " << idx << "is empty!" << std::endl;
	}
	else
		std::cout << "Wrong slot index number" << std::endl;
}