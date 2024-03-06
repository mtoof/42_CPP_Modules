/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:18 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/06 17:05:18 by mtoof            ###   ########.fr       */
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
			std::cout << it->first << " " << RED << it->second << RESET << " ";
		if (_oddElements)
			std::cout << _lastElement << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		std::cout << "After:   ";
		for (it = _vec.begin(); it != _vec.end(); it++)
			std::cout << it->first << " " << RED << it->second << RESET << " ";
		std::cout << std::endl;
	}
}

void PmergeMe::parseNumbers(int ac, char **av)
{
	int elements = ac - 1;
	if (elements % 2 == 0)
		_oddElements = true;
	for (int it = 1; av[it]; it += 2)
	{
		int number;
		int secondNumber;
		try
		{
			if (_oddElements && it == elements)
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
	sortByGreater(_vec, _vec.size(), 0);
	separateGreaterFromSmaller();
	insertionSort();
	return;
}

void PmergeMe::pairAndSort()
{
	std::vector<std::pair<int, int>>::iterator it;
	for (it = _vec.begin(); it != _vec.end(); it ++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::sortByGreater(std::vector<std::pair<int,int>> &vec, size_t vecSize, size_t start)
{
	if (vecSize <= 1) return;

	size_t middle = vecSize / 2;
	sortByGreater(vec, middle, start);
	sortByGreater(vec, vecSize - middle, start + middle);
	std::vector<std::pair<int, int>> tmp;
	size_t left = start, right = start + middle, end = start + vecSize;

	while (left < start + middle && right < end)
	{
		if (vec[left].second <= vec[right].second)
		{
			tmp.push_back(vec[left]);
			left++;
		}
		else
		{
			tmp.push_back(vec[right]);
			right++;
		}
	}

	while (left < start + middle)
	{
		tmp.push_back(vec[left]);
		left++;
	}

	while (right < end)
	{
		tmp.push_back(vec[right]);
		right++;
	}

	for (size_t i = 0; i < tmp.size(); ++i)
		vec[start + i] = tmp[i];	
}

void PmergeMe::separateGreaterFromSmaller()
{
	for (size_t iter = 0; iter < _vec.size(); iter++)
	{
		_mainChain.push_back(_vec[iter].second);
		_pend.push_back(_vec[iter].first);
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
	_mainChain.insert(_mainChain.begin(), _pend.at(0));
	std::vector<int> jArray = {0, 1};
	std::vector<int>::iterator pos;
	while (_mainChain.size() / 2 < (_vec.size()))
	{
		jArray.push_back(jacob(jArray, jArray.size()));
		int prev = *(jArray.end() - 2);
		if (jArray.back() == 1)
		{
			pos = std::lower_bound(_mainChain.begin(), _mainChain.begin() + 2, _pend.at(1));
			_mainChain.insert(pos, _pend.at(1));
		}
		else
		{
			for (int it = jArray.back(); it > prev; it--)
			{
				if (it <= int(_pend.size() - 1))
				{				
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
	if (!std::is_sorted(_mainChain.begin(), _mainChain.end()))
	{
		std::cerr << "Error" << std::endl;
	}
}

const char *PmergeMe::InvalidNumberException::what() const noexcept
{
	return ("Invalid number");
}