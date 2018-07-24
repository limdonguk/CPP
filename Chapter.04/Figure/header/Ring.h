#ifndef __CIRCLE_H_
#define __CIRCLE_H_

class Circle
{
    private:
        int x;
        int y;
        int radius;
    public:
        Circle(int xpos, int ypos, int rdus) 
            : x(xpos), y(ypos), radius(rdus) {}
        void InitMembers(int xpos, int ypos, int rdus);
        int GetX() const;
        int GetY() const;
        int GetRadius() const;
};

class Ring
{
    private:
        Circle c1;
        Circle c2;
    public:
        Ring(int x1, int y1, int rdus1, int x2, int y2, int rdus2) 
            : c1(x1,y1,rdus1), c2(x2,y2,rdus2) {} 
        void Init(int x1, int y1, int rdus1, int x2, int y2, int rdus2);
        void ShowRingInfo() const;
};

#endif