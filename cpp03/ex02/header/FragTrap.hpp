/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:17:24 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/08 17:29:01 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(std::string name_val);
	~FragTrap();
	FragTrap(const FragTrap &rhs);
	FragTrap &operator=(const FragTrap &rhs);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int getHitPoint() const;
	void healthReport() const;
	void highFivesGuys(void) const;
};

#endif