/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:22:51 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/10 14:46:32 by mtoof            ###   ########.fr       */
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

void	FragTrap::highFivesGuys() const
{
	if (this->_hitPoint == 0)
	{
		std::cout << "FragTrap " << _name << " can't Hive five anyone, " << _name << " has already died in action." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " High fives, guys!" << std::endl;
}
