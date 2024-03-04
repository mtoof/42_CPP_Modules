/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:29:13 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/04 20:18:26 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array()
	: _array(nullptr), _size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Argument constructor called" << std::endl;
	this->_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &rhs)
	: _array(nullptr), _size(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "Destructor called" << std::endl;
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
