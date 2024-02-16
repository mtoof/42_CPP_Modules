/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:12:26 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/16 17:02:06 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"

Span::Span()
{
	_size = 0;
}

Span::Span(unsigned int N)
{
	_size = N;
	_vec.reserve(N);
}

Span::Span(Span const &rhs)
{
	_vec.clear();
	for (unsigned int index = 0; index < rhs._size; index++)
		_vec.push_back(rhs._vec.at(index));
	_size = rhs._size;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_vec.clear();
		for (unsigned int index = 0; index < rhs._size; index++)
			_vec.push_back(rhs._vec.at(index));
		_size = rhs._size;
	}
	return (*this);
}

Span::~Span()
{
	_vec.clear();
}

int &Span::operator[](unsigned int index)
{
	if (index < _size)
		return _vec.at(index);
	else
		throw InvalidIndexException();
}

void Span::addNumber(int number)
{
	if (this->_vec.size() < this->_size)
		_vec.push_back(number);
	else
		throw SizeExpection();
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw NotEnoughItemException();
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator item;
	int min = std::numeric_limits<int>::max();
	std::vector<int>::iterator second_item = tmp.begin() + 1;
	for (item = tmp.begin(); second_item != tmp.end(); item++)
	{
		int current_span(*second_item - *item);
		min = std::min(min, current_span);
		second_item++;
	}
	return (min);
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw NotEnoughItemException();

	std::vector<int> tmp(_vec);

	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

const char *Span::InvalidIndexException::what() const noexcept
{
	return ("Invalid index");
}

const char *Span::NotEnoughItemException::what() const noexcept
{
	return ("Not Enough item to run longest or shortest span");
}

const char *Span::SizeExpection::what() const noexcept
{
	return ("No empty space in the Container");
}

const char *Span::InvalidInputException::what() const noexcept
{
	return ("Invalid Input");
}