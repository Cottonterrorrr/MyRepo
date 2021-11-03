// Account_m.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"


int main()
{
   
    

    Account* acc= new Savings("bob", 100, 0.05f);
    delete acc;

    

    return 0;
}

 