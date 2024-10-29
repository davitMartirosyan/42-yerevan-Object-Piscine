#ifndef BANK_HPP
#define BANK_HPP
#include <iostream>
#include <vector>
#include <map>

class Bank
{
	public:
		Bank();
		~Bank();
	public:
		void add(std::string const &passport, std::string const &f, std::string const &l);
		void deposit(std::string const &passport, int balance);
	public:
		float getBalance(std::string const &passport);
		std::string const &getFname(int id);
	private:
		class Account{
			public:
				Account(std::string const &passport, 
						std::string const &f,
						std::string const &l);
				~Account();
			public:
				std::string const &getFname( void ) const;
				std::string const &getLname( void ) const;
				std::string const &getPassport( void ) const;
				float getBalance( void ) const;
				int getId( void ) const;
			private:
				int id;
				// int value;
				float balance;
				std::string fname;
				std::string lname;
				std::string passport;
			private:
				void setId(int id);
				void setFname(std::string const &f);
				void setLname(std::string const &l);
				void setBalance(int balance);
				void setPassport(std::string const &passport);
				friend class Bank;
		};
		std::map<int, Account*> users;	
		static int id;
		int funds;
		int loan;
	public:
		typedef std::map<int, Account*>::iterator UsersDb;
};

#endif
