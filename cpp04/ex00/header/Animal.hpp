/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:00:21 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/16 18:02:18 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

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