#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int accID, int balance, const char *name)
    : accID(accID), balance(balance)
{
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account(const Account &copy)
    : accID(copy.accID), balance(copy.balance)
{
    int len = strlen(copy.cusName) + 1;
    cusName = new char[len];
    strcpy(cusName, copy.cusName);
}

int Account::GetID() const { return accID; }

void Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdraw(int money)
{
    if (balance < money)
        return 0;
    balance -= money;
    return money;
}

void Account::showAccInfo() const
{
    cout << "계좌ID: " << accID << endl;
    cout << "이 름: " << cusName << endl;
    cout << "잔 액: " << balance << endl;
}

Account::~Account()
{
    delete[] cusName;
}