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

	public:
		std::string 	&getFname( void );
		std::string 	getLname( void ) const;
		std::string 	getSurname( void ) const;
		std::string 	getPassport( void ) const;
		int 		getId( void ) const;
		int		getValue( void ) const;
		int		getBalance( void ) const;
		int		getAge( void ) const;
	public:
		int getLiquidity( void ) const;
	private:
		float percent;
		int id;
		int liquidity;
		int fund;
		std::string sessionId;
		std::map<std::string, Account *> clientsAccounts;
};

#endif
