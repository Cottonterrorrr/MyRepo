#include "Checking.h"
#include <iostream>


Checking::~Checking()
{
}

void Checking::Withdraw(float amount)
{
	
	if ((m_Balance-amount)>50)
	{
		Account::Withdraw(amount);
		std::cout << " Withdraw " << std::endl;
	}	
	else
	{
		std::cout << "inseficient Balance. balance need to be more than 50 " << std::endl;
	}
}
