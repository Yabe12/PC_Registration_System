#include <iostream>
#include "../user_menu/user_menu.h"
#include "../admin_menu/admin_menu.h"
// #include "../../../utils/menu_utils/menu_utils.h"  // No longer needed if removing header/footer
#include "super_admin_menu.h"

using namespace std;

void super_admin_menu() {
    int choice;
    while (true) {
        cout << "************************************" << endl;
        cout << "  Super Admin Menu" << endl;
        cout << "************************************" << endl;
        cout << "1. Work on admin\n";
        cout << "2. Work on user\n";
        cout << "3. Exit\n";
        cout << "************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                admin_menu();
                break;
            case 2:
                user_menu();
                break;
            case 3:
                cout << "\nExiting Super Admin Menu.\n";
                break;
            default:
                cout << "\nInvalid choice, try again.\n";
        }
    }
}
