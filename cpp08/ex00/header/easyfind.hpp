/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:21:31 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/16 17:34:27 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class NotFoundException : public std::exception
{
public:
	virtual const char *what() const noexcept;
};

template <typename T>
void easyfind(T const &container, int value);

#include "easyfind.tpp"

#endif