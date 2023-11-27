/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:13:28 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/27 17:23:24 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name_val) :_name(name_val)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their bare hands!" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon_type)
{
	this->_weapon = &weapon_type;
}