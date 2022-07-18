#include "Student.h"

Student::Student() {

}

Student::Student(string id, string name, string pwd) {
	this->m_StuId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// �Ȱ��ļ��еĻ�����Ϣ���������,�ŵ�������������
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

// �Ӳ˵�
void Student::showSubMenu() {
	cout << "Hi, ѧ��������棡" << endl;
	cout << "\t\t ------------------------------- " << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         1������ԤԼ           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         2���鿴�ҵ�ԤԼ       |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         3���鿴����ԤԼ       |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         4��ȡ��ԤԼ           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         0��ע����¼           |" << endl;
	cout << "\t\t|                               |" << endl;
	cout << "\t\t ------------------------------- " << endl;
}

// ����ԤԼ
void Student::applyOrder() {
	int date = 0;  // ����
	int interval = 0; // ʱ���
	int room = 0;  // ����

	while (true) {
		cout << "��������ʱ��Ϊ��һ�����壡" << endl;
		cout << "����������ԤԼ��ʱ�䣺" << endl;
		cout << "1����һ" << endl;
		cout << "2���ܶ�" << endl;
		cout << "3������" << endl;
		cout << "4������" << endl;
		cout << "5������" << endl;
		cin >> date;

		if (date < 1 || date > 5) {
			cout << "�����������������룡" << endl;
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "������ԤԼʱ��Σ�" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl; 
		cin >> interval;

		if (interval == 1 || interval == 2) {
			break;
		}
		else {
			cout << "�����������������룡" << endl;
		}
	}

	while (true) {
		cout << "������ҪԤԼ�Ļ������ͣ�" << endl;
		cout << "1�Ż�����" << vCom[0].m_MaxNum << endl;
		cout << "2�Ż�����" << vCom[1].m_MaxNum << endl;
		cout << "3�Ż�����" << vCom[2].m_MaxNum << endl;
		cin >> room;

		if (room == 1 || room == 2 || room == 3) {
			break;
		}
		else {
			cout << "�����������������룡" << endl;
		}
	}

	// �ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);  // ׷�ӷ�ʽд��
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "room:" << room << " "
		<< "StuId:" << this->m_StuId << " "
		<< "StuName:" << this->m_Name << " "
		<< "status:" << 1 << endl;
	cout << "ԤԼ�ɹ�������У�" << endl;

	system("pause");
	system("cls");
}

// �鿴�ҵ�ԤԼ
void Student::showMyOrder() {
	OrderFile of;
}

// �鿴����ԤԼ
void Student::showAllOrder() {

}

// ȡ��ԤԼ
void Student::cancelOrder() {

}

Student::~Student() {

}
