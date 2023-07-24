#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <unistd.h>
#include "Account.hpp"

using std::cout;
using std::endl;

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
	time_t time;
	tm *finaltime;
	char str[19];

	str[18] = '\0';
	std::time(&time);
	finaltime = std::localtime(&time);
	std::strftime(str, 18, "[%Y%m%d_%H%M%S] ", finaltime);
	cout << str;
}


void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts << ";";
	cout << "total:" << _totalAmount << ";";
	cout << "deposits:" << _totalNbDeposits << ";";
	cout << "withdrawals:" << _totalNbWithdrawals << endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << initial_deposit << ";";
	cout << "created" << endl;
}

Account::~Account()
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";";
	cout << "closed" << endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	cout << "deposit:" << deposit << ";";
	this->_amount = this->_amount + deposit;
	_totalAmount += deposit;
	_totalNbDeposits = _totalNbDeposits + 1;
	this->_nbDeposits = this->_nbDeposits + 1;
	cout << "amount:" << this->_amount << ";";
	cout << "nb_deposits:" << this->_nbDeposits << endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->_amount - withdrawal < 0)
	{
		cout << "index:" << this->_accountIndex << ";";
		cout << "p_amount:" << this->_amount << ";";
		cout << "withdrawal:refused" << endl;
		return false;
	}
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	cout << "withdrawal:" << withdrawal << ";";
	this->_amount = this->_amount - withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals = _totalNbWithdrawals + 1;
	this->_nbWithdrawals = this->_nbWithdrawals + 1;
	cout << "amount:" << this->_amount << ";";
	cout << "nb_withdrawals:" << this->_nbWithdrawals << endl;
	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";";
	cout << "deposits:" << this->_nbDeposits << ";";
	cout << "withdrawals:" << this->_nbWithdrawals << endl;
}

int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
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
