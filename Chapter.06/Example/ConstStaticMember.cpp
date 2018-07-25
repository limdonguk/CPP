#include <iostream>
using namespace std;

class CountryArea
{
public: 
    const static int RUSSIA      =1;
    const static int CANADA      =2;
    const static int CHINA       =3;
    const static int SOUTH_KOREA =4;
};

int main()
{
    cout<<"러시아: "<<CountryArea::RUSSIA<<endl;
    cout<<"캐나다: "<<CountryArea::CANADA<<endl;
    cout<<"중국: "<<CountryArea::CHINA<<endl;
    cout<<"한국: "<<CountryArea::SOUTH_KOREA<<endl;
    return 0;
}