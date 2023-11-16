/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:01:14 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/16 15:35:58 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap
{
protected:
	std::string _name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name_val);
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap &rhs);
	ClapTrap &operator=(const ClapTrap &rhs);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	virtual void healthReport() const; // my own test
	void set_attackDamage(unsigned int amount); // my own test
	void set_name(std::string name_value); // my own test
	int get_attackDamage() const; // my own test
	int get_energyPoint() const; // my own test
	int get_hitPoint() const; // my own test
};

#endif