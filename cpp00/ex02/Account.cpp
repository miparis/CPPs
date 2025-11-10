/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:37:20 by miparis           #+#    #+#             */
/*   Updated: 2025/10/18 16:32:42 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

/* 					Constructor and destructor of the class					*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account:: Account( int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_totalAmount += initial_deposit;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account:: ~Account( void )
{
	 _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
   	std::cout << "amount:" << _amount << ";";
   	std::cout << "closed" << std::endl;
}


/* 					Static variables getters				*/

int	Account::getNbAccounts(void )//Returns the number of accounts
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )//Returns the total inputed in all of the Accounts
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )// Return the number of deposit made/registered?
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )// Returns the nbr of withdrawls made on the account
{
	return (_totalNbWithdrawals);
}

/* 							Objects instances operations					*/
/*The const at the end of the method means it wont modify any variable
from the object instance*/
int		Account::checkAmount( void ) const
{
	return (_amount);
}

/*
[19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
[19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1
*/
void	Account::makeDeposit( int deposit )
{
	int		p_Amount = _amount;
	
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	 _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_Amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}
/*
index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
index:5;p_amount:23;withdrawal:refused
*/
bool	Account::makeWithdrawal( int withdrawal )
{
	bool	state = true;
	int		p_amount = _amount;

	_displayTimestamp();
	if (checkAmount() < withdrawal)
	{
		state = false;
		std::cout << "index:" << _accountIndex << ";";
    	std::cout << "p_amount:" << p_amount << ";";
    	std::cout << "withdrawal:refused" << std::endl;
	}
	else if (checkAmount() >= withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		state = true;
		std::cout << "index:" << _accountIndex << ";";
    	std::cout << "p_amount:" << p_amount << ";";
    	std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std:: cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (state);
}
/* 						Timestamps and status									*/

// [YYYYMMDD_HHMMSS]
void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    char buffer[16];
    std::tm *timeinfo;

    timeinfo = std::localtime(&now);
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "] ";
}
 //Verification of each instance of the object
/*
**This method prints the actual state of an account in the format:
** [timestamp] index:X;amount:X;deposits:X;withdrawals:X
*/
void    Account::displayStatus( void ) const
{
    _displayTimestamp(); // Muestra el timestamp
    
//We use this-> to said explicitly "hey access to this member of this specific object instance".

    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

//"Global" display of all of the info
/*
** This method prints the global state of all the accounts in the format:
** [timestamp] accounts:X;total:X;deposits:X;withdrawals:X
*/
void    Account::displayAccountsInfos( void ) 
{
    _displayTimestamp(); // Muestra el timestamp
    
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}