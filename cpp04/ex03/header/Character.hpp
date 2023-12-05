/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:08:01 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/05 16:10:57 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACHTER_HPP
#define CHARACHTER_HPP

#include "ICharacter.hpp"

class Character:public ICharacter
{
private:
	std::string _name;
public:
	Character();
	Character(std::string name);
	Character(const Character &rhs);
	Character &operator=(const Character &rhs);
	~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif