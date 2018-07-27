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
    Point operator*(int items)
    {
        Point pos(xpos*items, ypos*items);
        return pos;
    }
    friend Point operator*(int items, Point& ref);
};

Point operator*(int items, Point& ref)
{
    return ref*items;
}

int main()
{
    Point pos(1,2);
    Point cpy;

    cpy=pos*3;
    cpy.ShowPosition();

    cpy=2*pos*3;
    cpy.ShowPosition();
    return 0;
}