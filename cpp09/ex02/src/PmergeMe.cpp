/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:18 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/10 15:33:31 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

template <typename T, template<typename...> class Container>
PmergeMe<T, Container>::PmergeMe()
{
	_oddElements = false;
}

template <typename T, template<typename...> class Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe &rhs) : _vec(rhs._vec)
{
	_oddElements = rhs._oddElements;
}

template <typename T, template<typename...> class Container>
PmergeMe<T, Container> &PmergeMe<T, Container>::operator=(const PmergeMe<T, Container> &rhs)
{
	if (this != &rhs)
	{
		_vec.clear();
		_vec = rhs._vec;
		_oddElements = rhs._oddElements;
	}
	return (*this);
}

template <typename T, template<typename...> class Container>
PmergeMe<T, Container>::~PmergeMe()
{
}

template <typename T, template<typename...> class Container>
void PmergeMe<T, Container>::print(std::string flag) const
{
	typename Container<T>::const_iterator it;
	if (flag == "before")
	{
		std::cout << "Before:   ";
		for (it = _vec.begin(); it != _vec.end(); it++)
			std::cout << *it << " ";
		if (_oddElements)
			std::cout << _lastElement;
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

template <typename T, template<typename...> class Container>
void PmergeMe<T, Container>::parseNumbers(int ac, char **av, std::string identifier)
{
	if (ac % 2 == 0)
		_oddElements = true;
	for (int it = 1; av[it]; it++)
	{
		int number;
		try
		{
			if (_oddElements && it == ac - 1)
			{
				_lastElement = std::stoi(av[it]);
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
	std::chrono::duration<double> diff = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	std::cout << RED <<std::fixed << std::setprecision(8) << "Time to process a range of " << ac - 1 << " elements with " << identifier << " " << diff.count() << " microseconds" RESET << std::endl;
}

template <typename T, template<typename...> class Container>
void PmergeMe<T, Container>::fordJohnson()
{
	pairAndSort();
	sortByGreater(_tmp, _tmp.size(), 0);
	separateGreaterFromSmaller();
	insertionSort();
	return;
}

template <typename T, template<typename...> class Container>
void PmergeMe<T, Container>::pairAndSort()
{
	for (size_t iter = 0; iter < _vec.size(); iter+=2)
	{
		_tmp.push_back(std::pair{_vec[iter], _vec[iter + 1]});
	}
	typename Container<std::pair<T, T>>::iterator it;
	for (it = _tmp.begin(); it != _tmp.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	std::cout << std::endl;
}

template <typename T, template<typename...> class Container>
void PmergeMe<T, Container>::sortByGreater(Container<std::pair<T, T>> &vec, size_t vecSize, size_t start)
{
	if (vecSize <= 1)
		return;

	size_t middle = vecSize / 2;
	sortByGreater(vec, middle, start);
	sortByGreater(vec, vecSize - middle, start + middle);
	Container<std::pair<T, T>> tmp;
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

template <typename T, template<typename...> class Container>
void PmergeMe<T, Container>::separateGreaterFromSmaller()
{
	for (size_t iter = 0; iter < _tmp.size(); iter++)
	{
		_mainChain.push_back(_tmp[iter].second);
		_pend.push_back(_tmp[iter].first);
	}
}

template <typename T, template<typename...> class Container>
void PmergeMe<T, Container>::SequenceGenerator(Container<T> &vec, int n)
{
	while (std::accumulate(vec.begin(), vec.end(), 0) <= n)
	{
		T num = std::pow(2, vec.size() + 1) - vec.back();
		vec.push_back(num);
	}
}

template <typename T, template<typename...> class Container>
void PmergeMe<T, Container>::insertionSort()
{
	_mainChain.insert(_mainChain.begin(), _pend.at(0));
	typename Container<T>::iterator pos;
	Container<T> sequencesOfNumbers = {2};
	SequenceGenerator(sequencesOfNumbers, _pend.size());
	typename Container<T>::iterator readAmount = sequencesOfNumbers.begin();
	size_t prevIndex = 0;
	size_t iter = 0;
	size_t insertedElements = 1;
	while (_mainChain.size() / 2 < (_tmp.size()))
	{
		iter += *readAmount;
		while (iter > prevIndex)
		{
			if (iter <= _pend.size() - 1)
			{
				pos = std::upper_bound(_mainChain.begin(), _mainChain.begin() + iter + insertedElements, _pend.at(iter));
				_mainChain.insert(pos, _pend.at(iter));
				insertedElements++;
			}
			iter--;
		}
		prevIndex += *readAmount;
		iter = prevIndex;
		readAmount++;
	}
	if (_oddElements)
	{
		pos = std::lower_bound(_mainChain.begin(), _mainChain.end(), _lastElement);
		_mainChain.insert(pos, _lastElement);
		
	}
	if (!std::is_sorted(_mainChain.begin(), _mainChain.end()))
	{
		std::cerr << "Error\n" << std::endl;
		std::cout << "_mainChaind = ";
		for (size_t iter = 0; iter < _mainChain.size(); iter++)
			std::cout << _mainChain[iter] << " ";
		std::cout << std::endl;
		throw std::runtime_error("Couldn't sort the vector");
	}
	else
	{
		_vec = _mainChain;
	}
}

template <typename T, template<typename...> class Container>
const char *PmergeMe<T, Container>::InvalidNumberException::what() const noexcept
{
	return ("Invalid number");
}

template class PmergeMe<int, std::vector>;
template class PmergeMe<int, std::deque>;