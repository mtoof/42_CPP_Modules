/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:12:49 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/19 17:41:54 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span
{
private:
	std::vector<int> _vec;
	unsigned int _size;

public:
	Span();
	Span(unsigned int N);
	Span(Span const &rhs);
	~Span();
	Span &operator=(Span const &rhs);
	int &operator[](unsigned int index);
	void addNumber(int number);
	void addNumber(std::vector<int>::const_iterator position, std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
	int shortestSpan();
	int longestSpan();
	unsigned int getSize() const;
	void print() const;
	std::vector<int>::const_iterator getBegin() const;
	std::vector<int>::const_iterator getEnd() const;
	std::vector<int>::const_iterator getPos(unsigned int position) const;

	class SizeExpection: public std::exception
	{
		public:
			virtual const char* what() const noexcept;
	};
	
	class InvalidIndexException : public std::exception
	{
		public:
			virtual const char *what() const noexcept;
	};
	
	class NotEnoughItemException : public std::exception
	{
		public:
			virtual const char *what() const noexcept;
	};
	
	class InvalidInputException: public std::exception
	{
		public:
			virtual const char *what() const noexcept;
	};
};

#endif