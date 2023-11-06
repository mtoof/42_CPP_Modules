/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:24:41 by mtoof             #+#    #+#             */
/*   Updated: 2023/11/06 15:45:58 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const	Fixed _x;
	const	Fixed _y;
public:
	Point();
	Point(const float x_value, const float y_value);
	Point(const Point &point_class);
	Point &operator=(const Point &rhs);
	~Point();

	Fixed	get_x(void) const;
	Fixed	get_y(void) const;
	void	set_x(Fixed &fixed_x);
	void	set_y(Fixed &fixed_y);
};

std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif