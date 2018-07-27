#ifndef __ACOUNT_HANDLER_H__
#define __ACOUNT_HANDLER_H__
#include "Account.h"

class AccountHandler
{
  private:
    Account *accArr[100];
    int accNum;

  public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    void ChoiceAccount(void);
    ~AccountHandler();

  protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
};

#endif