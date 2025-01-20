#ifndef SUPER_ADMIN_MENU_H
#define SUPER_ADMIN_MENU_H

#include <iostream>
#include "../services/AdminService.h"
#include "../services/StudentService.h"
#include "AdminMenu.h"
#include <cstring>
using namespace std;
void menu_superadmin() {
    int choice;
    while (true) {
        cout << "\nSuperAdmin Menu:\n";
        cout << "1. Work on User\n";
        cout << "2. Work on Admin\n";
        cout << "3. Back\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: menu_work_on_users(); break;
            case 2: menu_work_on_admins(); break;
            case 3: return; // Return to main menu
            case 4: exit(0);
            default: cout << "Invalid choice, try again.\n";
        }
    }
}
void menu_work_on_users() {
    int choice;
    while (true) {
        cout << "\nWork on Users:\n";
        cout << "1. Add User\n";
        cout << "2. Update User\n";
        cout << "3. Delete User\n";
        cout << "4. Search and Display\n";
        cout << "5. Display All\n";
        cout << "6. Back\n";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Adding user...\n"; add_user(); break; 
            case 2: cout << "Update user...\n"; Update(); break;
            case 3: cout << "Delete user...\n"; Delete(); break;
            case 4:  cout << "search user...\n";search(); break;
            case 5: cout << "display user...\n"; display(); break;
            case 6:
            return;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

void menu_work_on_admins() {
    int choice;
    while (true) {
        cout << "\nWork on Admins:\n";
        cout << "1. Create Admin\n";
        cout << "2. Update Admin\n";
        cout << "3. Delete Admin\n";
        cout << "4. Search and Display\n";
        cout << "5. Display All Admins\n";
        cout << "6. Back\n";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Creating admin...\n";add_admin(); break;
            case 2: cout << "Updating admin...\n";update_admin(); break;
            case 3: cout << "Deleting admin...\n";delete_admin(); break;
            case 4: cout << "Searching admin...\n";search_admin(); break;
            case 5: cout << "Displaying all admins...\n";display_admin(); break;
            case 6: 
            return;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}


#endif 
