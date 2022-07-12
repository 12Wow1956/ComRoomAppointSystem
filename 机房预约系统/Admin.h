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

	// ����˺�
	void addAccount();

	// �鿴�˺�
	void showAccount();

	// �鿴����
	void showComputerRoom();

	// ���ԤԼ
	void clearOrder();
	
};