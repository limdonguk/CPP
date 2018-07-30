#include <iostream>
using namespace std;

template <typename T>
void SwapData(T &data1, T &data2)
{
    T temp;
    temp = data1;
    data1 = data2;
    data2 = temp;
}

class Point
{
  private:
    int xpos, ypos;

  public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
    }
    void ShowPosition() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

int main()
{
    Point p1(3, 4);
    Point p2(5, 6);
    p1.ShowPosition();
    p2.ShowPosition();
    SwapData(p1, p2);
    p1.ShowPosition();
    p2.ShowPosition();
    return 0;
}