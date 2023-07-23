#pragma once
#include "Worker.h"


class Employee : public Worker
{
public:

	Employee();
	Employee(int ID, string name, int job);

	~Employee();

	void show_information();
};