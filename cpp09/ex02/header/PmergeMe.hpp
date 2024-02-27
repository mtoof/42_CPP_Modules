/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:27:15 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/27 13:48:22 by mtoof            ###   ########.fr       */
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
	std::vector<std::pair<int, int>> _vec;
	std::deque<std::pair<int, int>> _deq;
	time_t start_time;
	std::chrono::steady_clock::time_point start;
	char *now;
	int _last_element;
	bool _odd_elements;
	// time_t end_time;
	// char *end;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();
	
	void FordJohson();
	void parseNumbers(int ac, char **av);
	void print(std::string flag) const;
	class InvalidNumberException: public std::exception
	{
		public:
			const char* what() const noexcept;
	};
};

#endif