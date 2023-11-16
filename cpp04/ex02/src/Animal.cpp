/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:01:20 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/15 15:52:24 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << "Animal Default Constructor Called." << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	std::cout << "Animal Copy Constructor Called." << std::endl;
	*this = rhs;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal Copy Assignment operator Called." << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Constructor Called." << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << _type << " says I'm an animal" << std::endl;
}