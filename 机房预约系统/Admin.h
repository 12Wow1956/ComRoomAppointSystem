#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"
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

	// 初始化容器: 读入老师、学生的信息
	void initInfo();

	// 学生容器
	vector<Student> vStu;

	// 老师容器
	vector<Teacher> vTea;
	
	// 去重
	bool checkRepeat(string id, int type);

	// 机房信息
	vector<ComputerRoom> vCom;
};