/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:43:47 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/06 15:43:48 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

double	ft_abs(double value)
{
	if (value < 0)
		value = -value;
	return (value);
}

double	triangle_area(Point const a, Point const b, Point const c)
{
	Fixed	p1 = a.get_x() * (b.get_y() - c.get_y());
	Fixed	p2 = b.get_x() * (c.get_y() - a.get_y());
	Fixed	p3 = c.get_x() * (a.get_y() - b.get_y());
	double area = ft_abs(p1.toFloat() + p2.toFloat() + p3.toFloat()) / 2;
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	double	total_area = triangle_area(a, b, c);
	double	alpha = triangle_area(point, a, b);
	double	beta = triangle_area(point, b, c);
	double	gamma = triangle_area(point, a, c);

	double epsilon = 1e-6;

	if (fabs(total_area - (alpha + beta + gamma)) < epsilon)
        return true;
    return false;
}
	// Triangle Area = 0.5 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|

	//α = ((y2 - y3)(x - x3) + (x3 - x2)(y - y3)) / ((y2 - y3)(x1 - x3) + (x3 - x2)(y1 - y3))
	//β = ((y3 - y1)(x - x3) + (x1 - x3)(y - y3)) / ((y2 - y3)(x1 - x3) + (x3 - x2)(y1 - y3))
	//γ = 1 - α - β

	//Area of Triangle ABC == Area of Triangle PAB + Area of Triangle PBC + Area of Triangle PAC

	// 	Check if the barycentric coordinates (u, v, w) of point P satisfy the following conditions:

	// 0 <= u <= 1
	// 0 <= v <= 1
	// 0 <= w <= 1
	// u + v + w = 1