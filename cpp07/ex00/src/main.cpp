/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:56:19 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/07 14:24:16 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"

int main(void)
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	float num = 1.2f;
	float num2 = 2.3f;
	::swap(num, num2);
	std::cout << "num = " << num << ", num2 = " << num2 << std::endl;
	std::cout << "min( num, num2 ) = " << ::min(num, num2) << std::endl;
	std::cout << "max( num, num2 ) = " << ::max(num, num2) << std::endl;
	char charVar = 'A';
	char charVar2 = 'C';
	::swap(charVar, charVar2);
	std::cout << "charVar = " << charVar << ", charVar2 = " << charVar2 << std::endl;
	std::cout << "min( charVar, charVar2 ) = " << ::min(charVar, charVar2) << std::endl;
	std::cout << "max( charVar, charVar2 ) = " << ::max(charVar, charVar2) << std::endl;
	return 0;
}