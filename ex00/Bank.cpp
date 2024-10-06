#include "Bank.hpp"

Bank::Bank() : id(0), liquidity(0)
{

}

Bank::~Bank()
{
	std::map<std::string, Account*>::iterator itr = clientsAccounts.begin();
	while (itr != clientsAccounts.end())
	{
		Account* tmp = itr->second;
		itr++;
		delete tmp;
	}
}

int Bank::getLiquidity( void ) const
{
	return (liquidity);
}

void Bank::add(std::string const &fname, std::string const &lname, std::string const &surname, std::string const &passport, int age)
{
	if (clientsAccounts.find(passport) != clientsAccounts.end())
		std::cout << "There is one cusomter with this passport" << std::endl;
	else
	{
		std::cout << "New Cusomter" << std::endl;
		Account *newCustomer = new Account;
		newCustomer->fname = fname;
		newCustomer->lname = lname;
		newCustomer->age = age;
		newCustomer->surname = surname;
		newCustomer->passport = passport;
		newCustomer->id = id++;
		newCustomer->balance = 0;
		newCustomer->value = 0;

		clientsAccounts.insert(std::make_pair(passport, newCustomer));
		std::cout << fname << " " << lname << std::endl;

	}
}
