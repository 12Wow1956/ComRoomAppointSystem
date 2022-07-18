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

	// ����˺�
	void addAccount();

	// �鿴�˺�
	void showAccount();

	// �鿴����
	void showComputerRoom();

	// ���ԤԼ
	void clearOrder();

	// ��ʼ������: ������ʦ��ѧ������Ϣ
	void initInfo();

	// ѧ������
	vector<Student> vStu;

	// ��ʦ����
	vector<Teacher> vTea;
	
	// ȥ��
	bool checkRepeat(string id, int type);

	// ������Ϣ
	vector<ComputerRoom> vCom;
};