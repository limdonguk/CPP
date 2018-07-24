#include <iostream>
#include "Ring.h"
using std::cin;
using std::cout;
using std::endl;

void Circle::InitMembers(int xpos, int ypos, int rdus)
{
    x = xpos;
    y = ypos;
    radius = rdus;
}

int Circle::GetX() const { return x; }
int Circle::GetY() const { return y; }
int Circle::GetRadius() const { return radius; }

void Ring::Init(int x1, int y1, int rdus1, int x2, int y2, int rdus2)
{
    c1.InitMembers(x1,y1,rdus1);
    c2.InitMembers(x2,y2,rdus2);
}

void Ring::ShowRingInfo() const
{
    cout<<"Inner Circle Info..."<<endl;
    cout<<"radius: "<<c1.GetRadius()<<endl;
    cout<<"["<<c1.GetX()<<", "<<c1.GetY()<<"]"<<endl;

    cout<<"Outer Circle Info..."<<endl;
    cout<<"radius: "<<c2.GetRadius()<<endl;
    cout<<"["<<c2.GetX()<<", "<<c2.GetY()<<"]"<<endl;
}