/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:47:15 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/26 09:20:09 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Zombie.hpp"

int main()
{
	int N = 10;
	Zombie* zombie_ptr = zombieHorde(N, "test");
	
	for (int index = 0;index < N; index++)
		zombie_ptr[index].announce();

	delete[] zombie_ptr;
	return (0);
}