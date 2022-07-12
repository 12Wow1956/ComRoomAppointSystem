#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;

class  Student : public Identity {
public:
	Student();

	Student(string id, string name, string pwd);

	// �Ӳ˵�
	virtual void showSubMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴�ҵ�ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();

	~Student();

private:
	// ѧ�������е�����:ѧ�����
	string m_StuId;
};