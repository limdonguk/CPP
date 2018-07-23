#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Point
{
    int xpos;
    int ypos;

    void MovePos(int x, int y)
    {
        xpos = xpos + x;
        ypos = ypos + y;
    }
    void AddPoint(const Point &pos)
    {
        xpos = xpos + pos.xpos;
        ypos = ypos + pos.ypos;
    }
    void ShowPosition()
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

int main()
{
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();

    pos1.AddPoint(pos2);
    pos1.ShowPosition();

    return 0;
}
