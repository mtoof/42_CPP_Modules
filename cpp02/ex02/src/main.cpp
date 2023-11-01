/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:50:40 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/01 09:56:51 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Fixed.hpp"

int main( void )
{
	Fixed a(11);
	Fixed b(11);
	std::cout << "// Comparison Operations" << std::endl;
	std::cout << std::boolalpha << "Less than = " << (b < a) << std::endl;
	std::cout << std::boolalpha << "Less than equal = " << (b <= a) << std::endl;
	std::cout << std::boolalpha << "Greater than = " << (b > a) << std::endl;
	std::cout << std::boolalpha << "Greater than equal = " << (b >= a) << std::endl;
	std::cout << std::boolalpha << "Not equal = " << (b != a) << std::endl;
	std::cout << std::boolalpha << "Comparison equal = " << (b == a) << std::endl;
	
	std::cout  << "a = " << a << std::endl;
	std::cout  << "b = " << b << std::endl;
	
	std::cout << "// Arithmetic Operations" << std::endl;
	std::cout  << "b + a = " << (b + a) << std::endl;
	std::cout  << "b - a = " << (b - a) << std::endl;
	std::cout  << "b * a = " << (b * a) << std::endl;
	std::cout  << "b / a = " << (b / a) << std::endl;
	
	std::cout << "// Increment/Decrement Operations" << std::endl;
	Fixed c(12);
	std::cout  << "c = " << c << std::endl;
	std::cout  << "c++ = " << c++ << std::endl;
	std::cout  << "c = " << c << std::endl;
	std::cout  << "++c = " << ++c << std::endl;
	std::cout  << "c = " << c << std::endl;
	std::cout  << "c-- = " << c-- << std::endl;
	std::cout  << "c = " << c << std::endl;
	std::cout  << "--c = " << --c << std::endl;
	std::cout  << "c = " << c << std::endl;
	
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
