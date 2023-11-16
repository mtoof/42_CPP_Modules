/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:01:14 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/16 18:02:53 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string _name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamage;
	
public:
	ClapTrap();
	ClapTrap(std::string name_val);
	~ClapTrap();
	ClapTrap(const ClapTrap &rhs);
	ClapTrap &operator=(const ClapTrap &rhs);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void set_attackDamage(unsigned int amount); // my own test
	int get_attackDamage() const; // my own test
	void healthReport() const;
};


#endif