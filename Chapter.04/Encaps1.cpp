#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class SinivelCap
{
    public:
        void Take() const { cout<<"콧물이 낫습니다."<<endl; }
};

class SneezeCap
{
    public:
        void Take() const { cout<<"재채기가 멎습니다."<<endl; }
};

class SnuffleCap
{
    public:
        void Take() const { cout<<"코가 뻥 뚫립니다."<<endl; }
};

class ColdPatient
{
    public:
        void TakeSinivelCap(const SinivelCap &cap) const { cap.Take(); };
        void TakeSneezeCap(const SneezeCap &cap) const { cap.Take(); };
        void TakeSnuffleCap(const SnuffleCap &cap) const { cap.Take(); };
};

int main()
{
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;
    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezeCap(zcap);
    sufferer.TakeSnuffleCap(ncap);

    return 0;
}