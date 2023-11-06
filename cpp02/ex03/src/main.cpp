/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:50:40 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/06 15:59:30 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// 	Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
// Output: Inside
// Explanation:
//               B(10,30)
//                 / \
//                /   \
//               /     \
//              /   P   \      P'
//             /         \
//      A(0,0) ----------- C(20,0) 
// Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
// Output: Outside
// Explanation:
//               B(10,30)
//                 / \
//                /   \
//               /     \
//              /       \      P
//             /         \
//      A(0,0) ----------- C(20,0) 

int main( void )
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point p1(10, 15);
	Point p2(30, 15);
	if (bsp(a, b, c, p1))
		std::cout << "Inside the area" << std::endl;
	else
		std::cout << "Outside the area" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "Inside the area" << std::endl;
	else
		std::cout << "outside the area" << std::endl;
	return 0;
}
