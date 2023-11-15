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
	brain = new Brain();
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
	{
		brain = new Brain(*rhs.brain);
		_type = rhs._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Constructor Called." << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << _type << " says Meow" << std::endl;
}

void	Cat::setAnIdea(unsigned int index, std::string idea)
{
	if (index > 99)
	{
		std::cout << "Wrong index" << std::endl;
		return ;
	}
	brain->setAnIdea(index, idea);
}

std::string Cat::getAnIdea(unsigned int index)
{
	if (index > 99)
	{
		std::cout << "Wrong index" << std::endl;
		return NULL;
	}
	return (brain->getAnIdea(index));
}
