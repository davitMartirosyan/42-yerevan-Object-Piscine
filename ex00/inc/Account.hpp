#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__
#include <vector>
#include <string>
#include <cstddef>
#include <iostream>

class Account
{
	friend class Bank;
	private:
		Account(size_t id, std::string const &, std::string const &, double);
		~Account();
		Account(const Account &cpto);
	public:
		size_t getId( void );
		size_t getId( void ) const;
		size_t getAmount( void );
		size_t getAmount( void ) const;
	public:
		std::string const &getFname( void );
		std::string const &getFname( void ) const;
		std::string const &getLname( void );
		std::string const &getLname( void ) const;
	private:
		size_t id;
		std::string fname;
		std::string lname;
		double amount;
		static size_t tableId;
};
typedef	std::vector<Account*>		Accounts_t;
typedef Accounts_t::iterator		A_it;
typedef Accounts_t::const_iterator	A_cit;
std::ostream& operator<<(std::ostream& os, const Account&);


#endif //__ACCOUNT_HPP__
