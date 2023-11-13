/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:57:48 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/13 18:43:40 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("unknown_clap_name"), _name("unknown")
{
	ScavTrap::set_energyPoint();
	std::cout << "Diamond Default Constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name_value): ClapTrap(name_value + "_clap_name"), ScavTrap(name_value), FragTrap(name_value), _name(name_value)
{
	ScavTrap::set_energyPoint();
	std::cout << "Diamond Argument Constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
{
	*this = rhs;
	std::cout << "Diamond copy Constructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		this->ClapTrap::_hitPoint = rhs.ClapTrap::_hitPoint;
		this->ClapTrap::_energyPoint = rhs.ClapTrap::_energyPoint;
		this->ClapTrap::_attackDamage = rhs.ClapTrap::_attackDamage;
	}
	std::cout << "Diamond copy assignment called." << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond destructor called." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << _name << " its ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::healthReport() const
{
	std::cout << "DiamondTrap " << DiamondTrap::_name << " has " << this->ClapTrap::_hitPoint <<" amount of hitPoint, " << "energy level is " << this->ClapTrap::_energyPoint << " and attachDamage is " << this->ClapTrap::_attackDamage << std::endl;
}
