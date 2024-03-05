/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:18 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/06 00:14:34 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_oddElements = false;
}

PmergeMe::PmergeMe(const PmergeMe &rhs) : _vec(rhs._vec), _deq(rhs._deq)
{
	_oddElements = rhs._oddElements;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vec.clear();
		_deq.clear();
		_vec = rhs._vec;
		_deq = rhs._deq;
		_oddElements = rhs._oddElements;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::print(std::string flag) const
{
	std::vector<std::pair<int, int>>::const_iterator it;
	if (flag == "before")
	{
		std::cout << "Before:   ";
		for (it = _vec.begin(); it != _vec.end(); it++)
			std::cout << it->first << " " << it->second << " ";
		if (_oddElements)
			std::cout << _lastElement << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		std::cout << "After:   ";
		for (it = _vec.begin(); it != _vec.end(); it++)
			std::cout << it->first << " " << it->second << " ";
		std::cout << std::endl;
	}
}

void PmergeMe::parseNumbers(int ac, char **av)
{
	if (ac % 2 == 0)
		_oddElements = true;
	for (int it = 1; av[it]; it += 2)
	{
		int number;
		int secondNumber;
		try
		{
			if (_oddElements && it == ac - 1)
			{
				_lastElement = std::stoi(av[it]);
				break;
			}
			number = std::stoi(av[it]);
			secondNumber = std::stoi(av[it + 1]);
		}
		catch (const std::exception &e)
		{
			throw InvalidNumberException();
		}
		_vec.push_back({number, secondNumber});
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
	print("before");
	sortByGreater(_vec);
	separateGreaterFromSmaller();
	// insertionSort();
	// std::cout << "pend = ";
	// for (size_t i = 0; i < _pend.size(); i++)
	// 	std::cout << _pend.at(i) << " ";
	// std::cout << std::endl;
	// std::cout << "_mainChain = "; 
	// for (size_t i = 0; i < _mainChain.size(); i++)
	// 	std::cout << _mainChain.at(i) << " "; 
	// std::cout << std::endl;


	return;
}

void PmergeMe::pairAndSort()
{
	std::vector<std::pair<int, int>>::iterator it;
	// if (_vec.front() > _vec.back())
	// 	std::swap(_vec.front(), _vec.back());
	for (it = _vec.begin(); it != _vec.end(); it += 2)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::sortByGreater(std::vector<std::pair<int,int>> vec) 
{
        // if (left < right) {
        //     size_t mid = left + (right - left) / 2;
        //     sortByGreater(left, mid); // Sort the left half
        //     sortByGreater(mid + 1, right); // Sort the right half
        //     merge(left, mid, right); // Merge the sorted halves
        // }
	size_t length = vec.size();
	if (length <= 1) return;

	size_t middle = length / 2;
	std::vector<std::pair<int, int>> leftVec, rightVec;
	for (size_t iter = 0; iter < length; iter++)
	{
		if (iter < middle)
			leftVec.push_back(_vec.at(iter));
		else
		{
			rightVec.push_back(_vec.at(iter));
		}
	}
	sortByGreater(leftVec);
	sortByGreater(rightVec);
	merge(leftVec, rightVec);
}

void PmergeMe::merge(std::vector<std::pair<int, int>> leftVec, std::vector<std::pair<int, int>> rightVec) 
{
	// std::cout << "leftVec = ";
	// for (size_t iter = 0; iter < leftVec.size(); iter++)
	// 	std::cout << leftVec.at(iter) << " ";
	// std::cout << std::endl;
	// std::cout << "rightVec = ";
	// for (size_t iter = 0; iter < rightVec.size(); iter++)
	// 	std::cout << rightVec.at(iter) << " ";
	// std::cout << std::endl;
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
	if (_oddElements)
		_pend.push_back(_lastElement);
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
