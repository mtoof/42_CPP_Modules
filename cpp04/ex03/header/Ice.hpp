/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:59:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/05 16:22:05 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
private:
	
public:
	Ice();
	Ice(const Ice &rhs);
	Ice &operator=(const Ice &rhs);
	~Ice();
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif