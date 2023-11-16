/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:59:04 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/16 17:07:07 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog();
	virtual void makeSound() const;
	void	setAnIdea(unsigned int index, std::string idea);
	std::string getAnIdea(unsigned int index);
	void	getAllIdeas(void) const;
};

#endif