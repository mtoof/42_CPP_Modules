/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:23:25 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/05 17:40:15 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MateriaSource.hpp"

MateriaSource::MateriaSource():_counter(0)
{
	std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* ptr)
{
	if (ptr != NULL)
	{
		_inventory[_counter] = ptr->clone();
		_counter++;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	
}