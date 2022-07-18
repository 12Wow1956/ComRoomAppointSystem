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

	// 更新预约记录
	void updateOrder();

	map<int, map<string, string>> m_orderDate;

	// 记录条数
	int m_size;
};