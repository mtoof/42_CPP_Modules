/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:07:19 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/07 15:05:08 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

struct myTest
{
	int number = 2;
	std::string str = "This is myTest struct";
};

std::ostream& operator<<(std::ostream &o, const myTest &rhs)
{
	o << "number = " << rhs.number << std::endl;
	o << "str = " << rhs.str << std::endl;
	return o;
}

int main()
{
	
	std::string array[3] = {"hello", "world", "this is a test"};

	::iter<std::string>(array, 3, ::print_array<std::string>);

	int int_array[3] = {1, 2, 3};

	::iter<int>(int_array, 3, ::increment_array<int>);
	::iter<int>(int_array, 3, ::print_array<int>);

	char char_array[3] = {'a', 'A', 'b'};

	::iter<char>(char_array, 3, ::increment_array<char>);
	::iter<char>(char_array, 3, ::print_array<char>);

	std::cout << "\nTest struct type\n" << std::endl;

	myTest myArray[3];
	iter<myTest>(myArray, 3, print_array<myTest>);
	return 0;
}