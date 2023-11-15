/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:00:02 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/15 18:15:42 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat &rhs);
	Cat &operator=(const Cat &rhs);
	virtual ~Cat();
	virtual void makeSound() const;
	void	setAnIdea(unsigned int index, std::string idea);
	std::string getAnIdea(unsigned int index);
};

#endif