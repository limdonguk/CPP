#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name;
    int age;
public:
    Person(const char *myname, int myage)
    {
        int len = strlen(myname)+1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person(const Person &ptr) 
        : age(ptr.age)
    {
        int len = strlen(ptr.name)+1;
        name = new char[len];
        strcpy(name, ptr.name);
    }
    void ShowPersonInfo() const
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor"<<endl;
    }
};

int main()
{
    Person man1("Lee Dong Woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}