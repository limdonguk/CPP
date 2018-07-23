#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

namespace PRINTER_CONST
{
    enum
    {
        MAX_LENGTH = 50
    };
}

class Printer
{
  private:
    char printer_str[PRINTER_CONST::MAX_LENGTH];

  public:
    void SetString(const char *str);
    void ShowString();
};

void Printer::SetString(const char *str)
{
    strcpy_s(printer_str, str);
}

void Printer::ShowString()
{
    cout << printer_str << endl;
}

int main()
{
    Printer pnt;
    pnt.SetString("Hello World");
    pnt.ShowString();

    pnt.SetString("I love c++");
    pnt.ShowString();

    return 0;
}
