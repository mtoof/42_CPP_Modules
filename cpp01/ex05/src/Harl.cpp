/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:33:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/29 13:06:37 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::_debug(void)
{
	std::cout << "Debug: Database connection pool initialized with 10 connections." << std::endl;
}

void Harl::_info(void)
{
	std::cout <<"Info: User XXX has successfully logged in." << std::endl;
}

void Harl::_warning(void)
{
	std::cout <<"Warning: Disk space running low: only 5% remaining." << std::endl;
}

void Harl::_error(void)
{
	std::cout <<"Error: Failed to connect to the database: timeout after 10 seconds." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*level_function[4])() = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};
	for (int level_index = 0; level_index < 4; level_index++)
	{
		if (!level.compare(levels[level_index]))
		{
			(this->*level_function[level_index])();
			break;
		}
	}
}