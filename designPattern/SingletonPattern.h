#pragma once
#include "header.h"

/*饿汉模式*/
class SingletonHungry
{
private:
    SingletonHungry() {};              // 构造函数私有化
    static SingletonHungry* instance; // 静态成员变量

    // 禁止拷贝构造和赋值操作
    SingletonHungry(const SingletonHungry&) = delete;
    SingletonHungry& operator=(const SingletonHungry&) = delete;

    // 测试用
    int test_num = 10;

public:
    static SingletonHungry* getInstance()
    {
        return instance;
    }

    // 测试用
    void resetNum(int num)
    {
        test_num = num;
    }

    int getNum()
    {
        return test_num;
    }
};

/*懒汉式方法1：线程不安全的方式*/
class SingletonLazy1
{
private:
    SingletonLazy1() {};              // 构造函数私有化
    static SingletonLazy1* instance; // 在类加载时不创建对象实例

    // 禁止拷贝构造和赋值操作
    SingletonLazy1(const SingletonLazy1&) = delete;
    SingletonLazy1& operator=(const SingletonLazy1&) = delete;

public:
    static SingletonLazy1* getInstance()
    {
        if (instance == NULL)
            instance = new SingletonLazy1(); // 第一次调用时创建对象实例
        return instance;
    }
};

/*懒汉方法2：线程安全的方式*/
class SingletonLazy2_DCL
{
private:
    SingletonLazy2_DCL() {};                       // 构造函数私有化
    volatile static SingletonLazy2_DCL* instance; // 必须用volatile修饰
    static mutex mtx;
public:
    volatile static SingletonLazy2_DCL* getInstance() // 需要进行同步加锁，保证线程安全
    {
        if (instance == nullptr)
        {                                          // 第一次检查
            mtx.lock(); // 加锁
            if (instance == nullptr)
            {                              // 第二次检查,防止多个线程同时进入临界区
                instance = new SingletonLazy2_DCL(); // 创建实例
            }
            mtx.unlock(); // 解锁
        }
        return instance;
    }
};

///*懒汉方法3：C++11中的call_once*/
//class SingletonLazy3_callOnce {
//private:
//    static SingletonLazy3_callOnce* instance;
//    static std::once_flag onceFlag;
//
//    // 私有化构造函数
//    SingletonLazy3_callOnce() {}
//
//    // 禁止拷贝构造和赋值操作
//    SingletonLazy3_callOnce(const SingletonLazy3_callOnce&) = delete;
//    SingletonLazy3_callOnce& operator=(const SingletonLazy3_callOnce&) = delete;
//
//public:
//    // 获取单例对象的函数
//    static SingletonLazy3_callOnce* getInstance() {
//        std::call_once(onceFlag, []() {
//            instance = new SingletonLazy3_callOnce();
//        });
//        return instance;
//    }
//};