/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:01:20 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/13 18:02:22 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat Default Constructor Called." << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	std::cout << "Cat Copy Constructor Called." << std::endl;
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat Copy Assignment operator Called." << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Constructor Called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << _type << " says Meow" << std::endl;
}
