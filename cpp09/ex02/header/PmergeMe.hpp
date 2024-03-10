/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:15 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/10 15:29:47 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <utility>
#include <numeric>

#define RESET   "\033[0m"
#define RED     "\033[31m"

template <typename T, template<typename...> class Container>
class PmergeMe
{
private:
	Container<T> _vec;
	Container<std::pair<T,T>> _tmp;
	Container<T> _mainChain;
	Container<T> _pend;
	
	int _lastElement;
	bool _oddElements;

	void fordJohnson();
	void pairAndSort();
	void sortByGreater(Container<std::pair<T,T>> &vec, size_t vecSize, size_t start);
	void separateGreaterFromSmaller();
	void SequenceGenerator(Container<T> &vec, int n);
	
	void insertionSort();
	
	PmergeMe &operator=(const PmergeMe &rhs);
	PmergeMe(const PmergeMe &rhs);

	std::chrono::high_resolution_clock::time_point end_time;
	std::chrono::high_resolution_clock::time_point start_time;

public:
	PmergeMe();
	~PmergeMe();
	
	void parseNumbers(int ac, char **av, std::string identifier);
	void print(std::string flag) const;
	class InvalidNumberException: public std::exception
	{
		public:
			const char* what() const noexcept;
	};
};

#endif