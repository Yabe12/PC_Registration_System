#ifndef DELETE_MENU_H
#define DELETE_MENU_H

#include <iostream>
#include "../services/AdminService.h"
#include "../services/StudentService.h"
#include "../services/NonstaffService.h"
#include "../services/StaffService.h"
#include "AdminMenu.h"
#include <cstring>
using namespace std;

// Function to delete users based on type
void Delete() {
    int choice;
    while (true) {
        cout << "Choose a type of user to delete:" << endl;
        cout << "1. student" << endl;
        cout << "2. staff" << endl;
        cout << "3. nonstaff" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        if (choice == 1) {
            delete_student();
            break;
        } else if (choice == 2) {
            delete_staff();
            break;
        } else if (choice == 3) {
            delete_nonstaff();
            break;
        } else if (choice == 4) {
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
  
}

#endif // SUPER_ADMIN_MENU_H