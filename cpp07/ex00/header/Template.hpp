/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:54:58 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/14 14:32:09 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>



template <typename T> 
void swap(T &a, T &b)
{
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp;
} 


template <typename T>
T min(T a, T b)
{
	return a < b ? a: b;
}

template <typename T>
T max(T a, T b)
{
	return a > b ? a: b;
}

#endif