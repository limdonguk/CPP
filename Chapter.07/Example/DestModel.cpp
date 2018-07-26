#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name;
public:
    Person(const char* myname)
    {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    ~Person()
    {
        delete []name;
    }
    void WhatYourName() const
    {
        cout<<"My name is "<<name<<endl;
    }
};

class UnivStudent : public Person
{
private:
    char* major;
public:
    UnivStudent(const char* myname, const char* mymajor)
        : Person(myname)
    {
        major = new char[strlen(mymajor)+1];
        strcpy(major, mymajor);
    }
    ~UnivStudent()
    {
        delete []major;
    }
    void WhoAreYou() const
    {
        WhatYourName();
        cout<<"My name is "<<major<<endl<<endl;
    }
};

int main()
{
    UnivStudent std1("Kim","Mathematics");
    std1.WhoAreYou();
    UnivStudent std2("Hong","Physics");
    std2.WhoAreYou();
    return 0;
}