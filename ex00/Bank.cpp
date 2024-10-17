#include "Bank.hpp"

Bank::Bank() : percent(0.95), id(0), liquidity(0), fund(0), sessionId("")
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

void Bank::deposit(int depo)
{
	if (sessionId.empty())
		throw std::logic_error("Please Login!");
	fund += depo - (percent * depo);
	depo = (percent * depo);
	std::map<std::string, Account*>::iterator itr = clientsAccounts.find(sessionId);
	if (itr != clientsAccounts.end())
	{
		itr->second->balance = depo;
		std::cout << itr->second->balance << std::endl;

		std::cout << "Bank Funds: " << fund << std::endl;
		std::cout << itr->second->passport << " funds: " << itr->second->balance << std::endl;
	}
}

void Bank::login(std::string const &passport)
{
	if (clientsAccounts.find(passport) != clientsAccounts.end())
	{
		sessionId = passport;
	}
	else
	{
		throw std::logic_error("Login Failed!");
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
		std::cout << "Welcome " << fname << " " << lname << std::endl;

	}
}

//std::string &Bank::getFname( void )
//{
//	if (sessionId.empty())
//		throw std::logic_error("Please Login!");
//	std::map<std::string, Account*>::iterator itr = clientsAccounts.find(sessionId);
//	if (itr != clientsAccounts.end())
//		return (itr->second->fname);		
//}

