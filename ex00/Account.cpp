#include "Account.hpp"

Account::Account(std::string const &fname, std::string const &lname, std::string const &surname)
{
	this->fname = fname;
	this->lname = lname;
	this->surname = surname;
	value = 0;
	id = -1;
}

Account::~Account()
{

}

int Account::getId( void ) const
{
	return (id);
}

int Account::getValue( void ) const
{
	return (value);
}

int Account::getBalance( void ) const
{
	return (balance);
}

int Account::getAge( void ) const
{
	return (age);
}
