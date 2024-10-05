#include "Bank.hpp"

int Bank::id = 0;

Bank::Bank() : liquidity(0)
{

}

Bank::~Bank()
{

}

int Bank::getLiquidity( void ) const
{
	return (liquidity);
}
