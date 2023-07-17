#include "add_contact.h"


void add_contact(Contact* contact) {
	if (contact->sum == MAX)
		cout << "通讯录已满（" << MAX << "人），无法添加！" << endl;
	else {
		int index = contact->sum;
		int temp;

		cout << "请输入姓名：" << endl;
		cin >> contact->contacters[index].name;

		cout << "请输入性别：\n1 -- 男\n2 -- 女" << endl;
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

		contact->sum++;
		cout << "添加成功！" << endl;
	}

	system("pause");
	system("cls");
}