#ifndef CONTACT_H
#define CONTACT_H

#include <string>

#define MAX 1000

using namespace std;


struct Contacter {
    string name;
    int gender;
    int age;
    string tel;
    string addr;
};

struct Contact {
    int sum;
    Contacter contacters[MAX];
};

#endif  // CONTACT_H