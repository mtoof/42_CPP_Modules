/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:00:54 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/13 18:19:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/DiamondTrap.hpp"

int main()
{
	DiamondTrap	*p1 = new DiamondTrap();
	p1->attack("Fury");
	p1->healthReport();
	p1->whoAmI();
	delete p1;
	return (0);
}