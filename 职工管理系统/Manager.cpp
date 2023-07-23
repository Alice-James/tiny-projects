#include "Manager.h"


Manager::Manager(int ID, string name, int job)
{
	this->ID = ID;
	this->name = name;
	this->job = job;
}

void Manager::show_information()
{
	cout << "职工编号：" << ID
		<< "\t职工姓名：" << name
		<< "\t\t岗位：经理\t岗位职责：完成老板交给的任务，并下发任务给员工";
}