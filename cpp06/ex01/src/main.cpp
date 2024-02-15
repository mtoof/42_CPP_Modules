/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:45:10 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/15 17:42:58 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data *data = new Data();
	Data *deserialized_data = nullptr;
	uintptr_t serialized_data;

	data->n = 1024;
	std::cout << "data->n = " << data->n << std::endl;

	serialized_data = Serializer::serialize(data);
	std::cout << "serialized data = " << serialized_data << std::endl;

	deserialized_data = Serializer::deserialize(serialized_data);
	std::cout << "\ndata address      = " << data << std::endl;
	std::cout << "deserialized data = " << deserialized_data << std::endl;
	std::cout << "deserialized->n = " << deserialized_data->n << std::endl;

	delete data;
	return (0);
}