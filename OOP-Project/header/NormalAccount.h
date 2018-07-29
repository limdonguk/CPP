#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "Account.h"

class NormalAccount : public Account
{
private:
	int ratio;

public:
	NormalAccount(int accID, int balance, const char *name, int ratio)
		: Account(accID, balance, name), ratio(ratio)
	{
	}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money*(ratio / 100.0));
	}
};

#endif