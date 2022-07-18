#include "Admin.h"

Admin::Admin() {
	
}

Admin::Admin(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	// 初始化容器 获取到所有文件中
	this->initInfo();

	// 初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom croom;
	while (ifs >> croom.m_ComId && ifs >> croom.m_MaxNum) {
		vCom.push_back(croom);
	}

	ifs.close();
	cout << "共有机房" << vCom.size() << endl;
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
	string errorTip;
	int sel = 0;
	cout << "请选择：";
	cin >> sel;

	if (sel == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复！！！ 请重新输入：";
	}
	else if (sel == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入职工号: ";
		errorTip = "职工号重复！！！ 请重新输入：";
	}

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	string id, name, pwd;

	while (true) {		
		cout << tip << endl;
		cin >> id;		

		if (sel == 1) {
			bool ret = this->checkRepeat(id, 1);
			if (ret) {
				cout << errorTip << endl;
			}
			else {				
				break;
			}
		}
		else if (sel == 2) {
			bool ret = this->checkRepeat(id, 2);
			if (ret) {
				cout << errorTip << endl;
			}
			else {				
				break;
			}
		}

	}	
	cout << "用户名：" << endl;
	cin >> name;
	cout << "密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	ofs.close();
	this->initInfo();

	system("pause");
	system("cls");	
}

// 查看账号
void Admin::showAccount() {
	// 先初始化：将文件中内容读入容器中
	this->initInfo();

	int sel = 0;
	cout << "请问想查看谁的账号？" << endl;
	while (true) {		
		cout << "1、学生" << endl;
		cout << "2、老师" << endl;
		cout << "请选择：";
		cin >> sel;

		if (sel == 1 || sel == 2) {
			break;
		}
		else {
			cout << "请重输：" << endl;
		}
	}

	// 遍历容器
	if (sel == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); ++it) {
			cout << "学号： " << it->m_StuId << "\t姓名： " << it->m_Name << "\t密码： " << it->m_Pwd << endl;
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); ++it) {
			cout << "学号： " << it->m_EmpId << "\t姓名： " << it->m_Name << "\t密码： " << it->m_Pwd << endl;
		}
	}
	system("pause");
	system("cls");
}

// 查看机房
void Admin::showComputerRoom() {
	// 遍历机房容器
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); ++it) {
		cout << "机房编号： " << it->m_ComId << "\t机房最大容量： " << it->m_MaxNum << endl;
	}

	system("pause");
	system("cls");
}

// 清空预约
void Admin::clearOrder() {

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);

	cout << "清空成功！" << endl;
	ofs.close();

	system("pause");
	system("cls");
}

// 初始化容器: 读入老师、学生的信息
void Admin::initInfo() {
	vStu.clear();
	vTea.clear();

	ifstream ifs;	

	// 读入学生信息
	ifs.open(STUDENT_FILE, ios::in); // 读入用in
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_StuId && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);		
	}
	ifs.close();
	// cout << "目前有学生" << vStu.size() << "名" << endl;

    // 读入老师信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	ifs.close();
	// cout << "目前有老师" << vTea.size() << "名" << endl;
}



// 去重
bool Admin::checkRepeat(string id, int type) {
	if (type == 1) { // 学生
		// 遍历vStu容器里的所有看是否有重复啦
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); ++it) {
			if (it->m_StuId == id) {
				return true;
			}
		}
		return false;
	}
	else if (type == 2) {
		for (auto it = vTea.begin(); it != vTea.end(); ++it) {
			if (it->m_EmpId == id) {
				return true;
			}
		}
		return false;
	}
}