/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:00:34 by mtoof             #+#    #+#             */
/*   Updated: 2023/12/10 13:54:02 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:

public:
	WrongCat();
	WrongCat(const WrongCat &rhs);
	WrongCat &operator=(const WrongCat &rhs);
	virtual ~WrongCat();
	void makeSound() const;
};

#endif