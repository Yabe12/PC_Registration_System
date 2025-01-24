// --- menus/main_menu.cpp ---
#include <iostream>
#include "../services/auth_service.h"
#include "./sub_menus/super_admin_menu/super_admin_menu.h"
#include "./sub_menus/admin_menu/admin_vsocmenu.h"

using namespace std;

void mainMenu() {
    char roleChoice;
    cout << "Choose your role:\nA. I am SuperAdmin\nB. I am Admin\n";
    cin >> roleChoice;

    if (roleChoice == 'A' || roleChoice == 'a') {
        if (login(true)) {
            super_admin_menu();
        }
    } else if (roleChoice == 'B' || roleChoice == 'b') {
        if (login(false)) {
            admin_menu();
        }
    } else {
        cout << "Invalid choice!\n";
    }
}
