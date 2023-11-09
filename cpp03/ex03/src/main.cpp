/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:00:54 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/09 17:34:53 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/DiamondTrap.hpp"

int main()
{
	FragTrap	fury("Fury");
	FragTrap	iron_man("Iron man");
	DiamondTrap	ghule("Ghule");

	fury.attack("Iron man");
	iron_man.takeDamage(fury.get_attackDamage());
	iron_man.highFivesGuys();
	fury.set_attackDamage(100);
	fury.attack("Iron man");
	iron_man.takeDamage(fury.get_attackDamage());

	return (0);
}