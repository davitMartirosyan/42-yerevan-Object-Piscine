#include <iostream>
#include "inc/Bank.hpp"

int main( void )
{
	Bank* bank = new Bank("AmeriaBank");
	bank->newAccount("Davit", "Martirosyan", 300);
	bank->newAccount("Vachagan", "Hovhannisyan", 200);

	std::cout << "************************" << std::endl;

	std::cout << *bank << std::endl;
	delete bank;
}
