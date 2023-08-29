#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include "BankAccount.h"

using namespace std;

class CheckingAccount : public BankAccount{
private:
    double owed;

public:
    CheckingAccount(double bal, double air):BankAccount(bal, air){
            owed = 0.0;
        }
    double getAmountOwed() const{
        return owed;
    }
    virtual void withdraw(double w){
        if(w > balance){
            cout << "Withdrawal failed! You attempted to check Rs.";
            cout << w << " but current balance is Rs." << balance;
            cout << ".\nYou will be charged Rs.15.00 for this.\n";
            balance -= 15.0;
        }
        else{
            BankAccount::withdraw(w);
        }
    }
    virtual ServAndOwed monthlyProc(){
        serviceCharges += 5.0;
        serviceCharges += 0.1 * numWithdrawal;
        mnCharges += serviceCharges;
        ServAndOwed temp;
        temp.servCharges = serviceCharges;
        BankAccount::monthlyProc();
        if(balance < 0){
            owed = 0 - balance;
        }
        temp.totalOwed = owed;
        owed = 0;
        return temp;
    }

};

#endif