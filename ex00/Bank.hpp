#ifndef BANK_HPP
#define BANK_HPP
#include <vector>
#include "Account.hpp"

class Account;

class Bank
{
	public:
		Bank();
		~Bank();
	public:
		Account* newAccount(std::string const &fname, std::string const &lname, std::string const &surname, int age);
		int getLiquidity( void ) const;
	private:
		static int id;
		int liquidity;
		std::vector<Account*> clientAccounts;
};

#endif
