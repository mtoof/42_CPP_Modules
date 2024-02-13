/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:40:45 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/13 17:57:56 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base	*Base::generate(void)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distributor(1, 3);
	Base *ptr = nullptr;
	switch (distributor(generator))
	{
		case 1:
			ptr = new A();
			break;
		case 2:
			ptr = new B();
			break;
		case 3:
			ptr = new C();
			break;
	}
	return (ptr);
}

void	Base::identify(Base* p)
{
	if (p)
	{
		if (dynamic_cast<A*>(p))
			std::cout << "A" <<std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "B" <<std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "C" <<std::endl;
	}
}

void	Base::identify(Base& p)
{
	try{(void)dynamic_cast<A&>(p);std::cout << "A" << std::endl;}catch(std::exception &e){};
	try{(void)dynamic_cast<B&>(p);std::cout << "B" << std::endl;}catch(std::exception &e){};
	try{(void)dynamic_cast<C&>(p);std::cout << "C" << std::endl;}catch(std::exception &e){};
}