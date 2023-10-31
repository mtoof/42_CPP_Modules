/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:42:20 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/31 16:06:18 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Fixed.hpp"

Fixed::Fixed() : _fixed_point_number(0) //Default Constructor
{
}

Fixed::Fixed(const Fixed &fixed_class) //copy Constructor
{
	*this = fixed_class;
}

Fixed::Fixed(const int ivalue) :  _fixed_point_number(ivalue << _fractional_bits)//Integer Constructor
{
}

Fixed::Fixed(const float fvalue) : _fixed_point_number(static_cast<int>(std::roundf(fvalue)) * (1 << _fractional_bits))//Float Constructor
{
}

Fixed	&Fixed::operator=(const Fixed &rhs) //Copy assignment Constructor
{
	if (this == &rhs)
		return (*this);
	int	fixed_num = rhs.getRawBits();
	this->_fixed_point_number = fixed_num;
	return (*this);
}

 Fixed::~Fixed()
{
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
	return ((static_cast<float>(_fixed_point_number) / static_cast<float>(1 << _fractional_bits)));
}

int 	Fixed::toInt( void ) const
{
	return (std::roundf(toFloat()));
}

std::ostream & operator<<(std::ostream & o, Fixed const &fixed)
{
	return (o << fixed.toFloat());
}

// ========================Comparison Operators==========================

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

// ========================Arithmetic Operators==========================
Fixed	Fixed::operator+(const Fixed &rhs) 
{
	int		number;
	Fixed	temp;

	number = this->getRawBits() + rhs.getRawBits();
	temp.setRawBits(number);
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	int		number;
	Fixed	temp;

	number = this->getRawBits() - rhs.getRawBits();
	temp.setRawBits(number);
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	temp;

	temp.setRawBits(this->getRawBits() * rhs.getRawBits() / (1 << _fractional_bits));
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	temp;
	
	temp.setRawBits(this->getRawBits() / rhs.getRawBits() * (1 << _fractional_bits));
	return (temp);
}

// ========================Increment/Decrement==========================

Fixed	&Fixed::operator++(void) //pre inc
{
	++_fixed_point_number;
	return (*this);
}

Fixed	&Fixed::operator--(void) //pre dec
{
	--_fixed_point_number;
	return (*this);
}

Fixed	Fixed::operator++(int) //post inc
{
	Fixed	temp = *this;
	++_fixed_point_number;
	return (temp);
}

Fixed	Fixed::operator--(int) //post inc
{
	Fixed	temp = *this;
	--_fixed_point_number;
	return (temp);

}

// ========================static member min/max functions==========================

static Fixed	&min(Fixed	&a, Fixed &b);
static Fixed	&min(const Fixed &a, const Fixed &b);
static Fixed	&max(Fixed	&a, Fixed &b);
static Fixed	&max(const Fixed &a, const Fixed &b);