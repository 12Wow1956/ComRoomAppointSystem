#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;

class  Teacher : public Identity {
public:
	 Teacher();

	 Teacher(string id, string name, string pwd);

	 virtual void showSubMenu();

	 // �鿴����ԤԼ
	 void showAllOrder();

	 // ���ԤԼ
	 void checkOrder();

	~ Teacher();

private:
	string m_EmpId;
};
