/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:41:21 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/30 17:49:14 by mtoof            ###   ########.fr       */
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
	Fixed(const int ivalue);
	Fixed(const float fvalue);
	Fixed(const Fixed &rhs);
	Fixed	&operator=(const Fixed &rhs);
	~Fixed();
	float 	toFloat( void ) const;
	int 	toInt( void ) const;
	int	 getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & o, Fixed const &input);
#endif