#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

 #include "Point.h"

 class Rectangle
 {
    private:
        Point upLeft;
        Point lowRight;
    public:
        Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
            : upLeft(x1,y1), lowRight(x2, y2) {}
        bool InitMembers(const Point &ul, const Point &lr);
        void ShowRecInfo() const;
 };

 #endif;