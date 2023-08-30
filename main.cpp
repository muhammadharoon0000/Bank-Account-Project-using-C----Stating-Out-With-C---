#include <iostream>
#include "SavingAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main()
{
    cout << "SAVINGS ACCOUNT\n\n";
    double startingBalance;
    double annualRate;

    cout << "Enter starting balance of Savings Account: Rs.";
    cin >> startingBalance;

    cout << "\nEnter Annual Interest Rate in %: ";
    cin >> annualRate;
    annualRate = annualRate/100;

    cout << "\nCreating Savings Account""";
    SavingsAccount savAcc(startingBalance, annualRate);
    cout << endl;

    double initProcessCharges;
    cout << "Enter monthly processing charges: Rs.";
    cin >> initProcessCharges;
    savAcc.setMonthlyCharges(initProcessCharges);

    double depos = 0, withdr = 0;
    double totalDepos = 0, totalWithdr = 0;

    cout << "\nEnter the deposits one by one. When finished,";
    cout << " enter -1:" << endl;

    cin >> depos;

    while(depos != -1){
        totalDepos += depos;
        cout << "Performing deposit...\n";
        savAcc.deposit(depos);
        cout<<endl;

        cout << "\nBalance: Rs." << savAcc.getBalance();
        cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
        cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();

        cout << "\n\nEnter another deposit amount, or -1 to stop: ";
        cin >> depos;
    }


    cout << "\nEnter the withdrawals one by one. When finished,";
    cout << " enter -1:" << endl;

    cin >> withdr;

    while(withdr != -1){
        totalWithdr += withdr;
        cout << "Performing withdrawal...\n";
        savAcc.withdraw(withdr);
        cout<<endl;

        cout << "\nBalance: Rs." << savAcc.getBalance();
        cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
        cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();

        cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
        cin >> withdr;
    }

    cout << "\nDone! Here are the monthly statistics: ";
    cout << "\nBeginning balance: Rs." << startingBalance;
    cout << "\nNumber of deposits: " << savAcc.getNumDeposits();
    cout << "\nTotal amount of deposits: Rs." << totalDepos;
    cout << "\nNumber of withdrawals: " << savAcc.getNumWithdrawals();
    cout << "\nTotal amount of withdrawals: Rs." << totalWithdr;
    cout << "\nMonthly charges: Rs." << initProcessCharges;

    ServAndOwed temp = savAcc.monthlyProc();

    cout << "\nService fees: Rs." << temp.servCharges;
    cout << "\nTotal monthly charges: Rs." << initProcessCharges + temp.servCharges;

    cout << "\nEnding balance: Rs." << savAcc.getBalance();

    cout << "\n\n\nCHECKING ACCOUNT\n\n";

    cout << "Enter starting balance of Checking Account: Rs.";
    cin >> startingBalance;

    cout << "\nEnter Annual Interest Rate in %: ";
    cin >> annualRate;
    annualRate = annualRate/100;

    cout << "\nCreating Checking Account";
    CheckingAccount checkAcc(startingBalance, annualRate);
    cout << "Done!\n";

    cout << "Enter monthly processing charges: Rs.";
    cin >> initProcessCharges;
    checkAcc.setMonthlyCharges(initProcessCharges);

    withdr = 0;
    totalWithdr = 0;

    cout << "\nEnter the withdrawals one by one. When finished,";
    cout << " enter -1:\n";

    cin >> withdr;

    while(withdr != -1){
        totalWithdr += withdr;

        cout << fixed << setprecision(2);
        cout << "Performing deposit...\n";
        checkAcc.withdraw(withdr);
        cout << "Done!\n";

        cout << "\nBalance: Rs." << checkAcc.getBalance();
        cout << "\nNumber of deposits: " << checkAcc.getNumDeposits();
        cout << "\nNumber of withdrawals: " << checkAcc.getNumWithdrawals();

        cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
        cin >> withdr;
    }

    cout << "Done! Here are the monthly statistics: ";
    cout << "\nBeginning balance: Rs." << startingBalance;
    cout << "\nNumber of withdrawals: Rs." << checkAcc.getNumWithdrawals();
    cout << "\nTotal amount of withdrawals: Rs." << totalWithdr;
    cout << "\nInitial monthly charges: Rs." << initProcessCharges;

    temp = checkAcc.monthlyProc();

    cout << "\nService fees: Rs." << temp.servCharges;
    cout << "\nTotal monthly charges: Rs." << initProcessCharges + temp.servCharges;
    cout << "\nEnding balance: Rs." << checkAcc.getBalance();
    cout << "\nClient owes to bank: Rs." << checkAcc.getAmountOwed();
    cout << endl;
    return 0;
}