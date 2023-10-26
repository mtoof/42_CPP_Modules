/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:58:41 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/26 11:22:10 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
private:
	std::string _name;
	Weapon*		_weapon;
public:
	HumanB(std::string name_val);
	~HumanB();
	void	setWeapon(Weapon &weapon_type);
	void	attack();
};

#endif
