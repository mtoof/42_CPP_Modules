/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:24:03 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/03 16:57:42 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Point.hpp"

Point::Point(): _x(0), _y(0) // Default constructor
{
}

Point::Point(const float x_value, const float y_value): _x(x_value), _y(y_value) // Constructor overload
{
}

Point::Point(const Point &point_class) // copy constructor
{
	*this = point_class;
}

Point &Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed&>(this->_x) = rhs.get_x();
		const_cast<Fixed&>(this->_y) = rhs.get_y();
	}
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::get_x(void) const
{
	return (this->_x);
}

Fixed	Point::get_y(void) const
{
	return (this->_y);
}

void	Point::set_x(Fixed &fixed_x)
{
	const_cast<Fixed&>(this->_x) = fixed_x;
}

void	Point::set_y(Fixed &fixed_y)
{
	const_cast<Fixed&>(this->_x) = fixed_y;
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
	out << "x = " << point.get_x() << " and y = " << point.get_y() << std::endl;
	return (out);
}