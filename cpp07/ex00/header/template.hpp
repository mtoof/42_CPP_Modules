/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:54:58 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/14 15:55:05 by mtoof            ###   ########.fr       */
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
const T &min(const T &a, const T &b)
{
	return a < b ? a: b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
	return a > b ? a: b;
}

#endif