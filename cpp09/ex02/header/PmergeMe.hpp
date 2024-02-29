/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:15 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/29 15:13:08 by mtoof            ###   ########.fr       */
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

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;
	time_t start_time;
	std::chrono::steady_clock::time_point start;
	char *now;
	int _last_element;
	bool _odd_elements;
	void fordJohnson();
	void pairAndSort();
	void sortByGreater(size_t container_size);
	void separateGreaterFromSmaller();
	void insertionSort();
	// time_t end_time;
	// char *end;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);
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