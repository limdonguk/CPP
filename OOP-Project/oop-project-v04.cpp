// const 키워드로 안정성 강화

#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccout(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

class Account
{
private:
	int accID;
	int balance;
	char *cusName;

public:
	Account(int accID, int balance, const char *name)
		: accID(accID), balance(balance)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

    Account(const Account &copy)
        : accID(copy.accID), balance(copy.balance)
    {
        int len = strlen(copy.cusName)+1;
        cusName = new char[len];
        strcpy(cusName, copy.cusName);
    }
    
	int GetID() const { return accID; }

	int Deposit(int money)
	{
		if (money <= 0)
			return 0;
		else
		{
			balance += money;
			return 1;
		}
	}

	int Withdraw(int money)
	{
		if (money <= 0)
			return 0;
		if (money > balance)
			return 2;
		else
		{
			balance -= money;
			return 1;
		}
	}

	void showAccInfo() const
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이 름: " << cusName << endl;
		cout << "잔 액: " << balance << endl
			<< endl;
	}

	~Account()
	{
		delete[] cusName;
	}
};

enum
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT
};

Account *accArr[100];
int accNum = 0;

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccout();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccout(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
	cout << endl;

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void DepositMoney()
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			if (accArr[i]->Deposit(money) == 1)
				cout << "입금완료" << endl;
			else
				cout << "입금실패, 입력값을 확인해주세요." << endl;
		}
		else
			cout << "유효하지 않은 ID 입니다." << endl
			<< endl;
	}
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[ 출 금 ]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			if (accArr[i]->Withdraw(money) == 1)
				cout << "출금완료" << endl
				<< endl;
			else if (accArr[i]->Withdraw(money) == 2)
				cout << "출금실패, 잔액이 부족합니다." << endl
				<< endl;
			else
				cout << "출금실패, 입력값을 확인해주세요." << endl << endl;
		}
		else
			cout << "유효하지 않은 ID 입니다." << endl
			<< endl;
	}
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->showAccInfo();
	}
}