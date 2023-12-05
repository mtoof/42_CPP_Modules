/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:59:33 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/05 16:21:39 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
private:
	
public:
	Cure();
	Cure(const Cure &rhs);
	Cure &operator=(const Cure &rhs);
	~Cure();
	
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif