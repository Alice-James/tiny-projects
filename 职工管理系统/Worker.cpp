#include "Worker.h"


ostream& operator<<(ostream& os, Worker& worker)
{
	worker.show_information();
	return os;
}