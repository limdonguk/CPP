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
    Point& operator++()
    {
        xpos+=1;
        ypos+=1;
        return *this;
    }

    // 값 자체가 바뀜
    // Point& operator-()
    // {
    //     xpos = -xpos;
    //     ypos = -ypos;
    //     return *this;
    // }
    
    // 새로운 객체를 생성하여 바뀐 값만 출력한다.
    Point& operator-()
    {
        Point pos(-xpos, -ypos);
        return pos;
    }
    friend Point& operator--(Point &ref);
    friend Point& operator~(Point &ref);

};

Point& operator--(Point &ref)
{
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

// 값 자체가 변경됨
// Point& operator~(Point &ref)
// {
//     int temp;
//     temp = ref.xpos;
//     ref.xpos = ref.ypos;
//     ref.ypos = temp;
//     return ref;
// }

Point& operator~(Point &ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

int main()
{
    Point pos(1,2);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();

    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();

    -pos;
    pos.ShowPosition();

    ~pos;
    pos.ShowPosition();
    return 0;
}