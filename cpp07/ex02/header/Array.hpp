/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:22 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/07 16:21:52 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &rhs);
	Array &operator=(Array const &rhs);
	T &operator[](int index);
	const T &operator[](int index) const;
	~Array();
	unsigned int size() const;
};

#include "Array.tpp"

#endif
