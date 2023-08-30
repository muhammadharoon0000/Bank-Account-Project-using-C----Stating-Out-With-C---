#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <iomanip>
#include "BankAccount.h"

using namespace std;

class SavingsAccount : public BankAccount{
private:
    bool status;
    bool ACTIVE = true;
    bool INACTIVE = false;

public:
    SavingsAccount(double bal, double air) :
        BankAccount(bal, air)
    {
        if(balance >= 25){
            status = ACTIVE;
        }
        else{
            status = INACTIVE;
        }
    }
    bool getStatus(){
        return status;
    }
    virtual void withdraw(double w){
        if(status == ACTIVE){
            BankAccount::withdraw(w);
            if(balance < 25)
                status = INACTIVE;
        }
        else{
            cout << "Withdrawal failed! Savings account ";
            cout << "is inactive (Current balance: Rs";
            cout << balance << ")" << endl;
        }
    }
    virtual void deposit(double dep){
        if(status == INACTIVE){
            if(dep + balance >= 25){
                BankAccount::deposit(dep);
            }
            else{
                cout << "Deposit failed! Savings account will";
                cout << " be inactive after deposit!\n(Rs";
                cout << balance << " + Rs" << dep;
                cout << " = Rs" << balance + dep << ")\n";
                return;
            }

        }
        else{
            BankAccount::deposit(dep);
        }
    }
    virtual ServAndOwed monthlyProc(){
        if(numWithdrawal > 4){
            serviceCharges += 1.0 * (numWithdrawal - 4);
            mnCharges += serviceCharges;
        }
        ServAndOwed temp;
        temp.servCharges = serviceCharges;
        temp.totalOwed = 0.0;
        BankAccount::monthlyProc();
        if(balance < 25){
            status = INACTIVE;
        }
        return temp;
    }
};

#endif