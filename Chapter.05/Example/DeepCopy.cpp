#pragma warning(disable: 4996)

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
		}
	}
}

class NameCard
{
private:
	char* myName;
	char* compName;
	char* phNum;
	int compPos;
public:
	NameCard(const char* _name, const char* _company, const char* _phone, int pos)
		: compPos(pos)
	{
		myName = new char[strlen(_name) + 1];
		compName = new char[strlen(_company) + 1];
		phNum = new char[strlen(_phone) + 1];
		strcpy(myName, _name);
		strcpy(compName, _company);
		strcpy(phNum, _phone);
	}
	NameCard(const NameCard &copy)
		: compPos(copy.compPos)
	{
		myName = new char[strlen(copy.myName) + 1];
		compName = new char[strlen(copy.compName) + 1];
		phNum = new char[strlen(copy.phNum) + 1];
		strcpy(myName, copy.myName);
		strcpy(compName, copy.compName);
		strcpy(phNum, copy.phNum);
	}
	void ShowNameCardInfo()
	{
		cout << "이름:" << ' ' << myName << endl;
		cout << "회사:" << ' ' << compName << endl;
		cout << "전화번호:" << ' ' << phNum << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(compPos);
		cout << endl;
	}
	~NameCard()
	{
		delete[]myName;
		delete[]compName;
		delete[]phNum;
	}
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}