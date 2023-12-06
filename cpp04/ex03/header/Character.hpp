/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:08:01 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/06 18:41:43 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACHTER_HPP
#define CHARACHTER_HPP

#include "ICharacter.hpp"

class AMateria;

class Character:public ICharacter
{
private:
	std::string _name;
	AMateria* 	_inventory[4];
public:
	Character();
	Character(std::string name);
	Character(const Character &rhs);
	Character &operator=(const Character &rhs);
	~Character();

	virtual std::string const &getName() const;
	virtual void equip(AMateria* materia);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif