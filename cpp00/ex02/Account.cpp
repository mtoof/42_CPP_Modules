/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:24:24 by mtoof             #+#    #+#             */
/*   Updated: 2023/10/24 17:53:33 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	:_accountIndex(_nbAccounts),_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" << "amount:" << _amount \
	<< ";" << "created" << std::endl;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);	
}

void	Account::_displayTimestamp( void )
{
		std::time_t currentTime = std::time(NULL);
    std::tm* localTime = std::localtime(&currentTime);
	//Date//
	std::cout << "[" <<std::setfill('0') << (1900 + localTime->tm_year)
              << std::setfill('0') << (localTime->tm_mon + 1) \
			  << localTime->tm_mday << "_" \
	//Time//
	<< std::setfill('0') << std::setw(2) << localTime->tm_hour \
	<< std::setfill('0') << std::setw(2) << localTime->tm_min \
	<< std::setfill('0') << std::setw(2) << localTime->tm_sec<<"]";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " " \
	<< "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";" \
	<< "deposits:" << getNbDeposits() << ";" << "withdrawls:" << getNbWithdrawals() << std::endl;
	}

// *************************************************************//

void	Account::makeDeposit( int deposit )
{
	int p_amount = _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount;
    _nbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount" << _amount << \
	";nb_deposits:" << _nbDeposits <<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount" << p_amount;
	if (_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:" << "refused" <<std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount" << _amount << \
	";nb_withdrawals:" << _nbWithdrawals <<std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " " \
	<< "index:" << _accountIndex << ";" << "amount:" << checkAmount() << ";" \
	<< "deposits:" << _nbDeposits << ";" << "withdrawls:" << _nbWithdrawals << std::endl;
}
