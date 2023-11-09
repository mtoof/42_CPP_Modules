/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:57:48 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/09 17:44:28 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Diamond Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name_value): ClapTrap(name_value + "_clap_name")
{
	std::cout << "Diamond Constructor called" << std::endl;
	this->_name = name_value;
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs): ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "Diamond copy Constructor called" << std::endl;
	*this = rhs;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoint = rhs._hitPoint;
		_energyPoint = rhs._energyPoint;
		_attackDamage = rhs._attackDamage;
	}
	std::cout << "Diamond copy assignment called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << _name << "its ClapTrap name is " << ClapTrap::_name << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint > 0)
	{
		std::cout << "FragTrap " << _name << " hp was " << _hitPoint;
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
		std::cout << "FragTrap " << _name << " has already died in action." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint > 0)
	{
		if (_hitPoint > 0)
		{
			--_energyPoint;
			_hitPoint += amount;
			std::cout << "FragTrap " << _name << " got " << amount << " hit point back." << std::endl;
			return ;
		}
		else
		std::cout << "FragTrap " << _name << " has already died in action. " << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " has no energy to repair. " << std::endl;
}

int	FragTrap::getHitPoint() const
{
	return (_hitPoint);
}

void	FragTrap::healthReport() const
{
	std::cout << "FragTrap " << _name << " has " << _hitPoint << " amount of hitPoint" << std::endl;
}
