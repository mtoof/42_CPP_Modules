/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:47:15 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/25 19:15:08 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie foo("Foo");
	Zombie **zombie_ptr = new Zombie * [10];
	for (int i = 0; i < 10;i++)
		zombie_ptr[i] = newZombie("Random Zombie " + std::to_string(i));
	randomChump("Random");
	for (int i = 0; i < 10;i++)
		delete zombie_ptr[i];
	delete [] zombie_ptr;
	return (0);
}