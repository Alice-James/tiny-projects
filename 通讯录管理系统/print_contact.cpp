#include "print_contact.h"


void print_contact_single(const Contacter* contacter) {
	cout << "姓名：" << contacter->name << "\t性别：" << ((contacter->gender == 1) ? "男" : "女") << "\t年龄：" << contacter->age << "\t电话：" << contacter->tel << "\t住址：" << contacter->addr << endl;
}

void print_contact_all(const Contact* contact) {
	if (contact->sum == 0)
		cout << "当前记录为空" << endl;
	else
		for (int i = 0; i < contact->sum; i++)
			print_contact_single(&(contact->contacters[i]));

	system("pause");
	system("cls");
}