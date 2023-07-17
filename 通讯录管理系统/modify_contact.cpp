#include "modify_contact.h"


void modify_contact(Contact* contact) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int index = just_find(contact, name);
	if (index == -1)
		cout << "查无此人" << endl;
	else {
		cout << "请输入姓名：" << endl;
		cin >> contact->contacters[index].name;

		cout << "请输入性别：\n1 -- 男\n2 -- 女" << endl;
		int temp;
		while (true) {
			cin >> temp;
			if (temp == 1 || temp == 2) {
				contact->contacters[index].gender = temp;
				break;
			}
			else
				cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入年龄：" << endl;
		cin >> contact->contacters[index].age;

		cout << "请输入联系电话：" << endl;
		cin >> contact->contacters[index].tel;

		cout << "请输入家庭住址：" << endl;
		cin >> contact->contacters[index].addr;

		cout << "添加成功！" << endl;
	}

	system("pause");
	system("cls");
}