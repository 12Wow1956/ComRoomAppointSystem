#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Identity {
public:
	virtual void showSubMenu() = 0;

	// ÓÃ»§Ãû
	string m_Name;

	// ÃÜÂë
	string m_Pwd;
};