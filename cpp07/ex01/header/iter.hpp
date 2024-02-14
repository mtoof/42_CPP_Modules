/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:06:39 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/14 16:30:45 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
template <typename TArray, typename TFunction>
void iter (TArray array[], int array_size, TFunction item_function)
{
	for (int index = 0; index < array_size; index++)
		item_function(array[index]);
}

template <typename TArray>
void print_array(const TArray &array_item)
{
	std::cout << array_item << std::endl;
}

template <typename TArray>
void increment_array(TArray &array_item)
{
	array_item++;
}
#endif