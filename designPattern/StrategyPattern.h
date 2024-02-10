#pragma once
#include "header.h"

/*策略类群*/
class TaxStrategy
{
public:
    virtual double Calculate() = 0;//将税率计算算法抽象为一个虚函数
    virtual ~TaxStrategy() {};
};
class CNTax : public TaxStrategy
{
public:
    double Calculate()
    {
        cout << "CNTax::Calculate()" << endl;
        return 0.1;
    }
};
class USTax : public TaxStrategy
{
public:
    double Calculate()
    {
        cout << "USTax::Calculate()" << endl;
        return 0.2;
    }
};
class JPTax : public TaxStrategy
{
public:
    double Calculate()
    {
        cout << "JPTax::Calculate()" << endl;
        return 0.3;
    }
};

/*税率接口类--供给应用程序调用*/
class SalesOrder
{
private:
    TaxStrategy* strategy;//提供一个抽象的策略类的多态指针
public:
    SalesOrder(TaxStrategy* strategy)
    {
        this->strategy = strategy;
    }
    double CalculateTax()
    {
        return strategy->Calculate();
    }
    ~SalesOrder()
    {
        delete strategy;
    }
};

