// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); //Returns the number of accounts
	static int	getTotalAmount( void ); //Returns the total inputed in all of the Accounts
	static int	getNbDeposits( void ); // Return the number of deposit made/registered?
	static int	getNbWithdrawals( void ); // Returns the nbr of withdrawls made on the account
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );//Constructor with default value setted
	~Account( void ); //Destructor

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;

// [TIMESTAMP]		_accountINdex	PreviousAmount	_totalNbWithdrawl	_totalAmount	_totalNbWithdrawals;			
//[19920104_091532] index:4;		p_amount:1321;	withdrawal:76;		amount:1245;	nb_withdrawals:1

private:
	// static variables init in the tests.cpp
	static int	_nbAccounts; // count of all Account objects created.
	static int	_totalAmount; // This will track the total amount across all accounts.
	//These will track the total number of deposits and withdrawals made across all accounts.
	static int	_totalNbDeposits; 
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	//Instance variables
	int				_accountIndex; //A unique index for each account.
	int				_amount; //  The current balance for that specific account.
	//The number of deposits and withdrawals for that specific account
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
