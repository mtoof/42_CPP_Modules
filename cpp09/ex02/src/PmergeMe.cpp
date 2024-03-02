/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:18 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/02 00:30:19 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_odd_elements = false;
}

PmergeMe::PmergeMe(const PmergeMe &rhs) : _vec(rhs._vec), _deq(rhs._deq)
{
	_odd_elements = rhs._odd_elements;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vec.clear();
		_deq.clear();
		_vec = rhs._vec;
		_deq = rhs._deq;
		_odd_elements = rhs._odd_elements;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::print(std::string flag) const
{
	if (flag == "before")
	{
		std::vector<int>::const_iterator it;
		std::cout << "Before:   ";
		for (it = _vec.begin(); it != _vec.end(); it++)
		{
			// if (std::distance(it, _vec.end()) > 1)
			std::cout << *it << " ";
		}
		if (_odd_elements)
			std::cout << _last_element << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		std::vector<int>::const_iterator it;
		std::cout << "After:   ";
		for (it = _vec.begin(); it != _vec.end(); it++)
		{
			// if (std::distance(it, _vec.end()) > 1)
			std::cout << *it << " ";
		}
		if (_odd_elements)
			std::cout << _last_element << std::endl;
		else
			std::cout << std::endl;
	}
}

void PmergeMe::parseNumbers(int ac, char **av)
{
	if (ac % 2 == 0)
		_odd_elements = true;
	for (int it = 1; av[it]; it++)
	{
		int number;
		try
		{
			if (_odd_elements && it == ac - 1)
			{
				_last_element = std::stoi(av[it]);
				break;
			}
			number = std::stoi(av[it]);
		}
		catch (const std::exception &e)
		{
			throw InvalidNumberException();
		}
		_vec.push_back(number);
	}
	start_time = std::chrono::high_resolution_clock::now();
	print("before");
	fordJohnson();
	print("after");
	end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double>  diff = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	std::cout << std::fixed << std::setprecision(8) <<"Time to process a range of " << ac - 1 << " elements with vectore : "  << diff.count() << " microseconds" << std::endl;
		
}

void PmergeMe::fordJohnson()
{
	pairAndSort();
	
	size_t container_size = _vec.size();
	sortByGreater(container_size);
	separateGreaterFromSmaller();
	insertionSort();
	return;
}

void PmergeMe::pairAndSort()
{
	std::vector<int>::iterator it;
	if (_vec.front() > _vec.back())
		std::swap(_vec.front(), _vec.back());
	for (it = _vec.begin(); it != _vec.end(); it += 2)
	{
		if (it + 1 != _vec.end() && *it > *(it + 1))
			std::swap(*it, *(it + 1));
	}
}

void PmergeMe::sortByGreater(size_t container_size)
{
	if (container_size > 4)
		sortByGreater(container_size / 2);
	size_t it = 1;
	size_t second_it = 0;
	for (it = 1; it < container_size; it += 2)
	{
		if (it + 2 < container_size)
			second_it = it + 2;
		else
			break;
		if (_vec.at(it) > _vec.at(second_it))
		{
			std::swap(_vec.at(it - 1), _vec.at(second_it - 1));
			std::swap(_vec.at(it), _vec.at(second_it));
			it = -1; // We need to reset iterator after every swap
		}
	}
}

void PmergeMe::separateGreaterFromSmaller()
{
	std::vector<int>::iterator item = _vec.end() - 1;
	for (size_t it = 0; it < (_vec.size() / 2); it++)
	{
		int element = *item;
		_vec.erase(item);
		_vec.insert(_vec.begin(), element);
		item--;
	}
}

void PmergeMe::insertionSort()
{
	int startOfSmallNumbersArray = _vec.back();
	std::vector<int>::iterator max_number  = std::max_element(_vec.begin(), _vec.end() - 1);
	std::vector<int>::iterator position;
	while (!std::is_sorted(_vec.begin(), _vec.end()))
	{
		position = std::lower_bound(_vec.begin(), max_number, startOfSmallNumbersArray);
		_vec.insert(position, startOfSmallNumbersArray);
		_vec.pop_back();
		max_number  = std::max_element(_vec.begin(), _vec.end());
		startOfSmallNumbersArray = _vec.back();
	}
	if(_odd_elements)
	{
		position = std::lower_bound(_vec.begin(), _vec.end(), _last_element);
		_vec.insert(position, _last_element);
	}
}

const char *PmergeMe::InvalidNumberException::what() const noexcept
{
	return ("Invalid number");
}

// https://www.phind.com/search?cache=lhynuq1hwo9mq2insmrmo57e
