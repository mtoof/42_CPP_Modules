/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:21:31 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/15 20:09:06 by mtoof            ###   ########.fr       */
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
	virtual const char *what() const noexcept
	{
		return ("Not found");
	}
};

template <typename T>
void easyfind(T const &container, int value)
{
	typename T::const_iterator item = std::find(container.begin(), container.end(), value);
	if (item != container.end())
		std::cout << "Found the item \"" << value << "\" at position :" << std::distance(container.begin(), item) << std::endl;
	else
		throw NotFoundException();
	return;
}

#endif