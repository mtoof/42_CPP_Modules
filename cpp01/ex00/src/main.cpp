/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:47:15 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/26 09:25:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie foo;
	foo.set_name("Foo");
	foo.announce();

	Zombie *zombie_ptr = NULL;
	zombie_ptr = newZombie("Zombie_ptr");
	zombie_ptr->announce();
	
	randomChump("Random");

	delete zombie_ptr;
	return (0);
}