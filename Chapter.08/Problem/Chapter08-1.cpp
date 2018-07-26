#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
  enum
  {
    RISK_A  =30,
    RISK_B  =20,
    RISK_C  =10
  };
}

class Employee
{
  private:
    char name[100];

  public:
    Employee(const char *name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const = 0;
    virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
  private:
    int salary;

  public:
    PermanentWorker(const char *name, int money)
        : Employee(name), salary(money)
    {
    }
    virtual int GetPay() const
    {
        return salary;
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
};

class TemporaryWorker : public Employee
{
  private:
    int workTime;
    int payPerHour;

  public:
    TemporaryWorker(const char *name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    {
    }
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    virtual int GetPay() const
    {
        return workTime * payPerHour;
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
};

class SalesWorker : public PermanentWorker
{
  private:
    int salesResult;
    double bonusRatio;

  public:
    SalesWorker(const char *name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    {
    }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    virtual int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
};

class ForeignSalesWorker : public SalesWorker
{
  private:
    const int riskType;

  public:
    ForeignSalesWorker(const char *name, int money, double ratio, const int risk)
        : SalesWorker(name, money, ratio), riskType(risk)
    { }
    
    int GetRiskPay() const
    {
        return (int)(SalesWorker::GetPay() * (riskType/100.0));
    }
    virtual int GetPay() const
    {
        return SalesWorker::GetPay() + GetRiskPay();
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout<<"salary: "<<SalesWorker::GetPay()<<endl;
        cout<<"risk pay: "<<GetRiskPay()<<endl;
        cout<<"sum: "<<GetPay()<<endl;
    } 
};

class EmployeeHandler
{
  private:
    Employee *empList[50];
    int empNum;

  public:
    EmployeeHandler() : empNum(0)
    {
    }
    void AddEmployee(Employee *emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    // 직원관리 컨트롤 클래스 객체 생성
    EmployeeHandler handler;

    ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();
    return 0;
}