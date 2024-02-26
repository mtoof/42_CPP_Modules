/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:18 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/26 18:56:58 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs): _vec(rhs._vec), _deq(rhs._deq)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vec.clear();
		_deq.clear();
		_vec = rhs._vec;
		_deq = rhs._deq;
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
		if (_vec.size() > 1)
		{
			std::cout << "Before: ";
			for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
			{
				if (std::distance(it, _vec.end()) > 1)
					std::cout << *it << " ";
				else
					std::cout << *it << std::endl;
			}
		}
	}
	for (int i = 0; i < 100000000; i++)
	{}
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - start );
	std::cout << "time = " << elapsed.count() << std::endl;
}

void PmergeMe::parseNumbers(char **av)
{
	start_time = time(0);
	now  = ctime(&start_time);
	start = std::chrono::steady_clock::now();
	for (int it = 1; av[it]; it++)
	{
		int number = 0;
		try
		{
			number = std::stoi(av[it]);
		}
		catch(const std::exception &e)
		{
			throw InvalidNumberException();
		}
		_vec.push_back(number);
	}
	print("before");
}

const char* PmergeMe::InvalidNumberException::what() const noexcept
{
	return ("Invalid number");
}