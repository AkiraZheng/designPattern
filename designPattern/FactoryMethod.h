#pragma once
#include "header.h"
namespace FactoryMethod {
	/*产品类的设计：抽象基类*/
	class Phone {
		// 产品基类
	public:
		Phone(string name) :_phone_name(name) {};
		virtual void show() = 0;
		virtual ~Phone() {}; //基类应该被声明为虚析构函数
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

	/*工厂类的设计：抽象基类*/
	class PhoneFactory {
		// 工厂类
	public:
		virtual Phone* createPhone(string name) = 0;
		virtual ~PhoneFactory() {}; //基类应该被声明为虚析构函数
	};
	class IphoneFactory :public PhoneFactory {
		// 工厂派生类
	public:
		Phone* createPhone(string name) {
			return new Iphone(name);
		}
	};
	class HuaWeiFactory :public PhoneFactory {
		// 工厂派生类
	public:
		Phone* createPhone(string name) {
			return new HuaWei(name);
		}
	};
}

