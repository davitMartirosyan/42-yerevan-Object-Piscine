#include <iostream>
#include "Account.hpp"
#include "Bank.hpp"

int main ( void )
{
	Bank *AmeriaBank = new Bank;
	//bank->newAccount("Davit", "Martirosyan", "Sureni", 26);
	AmeriaBank->getLiquidity();
}
