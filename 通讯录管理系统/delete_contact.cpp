#include "delete_contact.h"
#include "find_contact.h"

bool basic_delete(Contact* contact, string name) {
	int index = just_find(contact, name);
	if (index == -1)
		return 0;
	else {
		for (int i = index; i <= contact->sum - 2; i++)
			contact->contacters[i] = contact->contacters[i + 1];

		contact->sum--;
		return 1;
	}
}

void delete_contact_single(Contact* contact) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	cout << ((basic_delete(contact, name)) ? "ɾ���ɹ�" : "���޴���") << endl;

	system("pause");
	system("cls");
}

void delete_contact_all(Contact* contact) {
	contact->sum = 0;

	system("pause");
	system("cls");
}