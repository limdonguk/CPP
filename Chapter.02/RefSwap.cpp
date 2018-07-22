#include <iostream>
using namespace std;

void SwapByRef(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

void increaseNum(int &ref1)
{
    ref1++;
}

void switchNegativePositive(int &ref1)
{
    ref1 = ref1 * -1;
}

void SwapPointer(int *pNum1, int *pNum2)
{
    int &ref1 = *pNum1;
    int &ref2 = *pNum2;
    int temp;

    temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main()
{
    int val1 = 10;
    int val2 = 20;
    SwapByRef(val1, val2);
    cout << "val1 : " << val1 << endl;
    cout << "val2 : " << val2 << endl;

    increaseNum(val1);
    cout << "val1 : " << val1 << endl;

    switchNegativePositive(val2);
    cout << "val2 : " << val2 << endl;


    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    SwapPointer(ptr1, ptr2);
    cout << "num1 : " << *ptr1 << endl;
    cout << "num2 : " << *ptr2 << endl;
    return 0;
}