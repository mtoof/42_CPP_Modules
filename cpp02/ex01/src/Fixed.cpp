/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:42:20 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/30 18:27:19 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Fixed.hpp"

Fixed::Fixed() : _fixed_point_number(0) //Default Constructor
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed_class) //copy Constructor
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = fixed_class;
}

Fixed::Fixed(const int ivalue) :  _fixed_point_number(ivalue << _fractional_bits)//Integer Constructor
{
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float fvalue) : _fixed_point_number(std::roundf(fvalue * (1 << _fractional_bits)))//Float Constructor
{
	std::cout << "Float Constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs) //Copy assignment Constructor
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	int	fixed_num = rhs.getRawBits();
	this->_fixed_point_number = fixed_num;
	return (*this);
}

 Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixed_point_number);	
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_number = raw;
}
float 	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_fixed_point_number) / (1 << _fractional_bits));
}

int 	Fixed::toInt( void ) const
{
	return (std::roundf(toFloat()));
}

std::ostream & operator<<(std::ostream & o, Fixed const &fixed)
{
	return (o << fixed.toFloat());
}