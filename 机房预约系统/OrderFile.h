#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "globalFile.h"
using namespace std;

class OrderFile {
public:
	OrderFile();

	// ����ԤԼ��¼
	void updateOrder();

	map<int, map<string, string>> m_orderDate;

	// ��¼����
	int m_size;
};