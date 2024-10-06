#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <iostream>
#include "Bank.hpp"

class Bank;

class Account
{
	public:
		Account(std::string const &fname, std::string const &lname, std::string const &surname);
		~Account();
//	public:
//		int getId( void ) const;
//		int getValue( void ) const;
//		int getBalance( void ) const;
//		int getAge( void ) const;
	private:
		int id;
		int value;
		int balance;
		int age;
	private:
		std::string fname;
		std::string lname;
		std::string surname;
		std::string passport;
};

#endif
