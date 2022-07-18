#include <iostream>
#include <string>
#include <fstream>
#include "globalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
using namespace std;

void StudentMenu(Identity* &student) {

	while (true) {
		int sel = 0;
		student->showSubMenu();
		Student* stu = (Student*)student;
		cout << "请选择： ";
		cin >> sel;

		if (sel == 1) {
			// 申请预约
			stu->applyOrder();
		}
		else if (sel == 2) {
			// 查看预约
			stu->showMyOrder();
		}
		else if (sel == 3) {
			// 查看所有预约
			stu->showAllOrder();
		}
		else if (sel == 4) {
			// 取消预约
			stu->cancelOrder();
		}
		else {
			// 注销登录
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// 管理员界面
void AdminMenu(Identity* &admin) {	

	while (true) {
		int sel = 0;
		admin->showSubMenu();

		// 把上面父类的指针，再强转成子类指针
		Admin* adm = (Admin*)admin; // 使得此处的指针可以调用它自己的子类接口

		cout << "请选择：";
		cin >> sel;

		switch (sel)
		{
		case 1:
			adm->addAccount();
			//cout << "添加账号啦" << endl;
			break;
		case 2:
			adm->showAccount();
			break;
		case 3:
			adm->showComputerRoom();
			break;
		case 4:
			adm->clearOrder();
			break;
		case 0:
			// 注销登录
			delete admin; // 走以前先应该注销掉堆区数据
			cout << "注销成功！ " << endl;   // 此处注销登录，即，退出while循环，返回这个子函数的调用
			system("pause");
			system("cls");
			return;
		default: 
			break;
		}
	}
}




// 登录功能
void loginIn(string fileName, int type) {
	// 创建一个父类指针
	Identity* person = NULL;


	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}

	string id; // 编号：学号、职工号
	string name; // 用户名
	string pwd; // 密码

	// 先输入用户名、密码那些确定是谁要登录
	if (type == 1) {
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入你的用户名：" << endl;
	cin >> name;
	cout << "请输入你的密码：" << endl;
	cin >> pwd;


	// 确定以后为它创建类
	if (type == 1) {
		// 学生登录验证
		string fid, fname, fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			/*---------------------------在直接写完下方的代码之后却始终验证登陆失败的情况下。如果不验证这一下，就不知道问题出在哪里不知道如何改-------------------------------
			cout << fid << endl;
			cout << fname << endl;
			cout << fpwd << endl;
			cout << endl;*/

			// 所以呢？先输出，再进行此处的下一步
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "登录验证成功！" << endl;
				person = new Student(id, name, pwd);
				system("pause");
				system("cls");
				StudentMenu(person);
				return;
			}
		}		
	}
	else if (type == 2) {
		// 老师登录验证

		string fid, fname, fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "登录验证成功！" << endl;
				person = new Teacher(id, name, pwd);
				system("pause");
				system("cls");
				person->showSubMenu();
			}
		}

		/**/
	}
	else if (type == 3) {
		// 管理员登录验证

		string fname, fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (fname == name && fpwd == pwd) {
				//cout << fname << " " << fpwd << endl;
				cout << "登录验证成功！" << endl;
				person = new Admin(name, pwd);
				system("pause");
				system("cls");
				AdminMenu(person);
			}
		}

		/*自己写的小小代码：后来发现要登陆的时候是要有账号滴：而这个过程通过记事本里的内容验证。所以还要让他们验证相等
		person = new Admin(name, pwd);
		system("cls");
		person->showSubMenu();*/
	} else {
		cout << "验证登录失败！" << endl;
		system("pause");
		system("cls");
	}

	
}

int main() {

	int sel = 0;
	while (true) {

		cout << "--------------------------欢迎来到运城学院机房预约系统----------------------" << endl;
		cout << endl << "请输入您的身份" << endl;

		cout << "\t\t ------------------------------- " << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t|         1、学生代表           |" << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t|         2、老师               |" << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t|         3、管理员             |" << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t|         0、退出系统           |" << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t ------------------------------- " << endl;

		cout << "请输入：";
		cin >> sel;
		switch (sel)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn("TEACHER_FILE", 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用。再见！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}	

	system("pause");
	return 0;
}