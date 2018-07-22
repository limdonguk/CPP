#include <iostream>
using namespace std;

int main()
{
    const int num = 12;
    const int *pNum = &num;
    const int &refNum = *pNum;

    cout << num << endl;
    cout << pNum << endl;
    cout << refNum << endl;

    return 0;
}