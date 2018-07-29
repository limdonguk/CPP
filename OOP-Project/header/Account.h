#ifndef __ACOUNT_H__
#define __ACOUNT_H__

class Account
{
private:
	int accID;
	int balance;
	char *cusName;

public:
	Account(int accID, int balance, const char *name);
	Account(const Account &copy);
	Account& operator=(const Account& ref);
	int GetID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void showAccInfo() const;
	~Account();
};

#endif