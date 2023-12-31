/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:00:54 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/08 15:31:41 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	fury("Fury");
	ClapTrap	iron_man("Iron man");

	fury.set_attackDamage(10); // my own test
	iron_man.set_attackDamage(10); // my own test
	fury.attack("Iron man");
	iron_man.takeDamage(fury.get_attackDamage());
	iron_man.healthReport();
	iron_man.attack("Fury");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.beRepaired(100);
	return (0);
}