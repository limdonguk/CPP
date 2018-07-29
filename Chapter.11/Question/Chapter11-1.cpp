#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
  private:
    int bullet;

  public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police
{
  private:
    int handcuffs;
    Gun *pistol;

  public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    Police(const Police& ref)
    {
        if(ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol));
        else
            pistol = NULL;
    }
    void PutHandcuff()
    {
        cout << "SNAP" << endl;
        handcuffs--;
    }
    void Shot()
    {
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shot();
    }
    Police& operator=(const Police& ref)
    {
        if(pistol != NULL)
            delete []pistol;
        if(ref.pistol != NULL)
            pistol = new Gun(*(ref.pistol));
        else
            pistol = NULL;
    }
    ~Police()
    {
        if (pistol != NULL)
            delete pistol;
    }
};

int main()
{
    Police pman(5, 3);
    pman.Shot();
    pman.PutHandcuff();

    Police pman2(0, 3);
    pman2.Shot();
    pman2.PutHandcuff();
    return 0;
}