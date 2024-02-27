/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:18 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/27 16:15:24 by mtoof            ###   ########.fr       */
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
		std::cout << "Before: ";
		std::vector<std::pair<int, int>>::const_iterator it;
		for (it = _vec.begin(); it != _vec.end(); it++)
		{
			// if (std::distance(it, _vec.end()) > 1)
			std::cout << it->first << " " << it->second << " ";
		}
		if (_odd_elements)
			std::cout << _last_element << std::endl;
		else
			std::cout << std::endl;
	}
	// auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
	// std::cout << "time = " << elapsed.count() << std::endl;
}

void PmergeMe::parseNumbers(int ac, char **av)
{
	start_time = time(0);
	now = ctime(&start_time);
	start = std::chrono::steady_clock::now();
	if (ac % 2 == 0)
		_odd_elements = true;
	for (int it = 1; av[it]; it += 2)
	{
		int first = 0, second = 0;
		try
		{
			if (_odd_elements && it == ac - 1)
			{
				_last_element = std::stoi(av[it]);
				break;
			}
			first = std::stoi(av[it]);
			second = std::stoi(av[it + 1]);
		}
		catch (const std::exception &e)
		{
			throw InvalidNumberException();
		}
		_vec.push_back(std::make_pair(first, second));
	}
	print("before");
	FordJohson();
}

void PmergeMe::FordJohson()
{
	std::vector<std::pair<int, int>>::const_iterator it;
	for (it = _vec.begin(); it!= _vec.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	return;
}

const char *PmergeMe::InvalidNumberException::what() const noexcept
{
	return ("Invalid number");
}

// https://www.phind.com/search?cache=lhynuq1hwo9mq2insmrmo57e
