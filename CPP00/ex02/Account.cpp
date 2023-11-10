/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped <joaoped2@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:17:10 by joaoped           #+#    #+#             */
/*   Updated: 2023/11/09 19:26:51 by joaoped          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
    std::time_t t;
    std::tm *datetime;

    t = std::time(NULL);
    datetime = std::localtime(&t);
    std::cout << "[" << datetime->tm_year + 1900;
    std::cout << datetime->tm_mon + 1;
    std::cout << datetime->tm_mday << "_";
    std::cout << datetime->tm_hour;
    std::cout << datetime->tm_min;
    std::cout << datetime->tm_sec << "] ";
}

Account::Account( int initial_deposit ) {
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
    _nbAccounts++;
}

Account::Account( void ) {
    _amount = 0;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
    _totalNbDeposits++;
    _nbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << _amount << ";";
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:" << withdrawal << ";";
    _amount -= withdrawal;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount() const {
    return (_amount);
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
