/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:00:21 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/15 17:56:52 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>
#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal &rhs);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal(); 
	std::string getType() const;
	virtual void makeSound() const;
};


#endif