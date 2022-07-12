#include "Admin.h"

Admin::Admin() {
	
}

Admin::Admin(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Admin::showSubMenu() {
	cout << "Hi, 管理员界面！" << endl;
	cout << "\t\t ------------------------------- " << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         1、添加账号           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         2、查看账号           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         3、查看机房           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         4、清空预约           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         0、注销登录           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t ------------------------------- " << endl;
}

// 添加账号
void Admin::addAccount() {
	cout << "请问为谁添加账号？" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	int sel = 0;
	cout << "请选择：";
	cin >> sel;

	if (sel == 1) {
		fileName = "STUDENT_FILE";
		tip = "请输入学号：";
	}
	else if (sel == 2) {
		fileName = "TEACHER_FILE";
		tip = "请输入职工号: ";
	}

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);

	string id, name, pwd;
	cout << tip << endl;
	cin >> id;
	cout << "用户名：" << endl;
	cin >> name;
	cout << "密码：" << endl;
	cin >> pwd;

	// cout << id << " " << name << " " << pwd << endl;

	if (ofs.is_open()) {
		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "添加成功功功功！" << endl;
	}
	else {
		cout << "文件不存在！" << endl;
	}
	system("pause");
	system("cls");
	ofs.close();
}

// 查看账号
void Admin::showAccount() {

}

// 查看机房
void Admin::showComputerRoom() {

}

// 清空预约
void Admin::clearOrder() {

}