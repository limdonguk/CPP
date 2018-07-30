#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

class String
{
  private:
	char *string;
	int len;

  public:
	String()
	{
		len = 0;
		string = NULL;
	}
	String(const char *str)
	{
		len = strlen(str) + 1;
		string = new char[len];
		strcpy(string, str);
	}
	String(const String &ref)
	{
		len = ref.len;
		string = new char[len];
		strcpy(string, ref.string);
	}
	String &operator=(const String &ref)
	{
		if (string != NULL)
			delete[] string;
		len = ref.len;
		string = new char[len];
		strcpy(string, ref.string);
		return *this;
	}
	String operator+(const String &ref)
	{
		char *tempstr = new char[len + ref.len - 1];
		strcpy(tempstr, string);
		strcat(tempstr, ref.string);

		String temp(tempstr);
		delete[] tempstr;
		return temp;
	}
	String &operator+=(const String &ref)
	{
		len += (ref.len - 1);
		char *tempstr = new char[len];
		strcpy(tempstr, string);
		strcat(tempstr, ref.string);

		if (string != NULL)
			delete[] string;
		string = tempstr;
		return *this;
	}
	bool operator==(const String &ref)
	{
		return strcmp(string, ref.string) ? false : true;
	}
	friend ostream &operator<<(ostream &os, const String &ref)
	{
		os << ref.string;
		return os;
	}
	friend istream &operator>>(istream &is, String &ref)
	{
		char string[100];
		is >> string;
		ref = String(string);
		return is;
	}
	~String()
	{
		delete[] string;
	}
};
int main()
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}