#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;
enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

class Account
{
  private:
    int accID;
    int balance;
    char *cusName;

  public:
    Account(int accID, int balance, const char *name);
    Account(const Account &copy);
    int GetID() const;
    void Deposit(int money);
    int Withdraw(int money);
    void showAccInfo() const;
    ~Account();
};

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

class AccountHandler
{
  private:
    Account *accArr[100];
    int accNum;

  public:
    AccountHandler();
    void ShowMenu(void);
    void MakeAccout(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    ~AccountHandler();
};

void AccountHandler::ShowMenu(void)
{
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccout(void)
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

void AccountHandler::DepositMoney()
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
            accArr[i]->Deposit(money);
            cout << "입금완료" << endl;
            return;
        }
        else
            cout << "유효하지 않은 ID 입니다." << endl;
    }
}

void AccountHandler::WithdrawMoney(void)
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
            if (accArr[i]->Withdraw(money) == 0)
            {
                cout<<"잔액부족"<<endl;
                return;
            }
            cout<<"출금완료"<<endl;
            return;
        }
    }
    cout<<"유효하지 않는 ID입니다."<<endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->showAccInfo();
    }
}

AccountHandler::AccountHandler() : accNum(0) 
{ }

AccountHandler::~AccountHandler()
{
    for(int i=0; i<accNum; i++){
        delete accArr[i];
    }
}

int main()
{
    AccountHandler manager;
    int choice;

    while (1)
	{
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccout();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}
