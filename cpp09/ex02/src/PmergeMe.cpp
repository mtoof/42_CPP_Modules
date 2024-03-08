/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:18 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/08 15:53:28 by mtoof            ###   ########.fr       */
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
	std::vector<int>::const_iterator it;
	if (flag == "before")
	{
		std::cout << "Before:   ";
		for (it = _vec.begin(); it != _vec.end(); it++)
			// std::cout << it->first << " " << RED << it->second << RESET << " ";
			std::cout << *it << " ";
		if (_oddElements)
			std::cout << _lastElement << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		std::cout << "After:   ";
		for (it = _vec.begin(); it != _vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

void PmergeMe::parseNumbers(int ac, char **av)
{
	if (ac % 2 == 0)
		_oddElements = true;
	for (int it = 1; av[it]; it++)
	{
		int number;
		// int secondNumber;
		try
		{
			if (_oddElements && it == ac - 1)
			{
				_lastElement = std::stoi(av[it]);
				break;
			}
			number = std::stoi(av[it]);
			// secondNumber = std::stoi(av[it + 1]);
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
	std::chrono::duration<double> diff = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	std::cout << std::fixed << std::setprecision(8) << "Time to process a range of " << ac - 1 << " elements with vectore : " << diff.count() << " microseconds" << std::endl;
}

void PmergeMe::fordJohnson()
{
	pairAndSort();
	sortByGreater(_tmp, _tmp.size(), 0);
	separateGreaterFromSmaller();
	insertionSort();
	return;
}

void PmergeMe::pairAndSort()
{
	for (size_t iter = 0; iter < _vec.size(); iter+=2)
	{
		_tmp.push_back(std::pair{_vec[iter], _vec[iter + 1]});
	}
	std::vector<std::pair<int, int>>::iterator it;
	for (it = _tmp.begin(); it != _tmp.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	std::cout << std::endl;
}

void PmergeMe::sortByGreater(std::vector<std::pair<int, int>> &vec, size_t vecSize, size_t start)
{
	if (vecSize <= 1)
		return;

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
	for (size_t iter = 0; iter < _tmp.size(); iter++)
	{
		_mainChain.push_back(_tmp[iter].second);
		_pend.push_back(_tmp[iter].first);
	}
	if (_oddElements)
		_pend.push_back(_lastElement);
	std::cout << std::endl;
}

void SequenceGenerator(std::vector<int> &vec, int n)
{
	while (std::accumulate(vec.begin(), vec.end(), 0) <= n)
	{
		int num = std::pow(2, vec.size() + 1) - vec.back();
		vec.push_back(num);
	}
}

void PmergeMe::insertionSort()
{
	_mainChain.insert(_mainChain.begin(), _pend.at(0));
	std::vector<int>::iterator pos;
	std::vector<int> sequencesOfNumbers = {2};
	_pend.erase(_pend.begin());
	SequenceGenerator(sequencesOfNumbers, _pend.size());
	while (_mainChain.size() / 2 < (_tmp.size()))
	{
		int iter = *(sequencesOfNumbers.begin());
		while (iter-- > 0)
		{
			if (iter <= int(_pend.size() - 1))
			{
				pos = std::lower_bound(_mainChain.begin(), _mainChain.begin() + (_mainChain.size() - _pend.size()) + iter, _pend.at(iter));
				_mainChain.insert(pos, _pend.at(iter));
				_pend.erase(_pend.begin() + iter);
			}
		}
		sequencesOfNumbers.erase(sequencesOfNumbers.begin());
	}
	if (!std::is_sorted(_mainChain.begin(), _mainChain.end()))
	{
		std::cerr << "Error" << std::endl;
		throw std::runtime_error("Couldn't sort the vector");
	}
	else
	{
		_vec = _mainChain;
	}
}

const char *PmergeMe::InvalidNumberException::what() const noexcept
{
	return ("Invalid number");
}