#include "Boss.h"


Boss::Boss(int ID, string name, int job)
{
	this->ID = ID;
	this->name = name;
	this->job = job;
}

void Boss::show_information()
{
	cout << "职工编号：" << ID
		<< "\t职工姓名：" << name
		<< "\t\t岗位：总裁\t岗位职责：管理公司所有事务";
}