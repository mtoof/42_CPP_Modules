/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:10:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/07 16:59:27 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :_name(""), _hit(10), _energy(10), _attack_damage(0)// Default Constructor
{
	std::cout << "Default Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name_val) :_name(name_val), _hit(10), _energy(10), _attack_damage(0)// Default Constructor
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) // Copy constructor
{
	std::cout << "Copy Constructor called." << std::endl;
	*this = rhs;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) // Copy assignment operator
{
	std::cout << "Copy assignment operator called." << std::endl;
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
	std::cout << "Destructor for called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit == 0)
	{
		std::cout << "ClapTrap " << _name << " can't take any actions, " << _name << " has already been died in action." << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << _name << " no energy left to attack." << std::endl;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target \
		<< " , causing " << _attack_damage << " points of damage!" << std::endl;
	}
	--_energy;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit > 0)
	{
		std::cout << "ClapTrap " << _name << " hp was " << _hit;
		_hit -= amount;
		if (_hit > 0)
			std::cout << " received " << amount << " damage, hp is " << _hit << std::endl;
		else
			std::cout << " received " << amount << " damage and died in action." << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has already been died in action." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		if (_hit > 0)
		{
			--_energy;
			_hit += amount;
			std::cout << "ClapTrap " << _name << " gets " << amount << " hit point back." << std::endl;
			return ;
		}
		else
		std::cout << "ClapTrap " << _name << " has already been died in action. " << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy to repair. " << std::endl;
}

void	ClapTrap::set_attack_damage(unsigned int amount) // my own test
{
	this->_attack_damage += amount;
}
// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
// or energy points left.