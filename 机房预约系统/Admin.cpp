#include "Admin.h"

Admin::Admin() {
	
}

Admin::Admin(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
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
	int sel = 0;
	cout << "��ѡ��";
	cin >> sel;

	if (sel == 1) {
		fileName = "STUDENT_FILE";
		tip = "������ѧ�ţ�";
	}
	else if (sel == 2) {
		fileName = "TEACHER_FILE";
		tip = "������ְ����: ";
	}

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);

	string id, name, pwd;
	cout << tip << endl;
	cin >> id;
	cout << "�û�����" << endl;
	cin >> name;
	cout << "���룺" << endl;
	cin >> pwd;

	// cout << id << " " << name << " " << pwd << endl;

	if (ofs.is_open()) {
		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "��ӳɹ���������" << endl;
	}
	else {
		cout << "�ļ������ڣ�" << endl;
	}
	system("pause");
	system("cls");
	ofs.close();
}

// �鿴�˺�
void Admin::showAccount() {

}

// �鿴����
void Admin::showComputerRoom() {

}

// ���ԤԼ
void Admin::clearOrder() {

}