#pragma once
#include "header.h"
namespace FactoryMethod_SimpleFactory {
    /*产品类的设计*/
    class Phone {
        // 产品基类
    public:
        Phone(string name) :_phone_name(name) {};
        virtual void show() = 0;
    protected:
        string _phone_name;
    };
    class Iphone :public Phone {
        // 产品派生类
    public:
        Iphone(string name) :Phone(name) {};
        void show() {
            cout << "I have a phone named: " << _phone_name << endl;
        }
    };
    class HuaWei :public Phone {
        // 产品派生类
    public:
        HuaWei(string name) :Phone(name) {};
        void show() {
            cout << "I have a phone named: " << _phone_name << endl;
        }
    };

    /*工厂类的设计*/
    class PhoneFactory {
        // 工厂类
    public:
        enum phone_type {
            IPHONE,
            HUAWEI
        };
        Phone* createPhone(int type) {
            switch (type)
            {
            case IPHONE:
                return new Iphone("iphone");
            case HUAWEI:
                return new HuaWei("huawei");
            default:
                return nullptr;
            }
        }
    };
}

