// --- menus/sub_menus/admin_menu.cpp ---
#include <iostream>
#include "../user_menu/user_menu.h"
#include "super_admin_menu.h"
#include "../admin_menu/admin_menu.h"
using namespace std;

void super_admin_menu() {
    int choice;
    while (true) {
        cout << "\nSuper Admin Menu:\n";
        cout << "1. Work on admin\n";
        cout << "2. Work on user\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Call the admin menu function here if it exists
                admin_menu();
                break;
            case 2:
                user_menu();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}