#include "header.h"
#include "SingletonPattern.h"
#include "FactoryMethod_SimpleFactory.h"
#include "FactoryMethod.h"
#include "AbstractFactory.h"
#include "ProxyPattern.h"
#include "TemplateMethodPattern.h"
#include "StrategyPattern.h"

/*设计模式1：单例模式*/
//饿汉模式，类外定义，main开始执行前，该对象就存在了
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

//懒汉方法1：线程不安全的方法
SingletonLazy1* SingletonLazy1::instance = nullptr;
void testSingletonLazy1()
{
    SingletonLazy1* p1 = SingletonLazy1::getInstance();
    SingletonLazy1* p2 = SingletonLazy1::getInstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
}

//懒汉方法2：DCL双重加锁方式-线程安全的方法
volatile SingletonLazy2_DCL* SingletonLazy2_DCL::instance = nullptr;
mutex SingletonLazy2_DCL::mtx;// 静态成员变量需要在类外初始化
void testSingletonLazy2_DCL()
{
    volatile SingletonLazy2_DCL* p1 = SingletonLazy2_DCL::getInstance();
    volatile SingletonLazy2_DCL* p2 = SingletonLazy2_DCL::getInstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
}

////懒汉方法3：采用call_once方法
//SingletonLazy3_callOnce* SingletonLazy3_callOnce::instance = nullptr;
//void testSingletonLazy3_callOnce()
//{
//    SingletonLazy3_callOnce* p1 = SingletonLazy3_callOnce::getInstance();
//    SingletonLazy3_callOnce* p2 = SingletonLazy3_callOnce::getInstance();
//    cout << "p1 = " << p1 << endl;
//    cout << "p2 = " << p2 << endl;
//}

/*设计模式2：工厂方法模式*/
//1. 简单工厂
void testFactory_simpleFactory() {
    unique_ptr<FactoryMethod_SimpleFactory::PhoneFactory> factory(new FactoryMethod_SimpleFactory::PhoneFactory());
    unique_ptr<FactoryMethod_SimpleFactory::Phone> p1(factory->createPhone(FactoryMethod_SimpleFactory::PhoneFactory::IPHONE));
    unique_ptr<FactoryMethod_SimpleFactory::Phone> p2(factory->createPhone(FactoryMethod_SimpleFactory::PhoneFactory::HUAWEI));
    p1->show();
    p2->show();
}
//2. 工厂方法
void testFactory_factoryMethod() {
    unique_ptr<FactoryMethod::PhoneFactory> iPhoneFactory(new FactoryMethod::IphoneFactory());
    unique_ptr<FactoryMethod::PhoneFactory> huaweiFactory(new FactoryMethod::HuaWeiFactory());
    unique_ptr<FactoryMethod::Phone> iphone(iPhoneFactory->createPhone("iphone"));//通过单独的Iphone工厂创建对应产品
    unique_ptr<FactoryMethod::Phone> huawei(huaweiFactory->createPhone("huawei"));//通过单独的HuaWei工厂创建对应产品
    iphone->show();
    huawei->show();
}

/*设计模式3：抽象工厂模式*/
void testAbstractFactory() {
    unique_ptr<AbstractFactor::AbstractFactory> iphoneFactory(new AbstractFactor::PhoneFactory_Iphone());
    unique_ptr<AbstractFactor::AbstractFactory> huaweiFactory(new AbstractFactor::PhoneFactory_Huawei());
    unique_ptr<AbstractFactor::Phone> iphone(iphoneFactory->createPhone());//通过单独的Iphone工厂创建手机产品
    unique_ptr<AbstractFactor::PhoneShell> iphoneShell(iphoneFactory->createPhoneShell());//通过单独的Iphone工厂创建手机壳产品
    unique_ptr<AbstractFactor::Phone> huawei(huaweiFactory->createPhone());//通过单独的HuaWei工厂创建手机产品
    unique_ptr<AbstractFactor::PhoneShell> huaweiShell(huaweiFactory->createPhoneShell());//通过单独的HuaWei工厂创建手机壳产品
    iphone->show();
    iphoneShell->display();
    huawei->show();
    huaweiShell->display();
}

/*设计模式4：代理模式*/
void testProxyModel() {
    Isubject* iSubject = new ProxySubject();//使用代理方式
    iSubject->process();
}

/*设计模式5：模板方法模式*/
void testTemplateMethodPattern() {
    Library* plib = new Application();
    plib->run();
    delete plib;
}

/*设计模式6：策略模式*/
void testStrategyPattern() {
    SalesOrder* order = new SalesOrder(new CNTax());//new CNTax()这里可以通过工厂模式将其抽象出来
    cout << order->CalculateTax() << endl;
    delete order;
}

int main() {
    /*
    * 获取编译器版本
    */
    //int num = _MSC_VER; // get the version
    //cout << "My MSVC version is: " << num << endl;

	/*
	* 设计模式1：单例模式
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
