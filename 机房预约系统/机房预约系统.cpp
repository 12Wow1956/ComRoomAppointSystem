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
		cout << "��ѡ�� ";
		cin >> sel;

		if (sel == 1) {
			// ����ԤԼ
			stu->applyOrder();
		}
		else if (sel == 2) {
			// �鿴ԤԼ
			stu->showMyOrder();
		}
		else if (sel == 3) {
			// �鿴����ԤԼ
			stu->showAllOrder();
		}
		else if (sel == 4) {
			// ȡ��ԤԼ
			stu->cancelOrder();
		}
		else {
			// ע����¼
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// ����Ա����
void AdminMenu(Identity* &admin) {	

	while (true) {
		int sel = 0;
		admin->showSubMenu();

		// �����游���ָ�룬��ǿת������ָ��
		Admin* adm = (Admin*)admin; // ʹ�ô˴���ָ����Ե������Լ�������ӿ�

		cout << "��ѡ��";
		cin >> sel;

		switch (sel)
		{
		case 1:
			adm->addAccount();
			//cout << "����˺���" << endl;
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
			// ע����¼
			delete admin; // ����ǰ��Ӧ��ע������������
			cout << "ע���ɹ��� " << endl;   // �˴�ע����¼�������˳�whileѭ������������Ӻ����ĵ���
			system("pause");
			system("cls");
			return;
		default: 
			break;
		}
	}
}




// ��¼����
void loginIn(string fileName, int type) {
	// ����һ������ָ��
	Identity* person = NULL;


	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}

	string id; // ��ţ�ѧ�š�ְ����
	string name; // �û���
	string pwd; // ����

	// �������û�����������Щȷ����˭Ҫ��¼
	if (type == 1) {
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "����������û�����" << endl;
	cin >> name;
	cout << "������������룺" << endl;
	cin >> pwd;


	// ȷ���Ժ�Ϊ��������
	if (type == 1) {
		// ѧ����¼��֤
		string fid, fname, fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			/*---------------------------��ֱ��д���·��Ĵ���֮��ȴʼ����֤��½ʧ�ܵ�����¡��������֤��һ�£��Ͳ�֪������������ﲻ֪����θ�-------------------------------
			cout << fid << endl;
			cout << fname << endl;
			cout << fpwd << endl;
			cout << endl;*/

			// �����أ���������ٽ��д˴�����һ��
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "��¼��֤�ɹ���" << endl;
				person = new Student(id, name, pwd);
				system("pause");
				system("cls");
				StudentMenu(person);
				return;
			}
		}		
	}
	else if (type == 2) {
		// ��ʦ��¼��֤

		string fid, fname, fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "��¼��֤�ɹ���" << endl;
				person = new Teacher(id, name, pwd);
				system("pause");
				system("cls");
				person->showSubMenu();
			}
		}

		/**/
	}
	else if (type == 3) {
		// ����Ա��¼��֤

		string fname, fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (fname == name && fpwd == pwd) {
				//cout << fname << " " << fpwd << endl;
				cout << "��¼��֤�ɹ���" << endl;
				person = new Admin(name, pwd);
				system("pause");
				system("cls");
				AdminMenu(person);
			}
		}

		/*�Լ�д��СС���룺��������Ҫ��½��ʱ����Ҫ���˺ŵΣ����������ͨ�����±����������֤�����Ի�Ҫ��������֤���
		person = new Admin(name, pwd);
		system("cls");
		person->showSubMenu();*/
	} else {
		cout << "��֤��¼ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
	}

	
}

int main() {

	int sel = 0;
	while (true) {

		cout << "--------------------------��ӭ�����˳�ѧԺ����ԤԼϵͳ----------------------" << endl;
		cout << endl << "�������������" << endl;

		cout << "\t\t ------------------------------- " << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t|         1��ѧ������           |" << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t|         2����ʦ               |" << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t|         3������Ա             |" << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t|         0���˳�ϵͳ           |" << endl;
		cout << "\t\t|                               |" << endl;
		cout << "\t\t ------------------------------- " << endl;

		cout << "�����룺";
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
			cout << "��ӭ�´�ʹ�á��ټ���" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}	

	system("pause");
	return 0;
}