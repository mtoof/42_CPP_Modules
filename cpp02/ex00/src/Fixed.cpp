/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:42:20 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/09 11:53:18 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_number(0) //Default Constructor
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed_class) //copy Constructor
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = fixed_class;
}

Fixed	&Fixed::operator=(const Fixed &rhs) //Copy assignment operator
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_fixed_point_number = rhs.getRawBits();
	}
	return (*this);
}

 Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_number);	
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_number = raw;
}
