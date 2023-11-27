/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:58:38 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/27 17:08:59 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon&		_weapon;
public:
	HumanA(std::string name_val, Weapon &weapon_type);
	~HumanA();
	void	attack();
};

#endif