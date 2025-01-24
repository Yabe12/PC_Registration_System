#include <iostream>
#include "../services/auth_service.h"
#include "./sub_menus/super_admin_menu/super_admin_menu.h"
#include "./sub_menus/admin_menu/admin_menu.h"
// #include "../utils/menu_utils/menu_utils.h"  // No longer needed if removing header/footer

using namespace std;

void mainMenu() {
    char roleChoice;

    while (true) {
        cout << "************************************" << endl;
        cout << "  Main Menu" << endl;
        cout << "************************************" << endl;
        cout << "Choose your role:\n";
        cout << "A. I am SuperAdmin\n";
        cout << "B. I am Admin\n";
        cout << "C. Exit\n";
        cout << "************************************" << endl;
        cout << "Enter your choice (A, B, or C): ";
        cin >> roleChoice;

        switch (tolower(roleChoice)) {
            case 'a': // SuperAdmin
                if (login(true)) {
                    super_admin_menu();
                }
                break;

            case 'b': // Admin
                if (login(false)) {
                    admin_menu();
                }
                break;

            case 'c': // Exit
                cout << "\nExiting program. Goodbye!\n";
                return;

            default:
                cout << "\nInvalid choice! Please enter A, B, or C.\n";
        }
    }
}

int main() {
    // Main menu is called when the program starts
    mainMenu();
    return 0;
}

