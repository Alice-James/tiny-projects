#include "add_contact.h"


void add_contact(Contact* contact) {
	if (contact->sum == MAX)
		cout << "ͨѶ¼������" << MAX << "�ˣ����޷���ӣ�" << endl;
	else {
		int index = contact->sum;
		int temp;

		cout << "������������" << endl;
		cin >> contact->contacters[index].name;

		cout << "�������Ա�\n1 -- ��\n2 -- Ů" << endl;
		while (true) {
			cin >> temp;
			if (temp == 1 || temp == 2) {
				contact->contacters[index].gender = temp;
				break;
			}
			else
				cout << "������������������" << endl;
		}

		cout << "���������䣺" << endl;
		cin >> contact->contacters[index].age;

		cout << "��������ϵ�绰��" << endl;
		cin >> contact->contacters[index].tel;

		cout << "�������ͥסַ��" << endl;
		cin >> contact->contacters[index].addr;

		contact->sum++;
		cout << "��ӳɹ���" << endl;
	}

	system("pause");
	system("cls");
}