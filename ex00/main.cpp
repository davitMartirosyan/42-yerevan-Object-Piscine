#include <iostream>
#include <stdexcept>
#include "Bank.hpp"

int main ( void )
{
	Bank* AmeriaBank = new Bank;
	try{

		AmeriaBank->add("AP06500", "Davit", "Martirosyan");
		AmeriaBank->add("AP06354", "Garik", "Martirosyan");


		delete AmeriaBank;

	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		delete AmeriaBank;
	}
}
