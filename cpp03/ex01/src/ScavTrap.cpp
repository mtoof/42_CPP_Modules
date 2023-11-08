/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:53:24 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/08 15:33:12 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	std::cout << "Default ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name_val):ClapTrap(name_val)
{
	_name = name_val;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs)
{
	*this = rhs;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoint = rhs._hitPoint;
		_energyPoint = rhs._energyPoint;
		_attackDamage = rhs._attackDamage;
	}
	std::cout << "ScavTrap copy assignment called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoint == 0)
	{
		std::cout << "ScavTrap " << _name << " can't take any actions, " << _name << " has already died in action." << std::endl;
		return ;
	}
	if (this->_energyPoint == 0)
	{
		std::cout << "ScavTrap " << _name << " no energy left to attack." << std::endl;
		return ;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target \
		<< " , causing " << _attackDamage << " points of damage!" << std::endl;
		this->_energyPoint -= 1;
	}
}

void ScavTrap::guardGate()
{
	if (_hitPoint == 0)
	{
		std::cout << "ScavTrap " << _name << " can't be in Gate keeper mode. " << _name << " has already died in action." << std::endl;
		return ;
	}
	if (_energyPoint == 0)
	{
		std::cout << "ScavTrap " << _name << " no energy left to be in Gate keeper mode." << std::endl;
		return ;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
		this->_energyPoint -= 1;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint > 0)
	{
		std::cout << "ScavTrap " << _name << " hp was " << _hitPoint;
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
		std::cout << "ScavTrap " << _name << " has already died in action." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint > 0)
	{
		if (_hitPoint > 0)
		{
			--_energyPoint;
			_hitPoint += amount;
			std::cout << "ScavTrap " << _name << " got " << amount << " hit point back." << std::endl;
			return ;
		}
		else
		std::cout << "ScavTrap " << _name << " has already died in action. " << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " has no energy to repair. " << std::endl;
}

int	ScavTrap::getHitPoint() const
{
	return (_hitPoint);
}

void	ScavTrap::healthReport()
{
	std::cout << "ScavTrap " << _name << " has " << _hitPoint << " amount of hitPoint" << std::endl;
}