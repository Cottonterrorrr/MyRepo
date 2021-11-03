#pragma once
#include "Account.h"
class Checking :
    public Account
{
    public:
        using Account::Account;
        //if i dont use any more attributes in this clas i can use using Account so no need to write Constructor
        //Checking(const std::string& name,float balance);
        ~Checking();

        void Withdraw(float amount) override;

    

};

