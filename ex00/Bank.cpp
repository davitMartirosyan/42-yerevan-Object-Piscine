#include "Bank.hpp"

int Bank::id = 0;
Bank::Bank()
    : funds(5000), loan(0)
{

}

Bank::~Bank()
{
    UsersDb it = users.begin();
    while (it != users.end())
    {
        if (it->second)
        {
            delete it->second;
            it->second = NULL;
        }
        it++;
    }
}

void Bank::add(std::string const &passport, std::string const &f, std::string const &l)
{
    // check if passport already exist
    UsersDb it = users.find(passport);
    if (it != users.end())
    {
        std::cout << "User already Exist" << std::endl;
        return ;
    }
    Bank::Account* client = new Bank::Account(passport, f, l);
    users.insert(std::make_pair(passport, client));
    id++;
    std::cout << "Welcome: " << f + " " + l << std::endl;
}

void Bank::deposit(std::string const &passport, int balance)
{
    UsersDb it = users.begin();
    int tBalance = balance;
    while (it != users.end())
    {
        if (it->second->getPassport() == passport)
        {
            this->funds = tBalance = balance * 0.05;
            it->second->setBalance(balance - tBalance);
            return ;
        }
        it++;
    }
    tBalance = 0;
    throw std::runtime_error("Account not found");
}

float Bank::getBalance(std::string const &passport)
{
    UsersDb db = users.begin();
    while (db != users.end())
        if (db->second->getPassport() == passport)
            return (db->second->getBalance());
    throw std::runtime_error("Account not found");
}

std::string const &Bank::getFname(std::string const &passport)
{
    UsersDb it = users.find(passport);
    if (it != users.end())
        return (it->second->getFname());
    throw std::runtime_error("Account not found");
}


Bank::Account::Account(std::string const &passport, 
						std::string const &f,
						std::string const &l)
						: balance(0.0)
{
    this->setPassport(passport);
    this->setFname(f);
    this->setLname(l);
    this->setId(id);
}

Bank::Account::~Account()
{
    
}

std::string const &Bank::Account::getFname( void ) const
{
    return (this->fname);
}

std::string const &Bank::Account::getLname( void ) const
{
    return (this->lname);
}
std::string const &Bank::Account::getPassport( void ) const
{
    return (this->passport);
}

float Bank::Account::getBalance( void ) const
{
    return (this->balance);
}

int Bank::Account::getId( void ) const
{
    return (this->id);
}


void Bank::Account::setPassport(std::string const &passport)
{
    this->passport = passport;
}

void Bank::Account::setId(int id)
{
    this->id = id;
}

void Bank::Account::setFname(std::string const &f){
    this->fname = f;
}
void Bank::Account::setLname(std::string const &l){
    this->lname = l;
}

void Bank::Account::setBalance(float balance)
{
    this->balance += balance;
}