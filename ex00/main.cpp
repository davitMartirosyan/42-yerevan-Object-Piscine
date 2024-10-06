#include <iostream>
#include <stdexcept>
#include "Bank.hpp"

int main ( void )
{
	Bank *AmeriaBank = new Bank;
	try
	{
		AmeriaBank->add("Davit", "Martirosyan", "Sureni", "AP0634545", 26);

		AmeriaBank->login("AP0634545");

		AmeriaBank->deposit(500);

	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete AmeriaBank;
		return (1);
	}
	delete AmeriaBank;
	return (0);
}
