#pragma once
#include <iostream>
#include "globalFile.h"
#include "Identity.h"
using namespace std;

class Admin : public Identity {
public:
	Admin();

	Admin(string name, string pwd);

	virtual void showSubMenu();

	// 添加账号
	void addAccount();

	// 查看账号
	void showAccount();

	// 查看机房
	void showComputerRoom();

	// 清空预约
	void clearOrder();
	
};