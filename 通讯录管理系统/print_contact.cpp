#include "print_contact.h"


void print_contact_single(const Contacter* contacter) {
	cout << "������" << contacter->name << "\t�Ա�" << ((contacter->gender == 1) ? "��" : "Ů") << "\t���䣺" << contacter->age << "\t�绰��" << contacter->tel << "\tסַ��" << contacter->addr << endl;
}

void print_contact_all(const Contact* contact) {
	if (contact->sum == 0)
		cout << "��ǰ��¼Ϊ��" << endl;
	else
		for (int i = 0; i < contact->sum; i++)
			print_contact_single(&(contact->contacters[i]));

	system("pause");
	system("cls");
}