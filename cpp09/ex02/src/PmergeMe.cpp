/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:18 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/04 20:21:03 by mtoof            ###   ########.fr       */
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
			std::cout << *it << " ";
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
			std::cout << *it << " ";
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
	// insertionSort();
	std::cout << "pend = ";
	for (size_t i = 0; i < _pend.size(); i++)
		std::cout << _pend.at(i) << " ";
	std::cout << std::endl;
	std::cout << "_mainChain = "; 
	for (size_t i = 0; i < _mainChain.size(); i++)
		std::cout << _mainChain.at(i) << " "; 
	std::cout << std::endl;


	return;
}

void PmergeMe::pairAndSort()
{
	std::vector<int>::iterator it;
	// if (_vec.front() > _vec.back())
	// 	std::swap(_vec.front(), _vec.back());
	for (it = _vec.begin(); it != _vec.end(); it += 2)
	{
		if (it + 1 != _vec.end() && *it > *(it + 1))
			std::swap(*it, *(it + 1));
	}
}

void PmergeMe::sortByGreater(size_t container_size)
{
	if (container_size > 2)
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
	for (size_t iter = 0; iter < _vec.size(); iter++)
	{
		if (iter % 2)
			_mainChain.push_back(_vec.at(iter));
		else if (iter % 2 == 0)
			_pend.push_back(_vec.at(iter));
	}
	// if (_odd_elements)
	// 	_pend.push_back(_last_element);
}

int jacob(std::vector<int> jArray, int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (jArray[n - 1] + (2 * jArray[n - 2]));
}

void PmergeMe::insertionSort()
{
	// size_t n = 0;
	_mainChain.insert(_mainChain.begin(), _pend.at(0));
	std::vector<int> jArray = {0, 1};
	std::cout << "pend = ";
	for (size_t i = 0; i < _pend.size(); i++)
		std::cout << _pend.at(i) << " ";
	std::cout << std::endl;
	std::cout << "_mainChain = "; 
	for (size_t i = 0; i < _mainChain.size(); i++)
		std::cout << _mainChain.at(i) << " "; 
	std::cout << std::endl;

	std::vector<int>::iterator pos;
	while (_mainChain.size() < _vec.size())
	{
		jArray.push_back(jacob(jArray, jArray.size()));
		// std::cout << "jArray back = " << jArray.back() << std::endl;
		int prev = *(jArray.end() - 2);
		// std::cout << "prev = " << prev << std::endl;
		if (jArray.back() == 1)
		{
			// std::cout << "_pend.at(1) = " << _pend.at(1) << std::endl;
			pos = std::lower_bound(_mainChain.begin(), _mainChain.begin() + 2, _pend.at(1));
			_mainChain.insert(pos, _pend.at(1));
			// std::cout << "_mainChain = "; 
			// for (size_t i = 0; i < _mainChain.size(); i++)
			// 	std::cout << _mainChain.at(i) << " "; 
			// std::cout << std::endl;
		}
		else
		{
			for (int it = jArray.back(); it > prev; it--)
			{
				if (it <= int(_pend.size() - 1))
				{
				
					// std::cout << "_mainChain = "; 
					// for (size_t i = 0; i < _mainChain.size(); i++)
					// 	std::cout << _mainChain.at(i) << " "; 
					// std::cout << std::endl;
					// std::cout << "it = " << it << std::endl;
					// std::cout << "_pend.at(it) = " << _pend.at(it) << std::endl;
					// std::cout << "_mainChain.begin() + (_mainChain.size() - _pend.size()) = " << *(_mainChain.begin() + (_mainChain.size() - _pend.size()) + it) << std::endl;
					pos = std::lower_bound(_mainChain.begin(), _mainChain.begin() + (_mainChain.size() - _pend.size()) + it, _pend.at(it));
					_mainChain.insert(pos, _pend.at(it));
				}
			}
		}
	}
	// std::cout << "_mainChain = "; 
	// for (size_t i = 0; i < _mainChain.size(); i++)
	// 	std::cout << _mainChain.at(i) << " "; 
	// std::cout << std::endl;
	if (_odd_elements)
	{
		pos = std::lower_bound(_mainChain.begin(), _mainChain.end(), _last_element);
		_mainChain.insert(pos, _last_element);
	}
		
	if (std::is_sorted(_mainChain.begin(), _mainChain.end()))
		_vec = _mainChain;
	else
		std::cerr << "Error" << std::endl;
}

const char *PmergeMe::InvalidNumberException::what() const noexcept
{
	return ("Invalid number");
}

// https://www.phind.com/search?cache=lhynuq1hwo9mq2insmrmo57e
