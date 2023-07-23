#include "Employee.h"


Employee::Employee(int ID, string name, int job)
{
	this->ID = ID;
	this->name = name;
	this->job = job;
}

void Employee::show_information()
{
	cout << "职工编号：" << ID
		<< "\t职工姓名：" << name
		<< "\t\t岗位：员工\t岗位职责：完成经理交给的任务";
}