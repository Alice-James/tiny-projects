#pragma once
#include <iostream>
using namespace std;
#include <string>


class Worker
{
	friend ostream& operator<<(ostream& os, Worker& worker);


public:

	virtual void show_information() = 0;// ��ʾְ����Ϣ


	int ID;// ְ�����
	string name;// ����
	int job;// ��λ
};