/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:27:01 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/16 17:05:18 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called." << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	std::cout << "Brain Copy Constructor Called." << std::endl;
	*this = rhs;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain Copy Assignment operator Called." << std::endl;
	if (this != &rhs)
		for(unsigned int index = 0;index < 100;index++)
			this->ideas[index] = rhs.ideas[index];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Constructor Called." << std::endl;
}

void	Brain::setAnIdea(unsigned int index, std::string idea)
{
	if (index > 99)
	{
		std::cout << "wrong index" << std::endl;
		return ;
	}
	ideas[index] = idea;
}

std::string	Brain::getAnIdea(unsigned int index) const
{
	if (index > 99)
	{
		std::cout << "wrong index" << std::endl;
		return NULL;
	}
	return (ideas[index]);
}

void	Brain::getAllIdeas(void) const
{
	int index = 0;
	
	while (!ideas[index].empty())
	{
		std::cout << ideas[index] << std::endl;
		index++;
	}
}

