/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:33:26 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/16 17:35:30 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

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

const char* NotFoundException::what() const noexcept
{
	return ("Not found");
}
