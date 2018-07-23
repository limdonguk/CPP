#include <iostream>
#include "FruitSale.h"
using std::cin;
using std::cout;
using std::endl;

void FruitSeller::InitMembers(int price, int num, int money)
{
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
}

int FruitSeller::GetMyMoney() const
{
    return myMoney;
}

int FruitSeller::GetNumApples() const
{
    return numOfApples;
}

int FruitSeller::SaleApples(int money)
{
    int num = money / APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
}

void FruitSeller::ShowSalesResult() const
{
    cout << "남은 사과 : " << GetNumApples() << endl;
    cout << "판매 수익 : " << GetMyMoney() << endl << endl;
}


//--------------------------------------------------------//


void FruitBuyer::InitMembers(int price)
{
    myMoney = price;
    numOfApples = 0;
}

int FruitBuyer::GetMyMoney() const
{
    return myMoney;
}

int FruitBuyer::GetNumApples() const
{
    return numOfApples;
}

bool checkMoney(int money)
{
    if(money < 1000)
        return false;
    else 
        return true;
}

void FruitBuyer::BuyApples(FruitSeller &seller, int money)
{
    if(checkMoney(money))
    {
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
}


void FruitBuyer::ShowBuyResult() const
{
    cout << "현재 잔액 : " << GetMyMoney() << endl;
    cout << "사과 개수 : " << GetNumApples() << endl << endl;
}

int main()
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}