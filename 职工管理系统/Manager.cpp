#include "Manager.h"


Manager::Manager(int ID, string name, int job)
{
	this->ID = ID;
	this->name = name;
	this->job = job;
}

void Manager::show_information()
{
	cout << "ְ����ţ�" << ID
		<< "\tְ��������" << name
		<< "\t\t��λ������\t��λְ������ϰ彻�������񣬲��·������Ա��";
}