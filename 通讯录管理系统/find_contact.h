#include "Contact.h"
#include "print_contact.h"


/* 
如果没找到，返回-1；
如果找到了，返回序号；
*/
int just_find(const Contact* contact, string name);

/*
如果没找到，打印"查无此人";
如果找到了，单个打印；
*/
void find_and_print(const Contact* contact);