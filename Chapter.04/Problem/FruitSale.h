#ifndef __FRUIT_SALE_
#define __FRUIT_SALE_

class FruitSeller
{
  private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

  public:
    void InitMembers(int price, int num, int money);
    int GetMyMoney() const;
    int GetNumApples() const;
    int SaleApples(int money);
    void ShowSalesResult() const;
};

class FruitBuyer
{
  private:
    int myMoney;
    int numOfApples;

  public:
    void InitMembers(int price);
    int GetMyMoney() const;
    int GetNumApples() const;
    bool CheckMoney(int money);
    void BuyApples(FruitSeller &seller, int money);
    void ShowBuyResult() const;
};

#endif