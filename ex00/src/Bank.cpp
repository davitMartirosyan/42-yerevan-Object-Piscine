#include "../inc/Bank.hpp"

Bank::Bank(std::string const &bank) : bankName(bank)
{
}

Bank::~Bank()
{
	for(A_it it = begin(); it != end(); it++)
		delete (*it);
}

std::string const &Bank::getBankName( void )
{
	return (bankName);
}

bool Bank::newAccount(std::string const &fname, std::string const &lname, double deposit)
{
	if (deposit < 0)
		throw std::runtime_error(std::string("Invalid Deposit: "));
	double bank_tax = deposit * 0.05;
	this->liquidity += bank_tax;
	this->accounts.push_back(new Account(Account::tableId++, fname, lname, deposit - bank_tax));

	return (true);
}

bool Bank::deleteAccount(size_t id)
{
	for (A_it it = begin(); it != end(); it++)
	{
		if (id == (*it)->getId()){
			this->accounts.erase(it);
			return (true);
		}
	}
	std::cout << "Error: Account not found" << std::endl;
	return (false);
}

bool Bank::deposit(double amount, size_t id)
{
	for(A_it it = begin(); it != end();it++)
	{
		if (id == (*it)->getId())
		{
			double bank_tax = amount * 0.05;
			this->liquidity += bank_tax;
			(*it)->amount += amount - bank_tax;
		       return (true);	
		}
	}
	std::cout << "Error: Deposit action can't be made" << std::endl;
	return (false);

}


bool Bank::withdraw(double amount, size_t id)
{
	for(A_it it = begin(); it != end();it++)
	{
		if (id != (*it)->getId())
		{
			if (amount > (*it)->amount)
			{
				std::cout << "Error: Not enough money" << std::endl;
				return false;
			}
			(*it)->amount -= amount;
			return (true);
		}
	}
	return (false);
}


bool Bank::loan(double amount, size_t id)
{
	if (amount > this->liquidity)
	{
		std::cout << "Error: Loan can't be granted for" << std::endl;
		return (false);
	}
	for(A_it it = begin(); it != end(); it++)
	{
		if (id == (*it)->getId())
		{
			(*it)->amount += amount;
			return (true);
		}
	}
	std::cout << "Error: Account not found" << std::endl;
	return (false);
}

double Bank::getLiquidity( void )
{
	return (this->liquidity);
}

double Bank::getLiquidity( void ) const
{
	return (this->liquidity);
}

Account* Bank::getAccount( size_t id)
{
	for(A_it it = begin(); it != end(); it++)
	{
		if (id == (*it)->getId())
			return (*it);
	}
	std::cout << "Error: Account not found" << std::endl;
	return (NULL);
}

A_it Bank::begin( void )
{
	return (accounts.begin());
}

A_cit Bank::begin( void ) const
{
	return (accounts.begin());
}

A_it Bank::end( void )
{
	return (accounts.end());
}

A_cit Bank::end( void ) const
{
	return (accounts.end());
}

std::ostream& operator<<(std::ostream& os, const Bank& bank)
{
	os << "Bank informations: " << std::endl;
	os << "Liquidity:" << bank.getLiquidity() << std::endl;
	for (A_cit it = bank.begin(); it != bank.end(); it++)
		os << (**it) << std::endl;
	
	return os;
}