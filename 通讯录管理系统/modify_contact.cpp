#include "modify_contact.h"


void modify_contact(Contact* contact) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int index = just_find(contact, name);
	if (index == -1)
		cout << "���޴���" << endl;
	else {
		cout << "������������" << endl;
		cin >> contact->contacters[index].name;

		cout << "�������Ա�\n1 -- ��\n2 -- Ů" << endl;
		int temp;
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

		cout << "��ӳɹ���" << endl;
	}

	system("pause");
	system("cls");
}