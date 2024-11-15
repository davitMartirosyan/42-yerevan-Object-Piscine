#ifndef __BANK_HPP__
#define __BANK_HPP__
#include "Account.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstddef>

class Bank
{
	public:
		Bank(std::string const &bankName);
		std::string const &getBankName( void );
		~Bank();
	public:
		double getLiquidity( void );
		double getLiquidity( void ) const;
		Account* getAccount(size_t id) const;
		Account* getAccount(size_t id);
	public:
		bool newAccount(std::string const &, std::string const &, double);
		bool deleteAccount(size_t id);
		bool deposit(double amount, size_t id);
		bool withdraw(double amount, size_t id);
		bool loan(double amount, size_t id);
	public:
		A_it begin( void );
		A_cit begin( void ) const;
		A_it end( void );
		A_cit end( void ) const;

	private:
		std::string bankName;
		double liquidity;
	private:
		Accounts_t accounts;

};

std::ostream& operator<<(std::ostream& os, const Bank&);

#endif // __BANK_HPP__
