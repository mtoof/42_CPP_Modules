/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:00:56 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/26 11:16:42 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string weapon_type): _type(weapon_type)
{
		
}

Weapon::~Weapon()
{
	
}

void	Weapon::setType(std::string weapon_type)
{
	this->_type = weapon_type;
}

const std::string&	Weapon::getType(void) const
{
	return ((const std::string&) _type);	
}

