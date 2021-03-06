#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(const char *myname, int myage)
    {
        int len = strlen(myname)+1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor!"<<endl;
    }
    Person& operator=(const Person& ref)
    {
        delete []name;
        len = strlen(ref.name)+1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }
};

int main()
{
    Person man1("LeeDongWoo", 29);
    Person man2("YoonJuYul",22);
    man2=man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}
