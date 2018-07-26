#include <iostream>
using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int gasoline) : gasolineGauge(gasoline)
    {
        cout<<"Car(int gasoline)"<<endl;
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int gasoline, int electric)
        : Car(gasoline), electricGauge(electric)
    {
        cout<<"HybridCar(int gasoline, int electric)"<<endl;
    }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int gasoline, int electric, int water)
        : HybridCar(gasoline, electric), waterGauge(water)
    {
        cout<<"HybridWaterCar(int gasoline, int electric, int water)"<<endl;
    }
    void ShowCurrentGauge()
    {
        cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
        cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
        cout<<"잔여 워터량: "<<waterGauge<<endl;
    }
};

int main()
{
    HybridWaterCar car1(10,10,10);
    car1.ShowCurrentGauge();
}