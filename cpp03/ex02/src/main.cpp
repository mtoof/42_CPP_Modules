/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:00:54 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/08 17:55:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FragTrap.hpp"

int main()
{
	FragTrap	fury("Fury");
	FragTrap	iron_man("Iron man");

	fury.attack("Iron man");
	iron_man.takeDamage(fury.get_attackDamage());
	iron_man.highFivesGuys();
	fury.set_attackDamage(100);
	fury.attack("Iron man");
	iron_man.takeDamage(fury.get_attackDamage());
	fury.attack("Iron man");
	iron_man.takeDamage(fury.get_attackDamage());
	fury.attack("Iron man");
	iron_man.takeDamage(fury.get_attackDamage());
	fury.attack("Iron man");
	iron_man.takeDamage(fury.get_attackDamage());
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	fury.attack("Iron man");
	iron_man.healthReport();
	iron_man.attack("fury");
	return (0);
}