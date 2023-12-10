/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:46:40 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/10 13:53:07 by mtoof            ###   ########.fr       */
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
	me->unequip(2);
	me->unequip(3);
	Character* tim = new Character("tim");
	tmp = src->createMateria("cure");
	tim->equip(tmp);
	tmp = NULL;
	tmp = src->createMateria("cure");
	tim->equip(tmp);
	tmp = NULL;
	tmp = src->createMateria("ice");
	tim->equip(tmp);
	tmp = NULL;
	tmp = src->createMateria("ice");
	tim->equip(tmp);
	tmp = NULL;
	tmp = src->createMateria("cure");
	tim->equip(tmp);
	delete tmp;
	tmp = NULL;
	tim->unequip(0);
	tim->unequip(1);
	tim->unequip(2);
	tim->unequip(3);
	tim->unequip(4);
	tmp = tim->pickup_item("ice");
	tim->equip(tmp);
	tmp = NULL;
	tmp = tim->pickup_item("ice");
	tim->equip(tmp);
	tmp = NULL;
	
	delete tim;
	delete bob;
	delete me;
	delete src;
	return 0;
}