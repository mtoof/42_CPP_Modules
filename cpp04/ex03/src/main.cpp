/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:46:40 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/08 14:59:21 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AMateria.hpp"
#include "../header/MateriaSource.hpp"
#include "../header/Character.hpp"
#include "../header/Ice.hpp"
#include "../header/Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = NULL;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = NULL;
	ICharacter* bob = new Character("bob");
	bob->equip(tmp);
	tmp = NULL;
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);
	tmp = me->pickup_item("ice");
	me->equip(tmp);
	me->unequip(2);
	me->unequip(3);

	delete bob;
	delete me;
	delete src;
	return 0;
}