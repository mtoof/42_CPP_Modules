/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:30:15 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/13 16:58:47 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name_val);
	~ScavTrap();
	ScavTrap(const ScavTrap &rhs);
	ScavTrap &operator=(const ScavTrap &rhs);
	virtual void attack(const std::string& target);
	void guardGate();
};


#endif