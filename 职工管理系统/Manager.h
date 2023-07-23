#pragma once
#include "Worker.h"


class Manager : public Worker
{
public:

	Manager();
	Manager(int ID, string name, int job);

	~Manager();

	void show_information();
};