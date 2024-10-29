#include <iostream>
#include <stdexcept>
#include "Bank.hpp"

int main ( void )
{
	Bank* AmeriaBank = new Bank;
	try{

		AmeriaBank->add("AP06500", "Davit", "Martirosyan");
		AmeriaBank->add("AP06354", "Garik", "Martirosyan");

		AmeriaBank->deposit("AP06500", 2000);
		AmeriaBank->deposit("AP06500", 2000);
		AmeriaBank->deposit("AP06500", 2000);
		AmeriaBank->deposit("AP06500", 2000);


		float myBalance = AmeriaBank->getBalance("AP06500");
		std::cout << myBalance << std::endl;
		delete AmeriaBank;

	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		delete AmeriaBank;
	}
}
