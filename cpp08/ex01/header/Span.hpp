/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:12:49 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/16 13:42:36 by mtoof            ###   ########.fr       */
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
	int shortestSpan();
	int longestSpan();

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