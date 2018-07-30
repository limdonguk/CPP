#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len)
{
    T sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}

int main()
{
    int intArr[5] = {1.5, 2, 3, 4, 5};
    int len = 5;
    cout << SumArray(intArr, len) << endl;

    double dobArr[5] = {1.5, 2.0, 3.0, 4.0, 5.0};
    cout << SumArray(dobArr, len) << endl;
    return 0;
}