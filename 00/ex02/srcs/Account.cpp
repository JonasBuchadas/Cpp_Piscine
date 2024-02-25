#include "Account.hpp"

#include <iostream>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {
  _amount        = 0;
  _nbDeposits    = 0;
  _nbWithdrawals = 0;
  _accountIndex  = _nbAccounts;
  _nbAccounts++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::Account( int initial_deposit ) {
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  _nbDeposits    = 0;
  _nbWithdrawals = 0;
  _accountIndex  = _nbAccounts;
  _nbAccounts++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
}

void Account::makeDeposit( int amount ) {
  int p_amount = _amount;
  _amount += amount;
  _totalAmount += amount;
  _nbDeposits++;
  _totalNbDeposits++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
            << ";deposit:" << amount << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int amount ) {
  if ( amount > _amount ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";withdrawal:refused" << std::endl;
    return false;
  }
  int p_amount = _amount;
  _amount -= amount;
  _totalAmount -= amount;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
            << ";withdrawal:" << amount << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

void Account::_displayTimestamp() {
  time_t curr_time;
  char   date_string[18];

  time( &curr_time );

  strftime( date_string, 18, "[%Y%m%d_%H%M%S]", localtime( &curr_time ) );

  std::cout << date_string << " ";
  return;
}

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
  return;
}

void Account::t::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int Account::checkAmount() const { return _amount; }

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }
