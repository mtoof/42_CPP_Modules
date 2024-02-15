/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:23:02 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/15 17:42:39 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base ptr;
	A a;
	B b;
	C c;
	Base *ptr1 = ptr.generate();
	std::cout << "a = ";
	ptr.identify(&a);
	std::cout << "b = ";
	ptr.identify(&b);
	std::cout << "c = ";
	ptr.identify(&c);
	std::cout << "\n"
			  << std::endl;
	ptr1->identify(ptr1);

	delete ptr1;
}