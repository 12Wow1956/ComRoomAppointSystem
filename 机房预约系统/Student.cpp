#include "Student.h"

Student::Student() {

}

Student::Student(string id, string name, string pwd) {
	this->m_StuId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// 先把文件中的机房信息，读入程序,放到机房的容器中
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom cr;
	while (ifs >> cr.m_ComId && ifs >> cr.m_MaxNum) {
		vCom.push_back(cr);
	}
	ifs.close();
	/*for (auto it = vCom.begin(); it != vCom.end(); ++it) {
		cout << it[0].m_ComId << it[0].m_MaxNum << endl;
	}*/
}

// 子菜单
void Student::showSubMenu() {
	cout << "Hi, 学生代表界面！" << endl;
	cout << "\t\t ------------------------------- " << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         1、申请预约           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         2、查看我的预约       |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         3、查看所有预约       |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         4、取消预约           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         0、注销登录           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t ------------------------------- " << endl;
}

// 申请预约
void Student::applyOrder() {
	int date = 0;  // 日期
	int interval = 0; // 时间段
	int room = 0;  // 机房

	while (true) {
		cout << "机房开放时间为周一至周五！" << endl;
		cout << "请输入申请预约的时间：" << endl;
		cout << "1、周一" << endl;
		cout << "2、周二" << endl;
		cout << "3、周三" << endl;
		cout << "4、周四" << endl;
		cout << "5、周五" << endl;
		cin >> date;

		if (date < 1 || date > 5) {
			cout << "输入有误，请重新输入！" << endl;
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "请输入预约时间段：" << endl;
		cout << "1、上午" << endl;
		cout << "2、下午" << endl; 
		cin >> interval;

		if (interval == 1 || interval == 2) {
			break;
		}
		else {
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	while (true) {
		cout << "请输入要预约的机房类型：" << endl;
		cout << "1号机房：" << vCom[0].m_MaxNum << endl;
		cout << "2号机房：" << vCom[1].m_MaxNum << endl;
		cout << "3号机房：" << vCom[2].m_MaxNum << endl;
		cin >> room;

		if (room == 1 || room == 2 || room == 3) {
			break;
		}
		else {
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	// 文件
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);  // 追加方式写入
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "room:" << room << " "
		<< "StuId:" << this->m_StuId << " "
		<< "StuName:" << this->m_Name << " "
		<< "status:" << 1 << endl;
	cout << "预约成功，审核中！" << endl;

	system("pause");
	system("cls");
}

// 查看我的预约
void Student::showMyOrder() {
	OrderFile of;
}

// 查看所有预约
void Student::showAllOrder() {

}

// 取消预约
void Student::cancelOrder() {

}

Student::~Student() {

}
