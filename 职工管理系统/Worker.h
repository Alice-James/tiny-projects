#pragma once
#include <iostream>
using namespace std;
#include <string>


class Worker
{
	friend ostream& operator<<(ostream& os, Worker& worker);


public:

	virtual void show_information() = 0;// 显示职工信息


	int ID;// 职工编号
	string name;// 姓名
	int job;// 岗位
};