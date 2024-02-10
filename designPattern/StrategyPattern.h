#pragma once
#include "header.h"

/*������Ⱥ*/
class TaxStrategy
{
public:
    virtual double Calculate() = 0;//��˰�ʼ����㷨����Ϊһ���麯��
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

/*˰�ʽӿ���--����Ӧ�ó������*/
class SalesOrder
{
private:
    TaxStrategy* strategy;//�ṩһ������Ĳ�����Ķ�ָ̬��
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

