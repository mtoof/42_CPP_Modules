/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:19:11 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/19 18:39:24 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "First test\n" << std::endl;
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(25);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "======================================" << std::endl;
	std::cout << "Second test\n" << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=======================================" << std::endl;
	std::cout << "Third test\n" << std::endl;
	Span sp1 = Span(1);
	try
	{
		sp1.addNumber(11);
		sp1.addNumber(25);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	sp1.print();

	std::cout << "=======================================" << std::endl;
	std::cout << "Forth test\n" << std::endl;
	Span sp2(4);
	sp2.addNumber(12);
	sp2.addNumber(13);

	Span sp3(3);
	sp3.addNumber(14);
	sp3.addNumber(15);
	// sp3.addNumber(16);
	try
	{
		sp2.addNumber(sp2.getPos(2), sp3.getBegin(), sp3.getEnd());
		// sp2.addNumber(sp2.getPos(1), sp3.getBegin(), sp3.getEnd() - 1);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	sp2.print();
		
	return 0;
}