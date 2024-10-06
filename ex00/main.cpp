#include <iostream>
#include <stdexcept>
#include "Bank.hpp"

int main ( void )
{
	Bank *AmeriaBank = new Bank;

	AmeriaBank->add("Davit", "Martirosyan", "Sureni", "AP0634545", 26);

	delete AmeriaBank;
}
