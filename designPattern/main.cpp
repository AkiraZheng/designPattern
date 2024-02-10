#include "header.h"
#include "SingletonPattern.h"
#include "FactoryMethod_SimpleFactory.h"
#include "FactoryMethod.h"
#include "AbstractFactory.h"
#include "ProxyPattern.h"
#include "TemplateMethodPattern.h"
#include "StrategyPattern.h"

/*���ģʽ1������ģʽ*/
//����ģʽ�����ⶨ�壬main��ʼִ��ǰ���ö���ʹ�����
SingletonHungry* SingletonHungry::instance = new SingletonHungry();
void testSingletonHungry()
{
    cout << "origin->getNum() = " << SingletonHungry::getInstance()->getNum() << endl;
    SingletonHungry* p1 = SingletonHungry::getInstance();
    SingletonHungry* p2 = SingletonHungry::getInstance();
    p1->resetNum(20);
    cout << "p1->getNum() = " << p1->getNum() << endl;
    cout << "p2->getNum() = " << p2->getNum() << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
}

//��������1���̲߳���ȫ�ķ���
SingletonLazy1* SingletonLazy1::instance = nullptr;
void testSingletonLazy1()
{
    SingletonLazy1* p1 = SingletonLazy1::getInstance();
    SingletonLazy1* p2 = SingletonLazy1::getInstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
}

//��������2��DCL˫�ؼ�����ʽ-�̰߳�ȫ�ķ���
volatile SingletonLazy2_DCL* SingletonLazy2_DCL::instance = nullptr;
mutex SingletonLazy2_DCL::mtx;// ��̬��Ա������Ҫ�������ʼ��
void testSingletonLazy2_DCL()
{
    volatile SingletonLazy2_DCL* p1 = SingletonLazy2_DCL::getInstance();
    volatile SingletonLazy2_DCL* p2 = SingletonLazy2_DCL::getInstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
}

////��������3������call_once����
//SingletonLazy3_callOnce* SingletonLazy3_callOnce::instance = nullptr;
//void testSingletonLazy3_callOnce()
//{
//    SingletonLazy3_callOnce* p1 = SingletonLazy3_callOnce::getInstance();
//    SingletonLazy3_callOnce* p2 = SingletonLazy3_callOnce::getInstance();
//    cout << "p1 = " << p1 << endl;
//    cout << "p2 = " << p2 << endl;
//}

/*���ģʽ2����������ģʽ*/
//1. �򵥹���
void testFactory_simpleFactory() {
    unique_ptr<FactoryMethod_SimpleFactory::PhoneFactory> factory(new FactoryMethod_SimpleFactory::PhoneFactory());
    unique_ptr<FactoryMethod_SimpleFactory::Phone> p1(factory->createPhone(FactoryMethod_SimpleFactory::PhoneFactory::IPHONE));
    unique_ptr<FactoryMethod_SimpleFactory::Phone> p2(factory->createPhone(FactoryMethod_SimpleFactory::PhoneFactory::HUAWEI));
    p1->show();
    p2->show();
}
//2. ��������
void testFactory_factoryMethod() {
    unique_ptr<FactoryMethod::PhoneFactory> iPhoneFactory(new FactoryMethod::IphoneFactory());
    unique_ptr<FactoryMethod::PhoneFactory> huaweiFactory(new FactoryMethod::HuaWeiFactory());
    unique_ptr<FactoryMethod::Phone> iphone(iPhoneFactory->createPhone("iphone"));//ͨ��������Iphone����������Ӧ��Ʒ
    unique_ptr<FactoryMethod::Phone> huawei(huaweiFactory->createPhone("huawei"));//ͨ��������HuaWei����������Ӧ��Ʒ
    iphone->show();
    huawei->show();
}

/*���ģʽ3�����󹤳�ģʽ*/
void testAbstractFactory() {
    unique_ptr<AbstractFactor::AbstractFactory> iphoneFactory(new AbstractFactor::PhoneFactory_Iphone());
    unique_ptr<AbstractFactor::AbstractFactory> huaweiFactory(new AbstractFactor::PhoneFactory_Huawei());
    unique_ptr<AbstractFactor::Phone> iphone(iphoneFactory->createPhone());//ͨ��������Iphone���������ֻ���Ʒ
    unique_ptr<AbstractFactor::PhoneShell> iphoneShell(iphoneFactory->createPhoneShell());//ͨ��������Iphone���������ֻ��ǲ�Ʒ
    unique_ptr<AbstractFactor::Phone> huawei(huaweiFactory->createPhone());//ͨ��������HuaWei���������ֻ���Ʒ
    unique_ptr<AbstractFactor::PhoneShell> huaweiShell(huaweiFactory->createPhoneShell());//ͨ��������HuaWei���������ֻ��ǲ�Ʒ
    iphone->show();
    iphoneShell->display();
    huawei->show();
    huaweiShell->display();
}

/*���ģʽ4������ģʽ*/
void testProxyModel() {
    Isubject* iSubject = new ProxySubject();//ʹ�ô���ʽ
    iSubject->process();
}

/*���ģʽ5��ģ�巽��ģʽ*/
void testTemplateMethodPattern() {
    Library* plib = new Application();
    plib->run();
    delete plib;
}

/*���ģʽ6������ģʽ*/
void testStrategyPattern() {
    SalesOrder* order = new SalesOrder(new CNTax());//new CNTax()�������ͨ������ģʽ����������
    cout << order->CalculateTax() << endl;
    delete order;
}

int main() {
    /*
    * ��ȡ�������汾
    */
    //int num = _MSC_VER; // get the version
    //cout << "My MSVC version is: " << num << endl;

	/*
	* ���ģʽ1������ģʽ
	*/
    //testSingletonHungry(); 
    //testSingletonLazy1();
    //testSingletonLazy2_DCL();
    //testFactory_simpleFactory();
    //testFactory_factoryMethod();
    //testAbstractFactory();
    //testProxyModel();
    //testTemplateMethodPattern();
    testStrategyPattern();

    return 0;
}
