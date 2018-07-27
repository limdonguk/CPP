#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
    friend Point operator-(const Point &pos1, const Point &pos2);
    friend bool operator==(const Point &pos1, const Point &pos2);
    friend bool operator!=(const Point &pos1, const Point &pos2);
    Point& operator+=(const Point &pos)
    {
        Point pos(xpos += pos.xpos, ypos += pos.ypos);
        return *this;
    }
    Point& operator-=(const Point &pos)
    {
        Point pos(xpos -= pos.xpos, ypos -= pos.ypos);
        return *this;
    }
};

Point operator-(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
    return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
    if(pos1.xpos == pos2.xpos && pos2.ypos == pos2.ypos)
        return true;
    else
        return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    if(pos1.xpos != pos2.xpos && pos2.ypos != pos2.ypos)
        return true;
    else
        return false;
}


int main()
{
    Point pos1(3,4);
    Point pos2(10,20);
    Point pos3 = pos1-pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    return 0;
}