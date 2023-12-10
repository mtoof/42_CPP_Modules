/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:01:20 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/13 18:02:22 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor Called." << std::endl;
	_type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &rhs)
{
	std::cout << "Dog Copy Constructor Called." << std::endl;
	this->brain = NULL;
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog Copy Assignment operator Called." << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
		delete this->brain;
		if (rhs.brain)
			brain = new Brain(*rhs.brain);
		else
			brain = NULL;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Constructor Called." << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << _type << " says Woof woof" << std::endl;
}

void	Dog::setAnIdea(unsigned int index, std::string idea)
{
	if (index > 99)
	{
		std::cout << "Wrong index" << std::endl;
		return ;
	}
	brain->setAnIdea(index, idea);
}

std::string Dog::getAnIdea(unsigned int index)
{
	if (index > 99)
	{
		std::cout << "Wrong index" << std::endl;
		return NULL;
	}
	return (brain->getAnIdea(index));
}

void	Dog::getAllIdeas(void) const
{
	brain->getAllIdeas();
}