#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Caculator
{
  private:
    int addCount;
    int minCount;
    int divCount;
    int mulCount;

  public:
    void Init();
    double Add(double num1, double num2);
    double Min(double num1, double num2);
    double Mul(double num1, double num2);
    double Div(double num1, double num2);
    void ShowOpCount();
};

void Caculator::Init() 
{
    addCount=0;
    minCount=0;
    divCount=0;
    mulCount=0;
}

double Caculator::Add(double num1, double num2)
{
    addCount++;
    return num1 + num2;
}

double Caculator::Min(double num1, double num2)
{
    minCount++;
    return num1 - num2;
}

double Caculator::Mul(double num1, double num2)
{
    divCount++;
    return num1 * num2;
}

double Caculator::Div(double num1, double num2)
{
    divCount++;
    return num1 / num2;
}

void Caculator::ShowOpCount()
{
    cout << "덧셈: " << addCount;
    cout << " 뺄셈: " << minCount;
    cout << " 곱셈: " << mulCount;
    cout << " 나눗셈: " << divCount << endl;
}

int main()
{
    Caculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}
