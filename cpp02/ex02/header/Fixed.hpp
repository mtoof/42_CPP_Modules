/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:41:21 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/01 15:05:13 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class  Fixed
{
private:
	int					_fixed_point_number;
	static const int	_fractional_bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const int ivalue);
	Fixed(const float fvalue);
	Fixed(const Fixed &fixed_class);
	
	Fixed	&operator=(const Fixed &rhs);
	// Comparison operators
	bool	operator>(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	// arithmetic operators
	Fixed	operator+(const Fixed &rhs);
	Fixed	operator-(const Fixed &rhs);
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;
	// Increment/Decrement
	Fixed	&operator++(void);//pre inc
	Fixed	&operator--(void);//pre dec
	Fixed	operator++(int);//post inc
	Fixed	operator--(int);//post dec
	
	static Fixed&	min(Fixed	&a, Fixed &b);
	static const Fixed&	min(const Fixed &a, const Fixed &b);
	static Fixed&	max(Fixed	&a, Fixed &b);
	static const Fixed&	max(const Fixed &a, const Fixed &b);
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
	int	 getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & o, Fixed const &input);
#endif