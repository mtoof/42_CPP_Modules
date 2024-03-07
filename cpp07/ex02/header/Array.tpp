/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:13 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/07 16:23:07 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array()
	: _array(nullptr), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &rhs)
	: _array(nullptr), _size(0)
{
	*this = rhs;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_size = rhs._size;
		_array = new T[rhs._size];
		for (unsigned int index = 0; index < _size; index++)
			_array[index] = rhs._array[index];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](int index)
{
	if (index >= 0 && index < (int)_size)
		return (this->_array[index]);
	else
		throw std::out_of_range("Index is out of range");
}

template <typename T>
const T &Array<T>::operator[](int index) const
{
	if (index >= 0 && index < (int)_size)
		return (this->_array[index]);
	else
		throw std::out_of_range("Index is out of range");
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
	{
		delete[] _array;
	}
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
