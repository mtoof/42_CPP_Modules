/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:57:48 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/10 19:20:41 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
	std::cout << "Diamond Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name_value): ClapTrap(name_value + "_clap_name"), _name(name_value)
{
	std::cout << "Diamond Constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
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

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << _name << " its ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::healthReport() const
{
	std::cout << "DiamondTrap " << DiamondTrap::_name << " has " << DiamondTrap::_hitPoint << " amount of hitPoint, " << "energy level is " << DiamondTrap::_energyPoint << " and attachDamage is " << DiamondTrap::_attackDamage << std::endl;
}
