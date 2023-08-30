#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

using namespace std;

struct ServAndOwed{
    double servCharges;
    double totalOwed;
};

class BankAccount{

    protected:
        double balance;
        int numDeposits;
        int numWithdrawal;
        double annualIntRate;
        double mnCharges;
        double serviceCharges;

public:
    BankAccount(double bal, double air){
        if(bal < 0){
            cout << "Please enter postive number"<<endl;
            exit(EXIT_FAILURE);
        }
        if(air < 0){
            cout << "Please enter postive number"<<endl;
            exit(EXIT_FAILURE);
        }
        balance = bal;
        annualIntRate = air;

        numDeposits = 0;
        numWithdrawal = 0;
        mnCharges = 0.0;
        serviceCharges = 0.0;
    }
    double getBalance(){
        return balance;
    }

    int getNumDeposits() {
        return numDeposits;
    }

    int getNumWithdrawals() {
        return numWithdrawal;
    }

    double getAnnualIntRate() {
        return annualIntRate;
    }

    double getMonthlyCharges() {
        return mnCharges;
    }
    void setAnnualIntRate(double air){
        while(air < 0){
            cout << "Please enter positive number for annual interest"<<endl;
            cin >> air;
        }
        annualIntRate = air;
    }

    void setMonthlyCharges(double mc){
        while(mc < 0){
            cout << "Please enter postitive values ";
            cin >> mc;
        }
        mnCharges = mc;
    }
    virtual void deposit(double d){
        balance += d;
        numDeposits++;
    }
    virtual void withdraw(double w){
        balance -= w;
        numWithdrawal++;
    }
    virtual void calcInt(){
        balance += (annualIntRate/12.0)*balance;
    }
    virtual ServAndOwed monthlyProc(){
        balance -= mnCharges;
        calcInt();
        numDeposits = 0;
        numWithdrawal = 0;
        mnCharges = 0.0;
        serviceCharges = 0.0;
        ServAndOwed temp;
        return temp;
    }
};
#endif