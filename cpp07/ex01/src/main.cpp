/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:07:19 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/14 17:01:13 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::string array[3] = {"hello", "world", "this is a test"};

	::iter<std::string>(array, 3, ::print_array<std::string>);

	int int_array[3] = {1, 2 ,3};

	::iter<int>(int_array, 3, ::increment_array<int>);
	::iter<int>(int_array, 3, ::print_array<int>);
	
	return 0;
}