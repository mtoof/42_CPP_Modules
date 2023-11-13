/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:00:54 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/13 17:34:59 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/DiamondTrap.hpp"

int main()
{
	DiamondTrap	ghul("Ghul");
	ghul.attack("Fury");
	ghul.healthReport();
	ghul.whoAmI();
	return (0);
}