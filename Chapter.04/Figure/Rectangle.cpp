#include <iostream>
#include "Rectangle.h"
using std::cin;
using std::cout;
using std::endl;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
:upLeft(x1, y1), lowRight(x2, y2)
{
    //
}

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
    if(ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
    {
        cout<<"잘못된 위치정보 전달"<<endl;
        return false;
    }
    upLeft = ul;
    lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout<<"좌 상단 : "<<'['<<upLeft.GetX()<<", ";
    cout<<upLeft.GetY()<<']'<<endl;
    cout<<"우 하단 : "<<'['<<lowRight.GetX()<<", ";
    cout<<lowRight.GetY()<<']'<<endl;
}