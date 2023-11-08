/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:22:51 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/08 17:57:27 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
	std::cout << "Default FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name_val):ClapTrap(name_val)
{
	_name = name_val;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs)
{
	*this = rhs;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoint = rhs._hitPoint;
		_energyPoint = rhs._energyPoint;
		_attackDamage = rhs._attackDamage;
	}
	std::cout << "FragTrap copy assignment called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoint == 0)
	{
		std::cout << "FragTrap " << _name << " can't take any actions, " << _name << " has already died in action." << std::endl;
		return ;
	}
	if (this->_energyPoint == 0)
	{
		std::cout << "FragTrap " << _name << " no energy left to attack." << std::endl;
		return ;
	}
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target \
		<< " , causing " << _attackDamage << " points of damage!" << std::endl;
		this->_energyPoint -= 1;
	}
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

void	FragTrap::highFivesGuys() const
{
	if (this->_hitPoint == 0)
	{
		std::cout << "FragTrap " << _name << " can't Hive five anyone, " << _name << " has already died in action." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " High fives, guys!" << std::endl;
}