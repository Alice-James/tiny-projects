#include "Employee.h"


Employee::Employee(int ID, string name, int job)
{
	this->ID = ID;
	this->name = name;
	this->job = job;
}

void Employee::show_information()
{
	cout << "ְ����ţ�" << ID
		<< "\tְ��������" << name
		<< "\t\t��λ��Ա��\t��λְ����ɾ�����������";
}