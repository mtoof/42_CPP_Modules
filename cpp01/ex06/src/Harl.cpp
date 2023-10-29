/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:33:11 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/29 14:07:33 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::_debug(void)
{
	std::cout << "[Debug]\nDatabase connection pool initialized with 10 connections." << std::endl;
}

void Harl::_info(void)
{
	std::cout <<"[Info]\nUser XXX has successfully logged in." << std::endl;
}

void Harl::_warning(void)
{
	std::cout <<"[Warning]\nDisk space running low: only 5% remaining." << std::endl;
}

void Harl::_error(void)
{
	std::cout <<"[Error]\nFailed to connect to the database: timeout after 10 seconds." << std::endl;
}

void Harl::complain(std::string level)
{
	void	(Harl::*level_function[])() = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};
	switch (_level_finder(level))
	{
	case DEBUG:
	{
		(this->*level_function[DEBUG])();
	}
	case INFO:
	{
		(this->*level_function[INFO])();
	}
	case WARNING:
	{
		(this->*level_function[WARNING])();
	}
	case ERROR:
	{
		(this->*level_function[ERROR])();
	}
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

int Harl::_level_finder(std::string level)
{
	int max_level = 4;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int level_index = 0; level_index < max_level; level_index++)
	{
		if (!level.compare(levels[level_index]))
		{
			return (level_index);
		}
	}
	return (-1);
}