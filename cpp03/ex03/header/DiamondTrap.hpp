/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:33:28 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/16 15:36:44 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../header/FragTrap.hpp"
#include "../header/ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name_value);
	DiamondTrap(const DiamondTrap &rhs);
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap();
	virtual void	healthReport() const; // my own test
	void whoAmI();
};

#endif