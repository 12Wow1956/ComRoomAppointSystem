#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Identity {
public:
	virtual void showSubMenu() = 0;

	// �û���
	string m_Name;

	// ����
	string m_Pwd;
};