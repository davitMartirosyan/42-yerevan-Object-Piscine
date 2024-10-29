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
		void add(std::string const &, std::string const &, std::string const &);
		void deposit(std::string const &, int);
	public:
		float getBalance(std::string const &);
		std::string const &getFname(std::string const &);
	private:
		class Account{
			public:
				Account(std::string const &, 
						std::string const &,
						std::string const &);
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
				void setId(int);
				void setFname(std::string const &);
				void setLname(std::string const &);
				void setBalance(float);
				void setPassport(std::string const &);
				friend class Bank;
		};
		std::map<std::string, Account*> users;	
		static int id;
		int funds;
		int loan;
	public:
		typedef std::map<std::string, Account*>::iterator UsersDb;
};

#endif
