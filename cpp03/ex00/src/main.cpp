/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:00:54 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/07 16:59:15 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	fury("Fury");
	ClapTrap	iron_man("Iron man");

	fury.set_attack_damage(10); // my own test
	iron_man.set_attack_damage(10); // my own test
	fury.attack("Iron man");
	iron_man.attack("Fury");
	iron_man.takeDamage(10);
	fury.takeDamage(10);
	iron_man.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	iron_man.takeDamage(100);
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.beRepaired(100);
	return (0);
}