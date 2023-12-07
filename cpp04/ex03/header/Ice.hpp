/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:59:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/07 15:54:13 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "colors.hpp"

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