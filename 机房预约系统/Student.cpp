#include "Student.h"

Student::Student() {

}

Student::Student(string id, string name, string pwd) {

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
	cout << "\t\t ------------------------------- " << endl;
}

// 申请预约
void Student::applyOrder() {

}

// 查看我的预约
void Student::showMyOrder() {

}

// 查看所有预约
void Student::showAllOrder() {

}

// 取消预约
void Student::cancelOrder() {

}

Student::~Student() {

}
