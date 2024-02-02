#pragma once
#include "header.h"
namespace FactoryMethod {
	/*��Ʒ�����ƣ��������*/
	class Phone {
		// ��Ʒ����
	public:
		Phone(string name) :_phone_name(name) {};
		virtual void show() = 0;
		virtual ~Phone() {}; //����Ӧ�ñ�����Ϊ����������
	protected:
		string _phone_name;
	};
	class Iphone :public Phone {
		// ��Ʒ������
	public:
		Iphone(string name) :Phone(name) {};
		void show() {
			cout << "I have a phone named: " << _phone_name << endl;
		}
	};
	class HuaWei :public Phone {
		// ��Ʒ������
	public:
		HuaWei(string name) :Phone(name) {};
		void show() {
			cout << "I have a phone named: " << _phone_name << endl;
		}
	};

	/*���������ƣ��������*/
	class PhoneFactory {
		// ������
	public:
		virtual Phone* createPhone(string name) = 0;
		virtual ~PhoneFactory() {}; //����Ӧ�ñ�����Ϊ����������
	};
	class IphoneFactory :public PhoneFactory {
		// ����������
	public:
		Phone* createPhone(string name) {
			return new Iphone(name);
		}
	};
	class HuaWeiFactory :public PhoneFactory {
		// ����������
	public:
		Phone* createPhone(string name) {
			return new HuaWei(name);
		}
	};
}

