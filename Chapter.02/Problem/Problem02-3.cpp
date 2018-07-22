#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point&  PntAdder(const Point &p1, const Point &p2)
{
	Point *s1 = new Point;
	s1->xpos = p1.xpos + p2.xpos;
	s1->ypos = p1.ypos + p2.ypos;

	return *s1;
}

int main() 
{
	Point *p1 = new Point;
	Point *p2 = new Point;

	p1->xpos = 1, p1->ypos = 1;
	p2->xpos = 2, p2->ypos = 2;

	Point &refPnt = PntAdder(*p1, *p2);
	cout << "x = " << refPnt.xpos << endl;
	cout << "y = " << refPnt.ypos << endl;
}