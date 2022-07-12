#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;

class  Student : public Identity {
public:
	Student();

	Student(string id, string name, string pwd);

	// 子菜单
	virtual void showSubMenu();

	// 申请预约
	void applyOrder();

	// 查看我的预约
	void showMyOrder();

	// 查看所有预约
	void showAllOrder();

	// 取消预约
	void cancelOrder();

	~Student();

private:
	// 学生类特有的特性:学生编号
	string m_StuId;
};