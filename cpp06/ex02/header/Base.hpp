/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:51:57 by mtoof             #+#    #+#             */
/*   Updated: 2024/02/13 16:27:45 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <random>
#include <iostream>

class Base
{
public:
	virtual ~Base();
	Base	*generate(void);
	void	identify(Base* p);
	void	identify(Base& p);
};

#endif