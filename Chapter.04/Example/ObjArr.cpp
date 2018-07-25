#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char *name;
	int age;
public:
	Person(char *myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char *myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor" << endl;
	}
};

int main()
{
	Person *parr[3];    // 포인터 배열 선언
	char namestr[100];
	int age;

	for (int i = 0; i<3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;
		parr[i] = new Person(namestr, age); // 객체생성, 주소 값을 배열에 저장
	}
	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	return 0;
}