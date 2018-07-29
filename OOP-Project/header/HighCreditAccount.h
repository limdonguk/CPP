#ifndef __HIGH_CREDIT_ACCOUNT__
#define __HIGH_CREDIT_ACCOUNT__
#include "Account.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int credit;

public:
	HighCreditAccount(int accID, int balance, const char *name, int ratio, int credit)
		: NormalAccount(accID, balance, name, ratio), credit(credit)
	{
	}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money*(credit / 100.0));
	}
};

#endif