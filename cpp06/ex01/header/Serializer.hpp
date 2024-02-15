/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:44:50 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/15 17:43:09 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &rhs);
	Serializer &operator=(Serializer const &rhs);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif