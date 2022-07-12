#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;

class  Teacher : public Identity {
public:
	 Teacher();

	 Teacher(string id, string name, string pwd);

	 virtual void showSubMenu();

	 // 查看所有预约
	 void showAllOrder();

	 // 审核预约
	 void checkOrder();

	~ Teacher();

private:
	string m_EmpId;
};
