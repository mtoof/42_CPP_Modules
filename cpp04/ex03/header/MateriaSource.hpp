/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:38:28 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/07 17:52:35 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>
#include "colors.hpp"

class MateriaSource:public IMateriaSource
{
private:
	AMateria* _inventory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &rhs);
	MateriaSource &operator=(const MateriaSource &rhs);
	~MateriaSource();
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const &type);
};

#endif