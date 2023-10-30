/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:41:21 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/30 17:51:56 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class  Fixed
{
private:
	int					_fixed_point_number;
	static const int	_fractional_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed_class);
	Fixed	&operator=(const Fixed &rhs);
	~Fixed();
	int	 getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif