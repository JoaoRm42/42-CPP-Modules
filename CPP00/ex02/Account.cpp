/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped <joaoped2@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:17:10 by joaoped           #+#    #+#             */
/*   Updated: 2023/11/09 15:31:18 by joaoped          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>

#include "Account.hpp"

void Account::_displayTimestamp( void ) {
    std::time_t t;
    std::tm *datetime;

    t = std::time(NULL);
    datetime = std::localtime(&t);
    std::cout << "[" << datetime->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << datetime->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << datetime->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << datetime->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << datetime->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << datetime->tm_sec << "] ";
}

Account::Account( int initial_deposit ) {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
    _amount = initial_deposit;
}

Account::~Account( void ) {

}

int Account::getNbAccounts( void ) {
    return (0);
}

int Account::getTotalAmount( void ) {
    return (0);
}

int Account::getNbDeposits( void ) {
    return (0);
}

int Account::getNbWithdrawals( void ) {
    return (0);
}

void Account::displayAccountsInfos( void ) {
    std::cout << "accounts:" << Account::_nbAccounts << std::endl;
}

void Account::makeDeposit(int deposit) {
    std::cout << "makeDeposit" << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    std::cout << "makeWithdrawal" << std::endl;
    return (true);
}

int Account::checkAmount() const {
    std::cout << "checkAmount" << std::endl;
    return (0);
}

void Account::displayStatus() const {
    std::cout << "displayStatus" << std::endl;
}