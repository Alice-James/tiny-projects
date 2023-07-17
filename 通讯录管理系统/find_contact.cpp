#include "find_contact.h"

int just_find(const Contact* contact, string name) {
	for (int i = 0; i < contact->sum; i++) {
		if (contact->contacters[i].name == name)
			return i;
	}
	return -1;
}

void find_and_print(const Contact* contact) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int result = just_find(contact, name);
	if (result == -1)
		cout << "查无此人" << endl;
	else
		print_contact_single(&(contact->contacters[result]));

	system("pause");
	system("cls");
}