#pragma once
#include "Worker.h"


class Boss : public Worker
{
public:

	Boss();
	Boss(int ID, string name, int job);

	~Boss();

	void show_information();
};