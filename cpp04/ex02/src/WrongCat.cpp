/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:06:29 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/15 16:07:58 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat Default Constructor Called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs)
{
	std::cout << "WrongCat Copy Constructor Called." << std::endl;
	*this = rhs;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat Copy Assignment operator Called." << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Constructor Called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << _type << " say Mew" << std::endl;
}