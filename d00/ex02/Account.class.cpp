#include "Account.class.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

Account::Account(int initial_deposit) : _amount(initial_deposit), \
_nbDeposits(0), _nbWithdrawals(0), _checkAmountNbCalls(0) {
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += this->checkAmount();

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex \
            << ";amount:" << this->checkAmount() \
            << ";created" \
            << std::endl;
}

Account::~Account(void) {
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex \
            << ";amount:" << checkAmount() \
            << ";closed" \
            << std::endl;
}

int     Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int     Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int     Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int     Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts() \
                << ";total:" << Account::getTotalAmount() \
                << ";deposits:" << Account::getNbDeposits() \
                << ";withdrawals:" << Account::getNbWithdrawals() \
                << std::endl;
}

void	Account::makeDeposit(int deposit) {
    int p_amount = this->checkAmount();
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits += 1;

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex \
                << ";p_amount:" << p_amount \
                << ";deposit:" << deposit \
                << ";amount:" << this->checkAmount() \
                << ";nb_deposits:" << this->_nbDeposits \
                << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex \
                << ";p_amount:" << this->checkAmount() \
                << ";withdrawal:";

    if (this->checkAmount() <= withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    } else
    {
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;

        std::cout << withdrawal \
                << ";amount:" << this->checkAmount() \
                << ";nb_withdrawals:" << this->_nbWithdrawals \
                << std::endl;
        return true;
    }
}

int		Account::checkAmount(void) const {
    this->_checkAmountNbCalls++;
    return this->_amount;
}

void	Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex \
                << ";amount:" << this->checkAmount() \
                << ";deposits:" << this->_nbDeposits \
                << ";withdrawals:" << this->_nbWithdrawals \
                << std::endl;
}

void    Account::_displayTimestamp(void) {
    time_t      rawtime = time(nullptr);
    struct tm   *tm = localtime(&rawtime);

    std::cout << "[" << tm->tm_year + 1900 \
                << std::setw(2) << std::setfill('0') << tm->tm_mon + 1 \
                << std::setw(2) << std::setfill('0') << tm->tm_mday \
                << "_" << std::setw(2) << std::setfill('0') << tm->tm_hour \
                << std::setw(2) << std::setfill('0') << tm->tm_min \
                << std::setw(2) << std::setfill('0') << tm->tm_sec << "]";

}

int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;
