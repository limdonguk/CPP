#include <iostream>
#include <string.h>
using namespace std;

char *makeStrAdr(int len)
{
    char *str = new char[len];
    return str;
}

int main()
{
    char *str = makeStrAdr(20);
    strcpy_s(str, 20, "I am so happy");
    cout << str << endl;
    delete[] str;
    return 0;
}