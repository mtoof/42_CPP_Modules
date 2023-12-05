/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:38:28 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/05 16:44:21 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource:public IMateriaSource
{
private:
	static	const int	Max = 4;
	int	_counter;
	AMateria* _inventory[Max];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &rhs);
	MateriaSource &operator=(const MateriaSource &rhs);
	~MateriaSource();
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif