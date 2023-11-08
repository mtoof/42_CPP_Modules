/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:10:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/08 17:31:24 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :_name(""), _hitPoint(10), _energyPoint(10), _attackDamage(0)// Default Constructor
{
	std::cout << "ClapTrap Default Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name_val) :_name(name_val), _hitPoint(10), _energyPoint(10), _attackDamage(0)// Default Constructor
{
	std::cout << "ClapTrap Constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) // Copy constructor
{
	std::cout << "ClapTrap Copy Constructor called." << std::endl;
	*this = rhs;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) // Copy assignment operator
{
	std::cout << "ClapTrap Copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoint == 0)
	{
		std::cout << "ClapTrap " << _name << " can't take any actions, " << _name << " has already died in action." << std::endl;
		return ;
	}
	if (_energyPoint == 0)
	{
		std::cout << "ClapTrap " << _name << " no energy left to attack." << std::endl;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target \
		<< " , causing " << _attackDamage << " points of damage!" << std::endl;
		--_energyPoint;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint > 0)
	{
		std::cout << "ClapTrap " << _name << " hp was " << _hitPoint;
		_hitPoint -= amount;
		if (_hitPoint > 0)
			std::cout << " received " << amount << " damage, hp is " << _hitPoint << std::endl;
		else
		{
			std::cout << " received " << amount << " damage and died in action." << std::endl;
			_hitPoint = 0;
		}
	}
	else
		std::cout << "ClapTrap " << _name << " has already died in action." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint > 0)
	{
		if (_hitPoint > 0)
		{
			--_energyPoint;
			_hitPoint += amount;
			std::cout << "ClapTrap " << _name << " got " << amount << " hit point back." << std::endl;
			return ;
		}
		else
		std::cout << "ClapTrap " << _name << " has already died in action. " << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy to be repaired. " << std::endl;
}

void	ClapTrap::set_attackDamage(unsigned int amount) // my own test
{
	this->_attackDamage = amount;
}

int ClapTrap::get_attackDamage() const
{
	return (_attackDamage);
}

void	ClapTrap::healthReport() const
{
	std::cout << "ClapTrap " << _name << " has " << _hitPoint << " amount of hitPoint" << std::endl;
}
// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
// or energy points left.