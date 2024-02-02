#include "header.h"
#include "SingletonPattern.h"

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

int main() {
	/*
	* 设计模式1：单例模式
	*/
    //testSingletonHungry();
    //testSingletonLazy1();
    //testSingletonLazy2_DCL();

    return 0;
}