/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:10:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/06 17:36:37 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name_val) :_name(name_val), _hit(10), _energy(10), _attack_damage(0) 	// Default Constructor
{
	
}

ClapTrap::ClapTrap(const ClapTrap &rhs) // Copy constructor
{
	*this = rhs;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) // Copy assignment operator
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit = rhs._hit;
		this->_energy = rhs._energy;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name << "attacks " << target \
	<< " , causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	
}
