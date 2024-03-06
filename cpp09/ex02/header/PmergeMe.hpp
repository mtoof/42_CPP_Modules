/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:15 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/06 16:29:51 by mtoof            ###   ########.fr       */
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

#define RESET   "\033[0m"
#define RED     "\033[31m"

class PmergeMe
{
private:
	std::vector<std::pair<int,int>> _vec;
	std::deque<std::pair<int,int>> _deq;
	std::vector<int> _mainChain;
	std::vector<int> _pend;
	
	int _lastElement;
	bool _oddElements;

	void fordJohnson();
	void pairAndSort();
	void sortByGreater(std::vector<std::pair<int,int>> &vec, size_t vecSize, size_t start);
	void separateGreaterFromSmaller();
	void merge(std::vector<std::pair<int, int>> tmp, std::vector<std::pair<int, int>> vec, size_t start, size_t middle, size_t vecSize);
	void insertionSort();
	
	PmergeMe &operator=(const PmergeMe &rhs);
	PmergeMe(const PmergeMe &rhs);

	std::chrono::high_resolution_clock::time_point end_time;
	std::chrono::high_resolution_clock::time_point start_time;

public:
	PmergeMe();
	~PmergeMe();
	
	void parseNumbers(int ac, char **av);
	void print(std::string flag) const;
	class InvalidNumberException: public std::exception
	{
		public:
			const char* what() const noexcept;
	};
};

#endif