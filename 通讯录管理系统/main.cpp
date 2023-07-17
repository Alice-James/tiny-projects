#include <iostream>
#include "Contact.h"
#include "show_menu.h"
#include "add_contact.h"
#include "print_contact.h"
#include "find_contact.h"
#include "delete_contact.h"
#include "modify_contact.h"

using namespace std;


int main() {
    int instruction = 0;
    bool leave = false;
    Contact contact;
    contact.sum = 0;

    while (leave == false) {
        show_menu();
        cin >> instruction;
        switch (instruction) {
        case 0: {
            cout << "欢迎下次使用！" << endl;
            leave = true;
            break;
        }

        case 1: {
            add_contact(&contact);
            break;
        }

        case 2: {
            print_contact_all(&contact);
            break;
        }

        case 3: {
            delete_contact_single(&contact);
            break;
        }

        case 4: {
            find_and_print(&contact);
            break;
        }

        case 5: {
            modify_contact(&contact);
            break;
        }

        case 6: {
            delete_contact_all(&contact);
            break;
        }
        }
    }

    return 0;
}