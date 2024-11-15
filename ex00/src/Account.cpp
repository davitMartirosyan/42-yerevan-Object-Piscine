#include "../inc/Account.hpp"

size_t Account::tableId = 0;

Account::Account(size_t iterId, std::string const &f, std::string const &l, double deposit) 
	: id(iterId), fname(f), lname(l), amount(deposit)
{
}

Account::~Account()
{
}

size_t Account::getId( void )
{
	return (this->id);
}

size_t Account::getId( void ) const
{
	return (this->id);
}

size_t Account::getAmount( void )
{
	return (this->amount);
}

size_t Account::getAmount( void ) const
{
	return (this->amount);
}

std::string const &Account::getFname( void )
{
	return (this->fname);
}

std::string const &Account::getFname( void ) const
{
	return (this->fname);
}

std::string const &Account::getLname( void )
{
	return (this->lname);
}

std::string const &Account::getLname( void ) const
{
	return (this->lname);
}


std::ostream& operator<<(std::ostream& os, const Account& ac)
{
	os << 
		"[" << ac.getId() << "] " <<  
		ac.getFname() << " " << ac.getLname() << 
		" - [" << ac.getAmount() << "]";
	return os;
}