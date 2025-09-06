// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	
	typedef std::vector<Account::t>					  accounts_t; //Data container of Account objects
	typedef std::vector<int>						  ints_t; // Ints vector
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; //Pair of iterators, allows to group two variables in a unit
	//Iterator of the account vector and iterator of ints


	/*The following block we are declaring all of the accounts with their initials deposits
	 and creating int vectors with ammount to be deposited or withdrawed to each account */

	//Init vector with the constructor =  initial_deposit for each account
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	//calculates the total of accounts to be innited
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	//Declare and innit the account vector, starting with amount (first element) and amounts + amounts_size (last one of the vector) 
	accounts_t				accounts( amounts, amounts + amounts_size );
	//Iterators a.k.a to know the start and end of the vector
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	//Init vector of the deposits to do
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	//Calculates the total of deposits that we have before
	size_t const		d_size( sizeof(d) / sizeof(int) );
	//Declare and initialize the vector of int for the deposits
	ints_t				deposits( d, d + d_size );
	//Iterators a.k.a to know the start and end of the vector
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	//Init vector of the withdrawls to do
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	//Calculates the total of withdrawls that we have before
	size_t const		w_size( sizeof(w) / sizeof(int) );
	//Declare and initialize the vector of int for the withdrawls
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	//Iterators a.k.a to know the start and end of the vector
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	/*Recorre todos los objetos Account en el vector accounts.
	Para cada objeto Account, llama a su función displayStatus.*/

	//for (initialization; condition; increment)
	/*We create a new pair of iterator to go through all of the account and deposits and make 
	the corresponding deposit operation	*/

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
		/**(it.first) dereferences the first iterator, giving you the current Account object.
		*(it.second) dereferences the second iterator, giving you the current int value from the deposits vector.*/

	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
