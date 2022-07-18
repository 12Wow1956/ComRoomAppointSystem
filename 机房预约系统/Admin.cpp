#include "Admin.h"

Admin::Admin() {
	
}

Admin::Admin(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ʼ������ ��ȡ�������ļ���
	this->initInfo();

	// ��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom croom;
	while (ifs >> croom.m_ComId && ifs >> croom.m_MaxNum) {
		vCom.push_back(croom);
	}

	ifs.close();
	cout << "���л���" << vCom.size() << endl;
}

void Admin::showSubMenu() {
	cout << "Hi, ����Ա���棡" << endl;
	cout << "\t\t ------------------------------- " << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         1������˺�           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         2���鿴�˺�           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         3���鿴����           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         4�����ԤԼ           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         0��ע����¼           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t ------------------------------- " << endl;
}

// ����˺�
void Admin::addAccount() {
	cout << "����Ϊ˭����˺ţ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;
	int sel = 0;
	cout << "��ѡ��";
	cin >> sel;

	if (sel == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������� ���������룺";
	}
	else if (sel == 2) {
		fileName = TEACHER_FILE;
		tip = "������ְ����: ";
		errorTip = "ְ�����ظ������� ���������룺";
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
	cout << "�û�����" << endl;
	cin >> name;
	cout << "���룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	ofs.close();
	this->initInfo();

	system("pause");
	system("cls");	
}

// �鿴�˺�
void Admin::showAccount() {
	// �ȳ�ʼ�������ļ������ݶ���������
	this->initInfo();

	int sel = 0;
	cout << "������鿴˭���˺ţ�" << endl;
	while (true) {		
		cout << "1��ѧ��" << endl;
		cout << "2����ʦ" << endl;
		cout << "��ѡ��";
		cin >> sel;

		if (sel == 1 || sel == 2) {
			break;
		}
		else {
			cout << "�����䣺" << endl;
		}
	}

	// ��������
	if (sel == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); ++it) {
			cout << "ѧ�ţ� " << it->m_StuId << "\t������ " << it->m_Name << "\t���룺 " << it->m_Pwd << endl;
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); ++it) {
			cout << "ѧ�ţ� " << it->m_EmpId << "\t������ " << it->m_Name << "\t���룺 " << it->m_Pwd << endl;
		}
	}
	system("pause");
	system("cls");
}

// �鿴����
void Admin::showComputerRoom() {
	// ������������
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); ++it) {
		cout << "������ţ� " << it->m_ComId << "\t������������� " << it->m_MaxNum << endl;
	}

	system("pause");
	system("cls");
}

// ���ԤԼ
void Admin::clearOrder() {

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);

	cout << "��ճɹ���" << endl;
	ofs.close();

	system("pause");
	system("cls");
}

// ��ʼ������: ������ʦ��ѧ������Ϣ
void Admin::initInfo() {
	vStu.clear();
	vTea.clear();

	ifstream ifs;	

	// ����ѧ����Ϣ
	ifs.open(STUDENT_FILE, ios::in); // ������in
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_StuId && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);		
	}
	ifs.close();
	// cout << "Ŀǰ��ѧ��" << vStu.size() << "��" << endl;

    // ������ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	ifs.close();
	// cout << "Ŀǰ����ʦ" << vTea.size() << "��" << endl;
}



// ȥ��
bool Admin::checkRepeat(string id, int type) {
	if (type == 1) { // ѧ��
		// ����vStu����������п��Ƿ����ظ���
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