/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:15 by mtoof             #+#    #+#             */
/*   Updated: 2024/03/03 17:47:23 by mtoof            ###   ########.fr       */
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

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;
	std::vector<int> _mainChain;
	std::vector<int> _pend;

	int _last_element;
	bool _odd_elements;
	void fordJohnson();
	void pairAndSort();
	void sortByGreater(size_t container_size);
	void separateGreaterFromSmaller();
	void insertionSort();
	std::chrono::high_resolution_clock::time_point end_time;

	PmergeMe &operator=(const PmergeMe &rhs);
	PmergeMe(const PmergeMe &rhs);
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