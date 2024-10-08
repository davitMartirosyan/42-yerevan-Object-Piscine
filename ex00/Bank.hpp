#ifndef BANK_HPP
#define BANK_HPP
#include <iostream>
#include <vector>
#include <map>

typedef struct Account Account;

class Bank
{
	private:
		struct Account
		{
			std::string fname;
			std::string lname;
			std::string surname;
			std::string passport;
			int id;
			int value;
			int balance;
			int age;
		};
	public:
		Bank();
		~Bank();
	public: //Account utilities
		void withdraw(int wdraw);
		void deposit(int depo);
		void login(std::string const &passport);
	public:
		void add(std::string const &fname, std::string const &lname, std::string const &surname, std::string const &passport, int age);
		void remove(std::string const &passport);
		void change(std::string const &passport, std::string const &newPassport);
		void change(std::string const &passport, std::string const &newFname, std::string const &newLname);
	public:
		int getLiquidity( void ) const;
	private:
		int id;
		int liquidity;
		int fund;
		std::string sessionId;
		std::map<std::string, Account *> clientsAccounts;
};

#endif
