#include "Boss.h"


Boss::Boss(int ID, string name, int job)
{
	this->ID = ID;
	this->name = name;
	this->job = job;
}

void Boss::show_information()
{
	cout << "ְ����ţ�" << ID
		<< "\tְ��������" << name
		<< "\t\t��λ���ܲ�\t��λְ�𣺹���˾��������";
}